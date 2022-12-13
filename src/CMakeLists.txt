set (TVC_NAME azure_test)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 14)

find_package(CURL REQUIRED)

find_package(azure-storage-blobs-cpp CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
if ( OPENSSL_FOUND )
    message(STATUS "OpenSSL Found: ${OPENSSL_VERSION}")
    message(STATUS "OpenSSL Include: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OpenSSL Libraries: ${OPENSSL_LIBRARIES}")
endif()

# Build the template VOL
add_library (${TVC_NAME} SHARED s3vl_vol_connector.cc)
add_library (VL_FILE s3vl_file_callbacks.cc)

target_link_libraries(VL_FILE Azure::azure-storage-blobs)
target_link_libraries(${TVC_NAME} VL_FILE)

# set_target_properties (${TVC_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties (${TVC_NAME} PROPERTIES SOVERSION 1)
set_target_properties (${TVC_NAME} PROPERTIES PUBLIC_HEADER "${TVC_NAME}.h")
