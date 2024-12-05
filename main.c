#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h" 
#include "lwip/apps/http_client.h" //
#include "hardware/adc.h" 
#include "dandan.h"
#include "hardware/i2c.h"

char myBuff[4096];
const uint8_t num_chars_per_disp[]={7,7,7,5};
void arranque(void);
void impre (void);
// Configuración de Wi-Fi y ThingSpeak
#define WIFI_SSID ":PC Puma FESC C4:."
#define WIFI_PASSWORD "Equisde05#"
#define THINGSPEAK_HOST "api.thingspeak.com"
#define THINGSPEAK_PORT 80
#define API_KEY "I9BG5WTCMTIKTIQ1"
#define USERNAME "FBItBSULLQEVNBoLCzo8ERI"
#define CLIENT_ID "FBItBSULLQEVNBoLCzo8ERI"
#define PASSWORD "Sd1khTfpnH1Dc+RhuwaDs39/"
#define URL_TEMPLATE "/update?api_key=%s&field1=%.2f&username=%s&clientId=%s&password=%s"

void result(void *arg, httpc_result_t httpc_result,
            u32_t rx_content_len, u32_t srv_res, err_t err)
{
    printf("\ntransfer complete\n");
    printf("local result=%d\n", httpc_result);
    printf("http result=%d\n", srv_res);
}

err_t headers(httpc_state_t *connection, void *arg,
              struct pbuf *hdr, u16_t hdr_len, u32_t content_len)
{
    printf("\nheaders received\n");
    printf("content length=%d\n", content_len);
    printf("header length %d\n", hdr_len);
    pbuf_copy_partial(hdr, myBuff, hdr->tot_len, 0);
    printf("headers \n");
    printf("%s", myBuff);
    return ERR_OK;
}

err_t body(void *arg, struct altcp_pcb *conn,
           struct pbuf *p, err_t err)
{
    printf("body\n");
    pbuf_copy_partial(p, myBuff, p->tot_len, 0);
    printf("body length %d\n", p->tot_len);
    return ERR_OK;
}

float Temperatura()
{
    static bool adc_initialized = false;
    if (!adc_initialized) {
        adc_init();
        adc_set_temp_sensor_enabled(true);
        adc_select_input(4);
        adc_initialized = true;
    }

    uint16_t raw = adc_read();
    const float conversion = 3.33 / 4094;
    float resultado = raw * conversion;
    return 27 - (resultado - 0.706) / 0.001721;
}

int setup(uint32_t country, const char *ssid,
          const char *pass, uint32_t auth,
          const char *hostname, ip_addr_t *ip,
          ip_addr_t *mask, ip_addr_t *gw)
{
    if (cyw43_arch_init_with_country(country)) {
        return 1;
    }

    cyw43_arch_enable_sta_mode();
    if (hostname != NULL) {
        netif_set_hostname(netif_default, hostname);
    }
    int err;
    char buffer[255];
    int retrycount = 0;
    while (retrycount < 10)
    {
        if ((err = cyw43_arch_wifi_connect_timeout_ms(ssid, pass, auth, 30000))) {
            sprintf(buffer, "Error connecting to WiFi: %d", err);
            printf("%s\n", buffer);
            retrycount++;
            sleep_ms(1000);
            printf("Retrying connection %d/10", retrycount);
        } else {
            break;
        }
    }
    if (err != 0) {
        return 2;
    }

    int flashrate = 1000;
    int status = CYW43_LINK_UP + 1;
    while (status >= 0 && status != CYW43_LINK_UP)
    {
        printf("Retrying connection\n");
        int new_status = cyw43_tcpip_link_status(&cyw43_state, CYW43_ITF_STA);
        if (new_status != status) {
            status = new_status;
            flashrate = flashrate / (status + 1);
            printf("connect status: %d %d\n", status, flashrate);
        }
        
    }
    if (status < 0) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    } else {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        if (ip != NULL) {
            netif_set_ipaddr(netif_default, ip);
        }
        if (mask != NULL) {
            netif_set_netmask(netif_default, mask);
        }
        if (gw != NULL) {
            netif_set_gw(netif_default, gw);
        }
        printf("IP: %s\n", ip4addr_ntoa(netif_ip_addr4(netif_default)));
        printf("Mask: %s\n", ip4addr_ntoa(netif_ip_netmask4(netif_default)));
        printf("Gateway: %s\n", ip4addr_ntoa(netif_ip_gw4(netif_default)));
        printf("Host Name: %s\n", netif_get_hostname(netif_default));
    }
    return status;
}

char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASSWORD;
uint32_t country = CYW43_COUNTRY_NETHERLANDS;
uint32_t auth = CYW43_AUTH_WPA2_MIXED_PSK;
int main()
{
    stdio_init_all();
    arranque();
    for (int i = 0; i < 3; i++) {
        printf("Wake-up USB\n");
        sleep_ms(1000);
    }
    printf("SSID: %s\n", ssid);
    printf("PASS: %s\n", pass);

    if (setup(country, ssid, pass, auth, "MyPicoW", NULL, NULL, NULL) == CYW43_LINK_UP)
    {
        httpc_connection_t settings;
        
        settings.result_fn = result;
        settings.headers_done_fn = headers;

int retry_count = 0;
int max_retries = 3;

while (true) { // envio de datos
    
     impre();

    float temp = Temperatura();
   
    char url[128];
    snprintf(url, sizeof(url), URL_TEMPLATE, API_KEY, temp, USERNAME, CLIENT_ID, PASSWORD);
    
    printf("URL: %s\n", url);  // Verificar la URL generada
    err_t err = httpc_get_file_dns(THINGSPEAK_HOST, THINGSPEAK_PORT, url, &settings, body, NULL, NULL);
   
    if (err == HTTPC_RESULT_ERR_HOSTNAME) {
        printf("Error de resolución DNS (local result=3). Intentando de nuevo...\n");
        sleep_ms(5000);  // Agregar un retraso antes de reintentar
    } else if (err == HTTPC_RESULT_ERR_CONNECT) {
        printf("Error de conexión (local result=5). Intentando de nuevo...\n");
        retry_count++;
        if (retry_count >= max_retries) {
            printf("Máximo número de reintentos alcanzado. Abortando.\n");
            break;
        }
        sleep_ms(5000);
    } else if (err != HTTPC_RESULT_OK) {
        printf("Error HTTP %d. Intentando de nuevo...\n", err);
        retry_count++;
        if (retry_count >= max_retries) {
            printf("Máximo número de reintentos alcanzado. Abortando.\n");
            break;
        }
        sleep_ms(5000);
    } else {
        printf("HTTP status %d \n", err);
        retry_count = 0;  // Reiniciar el contador de reintentos en caso de éxito
    }

    cyw43_arch_poll(); 
    sleep_ms(20000); // ThingSpeak permite 1 actualización cada 15 segundos
     
}
    
    }
}

void arranque(void) {
    i2c_init(i2c1, 400000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);
}


void impre(void) {

    dandan_t disp;
    disp.external_vcc=false;
    dandan_init(&disp, 128,65, 0x3C, i2c1);

    dandan_limp(&disp);
    char buf[250];
   
    float tem = Temperatura();
    dandan_limp(&disp);
    snprintf(buf, sizeof(buf), "Temp: %.2f C", tem);
     sleep_ms(2000);
        dandan_escribe_string(&disp,10,10,1,buf);
        dandan_mostrar(&disp);
            
    if (tem >= 18){

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    }
}