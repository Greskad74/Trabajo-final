# Install script for directory: /opt/pico-sdk/lib/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/i74/Escritorio/wifi/build/_deps")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE MESSAGE_NEVER PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/aes.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/aesni.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/arc4.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/aria.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/asn1.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/asn1write.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/base64.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/bignum.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/blowfish.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/bn_mul.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/camellia.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ccm.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/certs.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/chacha20.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/chachapoly.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/check_config.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/cipher.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/cipher_internal.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/cmac.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/compat-1.3.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/config.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/config_psa.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/constant_time.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ctr_drbg.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/debug.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/des.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/dhm.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ecdh.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ecdsa.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ecjpake.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ecp.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ecp_internal.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/entropy.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/entropy_poll.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/error.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/gcm.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/havege.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/hkdf.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/hmac_drbg.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/md.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/md2.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/md4.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/md5.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/md_internal.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/net.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/net_sockets.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/nist_kw.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/oid.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/padlock.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/pem.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/pk.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/pk_internal.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/pkcs11.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/pkcs12.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/pkcs5.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/platform.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/platform_time.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/platform_util.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/poly1305.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/psa_util.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ripemd160.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/rsa.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/rsa_internal.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/sha1.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/sha256.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/sha512.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ssl.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ssl_cache.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ssl_cookie.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ssl_internal.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/ssl_ticket.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/threading.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/timing.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/version.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/x509.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/x509_crl.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/x509_crt.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/x509_csr.h"
    "/opt/pico-sdk/lib/mbedtls/include/mbedtls/xtea.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/psa" TYPE FILE MESSAGE_NEVER PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_builtin_composites.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_builtin_primitives.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_compat.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_config.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_driver_common.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_driver_contexts_composites.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_driver_contexts_primitives.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_extra.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_platform.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_se_driver.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_sizes.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_struct.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_types.h"
    "/opt/pico-sdk/lib/mbedtls/include/psa/crypto_values.h"
    )
endif()

