
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "MQTTClient.h"

// Configuración de ThingSpeak
#define ADDRESS     "tcp://mqtt3.thingspeak.com:1883"  // Dirección del broker MQTT de ThingSpeak
#define CLIENTID    "pico-client"                     // ID del cliente MQTT
#define TOPIC       "channels/2759963/publish/I9BG5WTCMTIKTIQ1" 
#define QOS         1                                 // Calidad de servicio
#define PAYLOAD     "field1=25.5&field2=60"           // Datos a enviar (ej: temperatura y humedad)
#define TIMEOUT     10000L                            // Tiempo de espera
int main() {
    stdio_init_all();

    // Inicializa Wi-Fi
    if (cyw43_arch_init()) {
        printf("Error inicializando Wi-Fi\n");
        return -1;
    }
    cyw43_arch_enable_sta_mode();

    printf("Conectando a Wi-Fi...\n");
    if (cyw43_arch_wifi_connect_timeout_ms("INFINITUM12C9_2.4", "7bxmZ5tr6T", CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("Error conectando al Wi-Fi\n");
        return -1;
    }
    printf("Wi-Fi conectado\n");

    // Configuración del cliente MQTT
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);

    conn_opts.username = "ThingSpeakUser";  // Usuario MQTT de ThingSpeak
    conn_opts.password = "I9BG5WTCMTIKTIQ1";  // Reemplaza con tu clave de escritura de ThingSpeak

    // Conecta al broker MQTT de ThingSpeak
    if (MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS) {
        printf("Error conectando al broker MQTT de ThingSpeak\n");
        return -1;
    }
    printf("Conectado al broker MQTT de ThingSpeak\n");

    while (true)
    {
        float temp = Temperatura();
   
        char payload[64];
        snprintf(payload, sizeof(payload), "field1= %2.f", temp)
        MQTTClient_message pubmsg = MQTTClient_message_initializer;
    
        pubmsg.payload = payload;  // Datos a publicar
        pubmsg.payloadlen = strlen(payload);
        pubmsg.qos = QOS;
        pubmsg.retained = 0;

        MQTTClient_publishMessage(client, TOPIC, &pubmsg, NULL);
        printf("Mensaje enviado: %s\n", payload);
    
        sleep_ms (15000); //Tiempo a esperar a publicar, dado por Thinkispeead
             
    }
    
    

    // Parte muerta por bucle infinito
    MQTTClient_disconnect(client, TIMEOUT);
    MQTTClient_destroy(&client);

    cyw43_arch_deinit();
    return 0;
}

float Temperatura (){
adc_init();
  adc_set_temp_sensor_enabled(true);
  adc_select_input(4);
  uint16_t raw = adc_read();
    const float conversion = 3.33/4094;
    float resultado = raw * conversion;
     return  27 - (resultado - 0.706)/0.001721;
    

 


}