#ifndef LWIP_HDR_LWIPOPTS_H
#define LWIP_HDR_LWIPOPTS_H

/* ------------------------------------------------------------------------
 * Configuraciones generales
 * ------------------------------------------------------------------------ */
#define NO_SYS                     1     // Habilita Netif API y Sequential API
#define LWIP_NETIF_API             0     // Habilita Netif API
#define LWIP_NETCONN               0     // Habilita Sequential API (necesaria para MQTT)
#define LWIP_SOCKET                0     // Habilita Sockets API
#define LWIP_TIMEVAL_PRIVATE       0     // Usa la definición de struct timeval de Newlib

/* ------------------------------------------------------------------------
 * Configuración de memoria
 * ------------------------------------------------------------------------ */
#define MEM_ALIGNMENT              4     // Alineación de memoria
#define MEM_SIZE                   1600  // Tamaño total de memoria para lwIP

/* Configuración de PBUF */
#define PBUF_POOL_SIZE             16    // Número de buffers en el pool
#define PBUF_POOL_BUFSIZE          500   // Tamaño de cada buffer

/* ------------------------------------------------------------------------
 * Configuración de TCP
 * ------------------------------------------------------------------------ */
#define TCP_MSS                    536   // Tamaño máximo de segmento TCP
#define TCP_SND_BUF                (2 * TCP_MSS)  // Tamaño del buffer de envío TCP
#define TCP_WND                    (2 * TCP_MSS)  // Tamaño de la ventana TCP

/* ------------------------------------------------------------------------
 * Configuración de ICMP y UDP
 * ------------------------------------------------------------------------ */
#define LWIP_ICMP                  1     // Habilita ICMP (opcional para ping)
#define LWIP_UDP                   1     // Habilita UDP
#define LWIP_TCP                   1     // Habilita TCP

/* ------------------------------------------------------------------------
 * Configuración de DNS
 * ------------------------------------------------------------------------ */
#define LWIP_DNS                   1     // Habilita el cliente DNS

/* ------------------------------------------------------------------------
 * Configuración del sistema
 * ------------------------------------------------------------------------ */
#define SYS_LIGHTWEIGHT_PROT       1     // Protección ligera para datos compartidos
#define LWIP_NETIF_STATUS_CALLBACK 1     // Habilita callbacks para cambios de estado de la red
#define LWIP_NETIF_LINK_CALLBACK   1     // Habilita callbacks para cambios en el enlace

/* ------------------------------------------------------------------------
 * Configuración de depuración
 * ------------------------------------------------------------------------ */
#define LWIP_DEBUG                 0     // Deshabilita mensajes de depuración

#endif /* LWIP_HDR_LWIPOPTS_H */
