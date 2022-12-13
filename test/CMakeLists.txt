# Build the test


add_executable (write write.cc)
target_include_directories (write PRIVATE "${PROJECT_SOURCE_DIR}/src")
target_link_libraries (write ${HDF5_C_LIBRARIES})