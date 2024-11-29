cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Set the Pico SDK path
set(PICO_SDK_PATH "/opt/pico-sdk")

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Import the Pico SDK
include(pico_sdk_import.cmake)

# Ensure Pico SDK is version 1.4.0 or later
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Define the project
project(mqtt C CXX ASM)

# Initialize the Pico SDK
pico_sdk_init()

# Add the main executable
add_executable(mqtt main.c)

# Set program metadata
pico_set_program_name(mqtt "mqtt")
pico_set_program_version(mqtt "0.1")

# Enable USB for standard I/O
pico_enable_stdio_uart(mqtt 0)
pico_enable_stdio_usb(mqtt 1)

# Include directories
target_include_directories(mqtt PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${PICO_SDK_PATH}/lib/lwip/src/include  
    ${PICO_SDK_PATH}/lib/lwip/test/unit
)

# Link required libraries
target_link_libraries(mqtt
    pico_stdlib
    pico_cyw43_arch_lwip_threadsafe_background  # Puedes ajustar según tu arquitectura
    hardware_pio
    hardware_adc
    ${CMAKE_CURRENT_LIST_DIR}/libs/libpaho-mqtt3c.a
)

# Generate additional outputs
pico_add_extra_outputs(mqtt)
