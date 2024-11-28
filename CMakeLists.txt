cmake_minimum_required(VERSION 3.13)

# Nombre del proyecto
project(mqtt_pico_project)

# Incluye el SDK de Pico
include(pico_sdk_init.cmake)
pico_sdk_init()

# Define el ejecutable principal
add_executable(mqtt_pico main.c)

# Incluye los encabezados necesarios
target_include_directories(mqtt_pico PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include    # Encabezados de Paho MQTT
)

# Vincula las bibliotecas necesarias
target_link_libraries(mqtt_pico
    pico_stdlib                          # Biblioteca estándar de Pico
    pico_cyw43_arch_lwip               # Wi-Fi y lwIP
    hardware_pio
    hardware_adc
    ${CMAKE_CURRENT_LIST_DIR}/libs/libpaho-mqtt3c.a  # Biblioteca estática MQTT síncrono
)

# Habilitar salida USB para depuración
pico_enable_stdio_usb(mqtt_pico 1)
pico_enable_stdio_uart(mqtt_pico 0)

# Genera archivos UF2
pico_add_extra_outputs(mqtt_pico)
