cmake_minimum_required (VERSION 3.2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-O0")

project (s3_vol DESCRIPTION "S3 VOL connector")



# Find HDF5

find_package (HDF5 1.13 COMPONENTS C REQUIRED)
link_directories (${HDF5_LIBRARY_DIRS})
include_directories (${HDF5_INCLUDE_DIR})
set (LINK_LIBS ${LINK_LIBS} ${HDF5_C_${LIB_TYPE}_LIBRARY})

# It's really easy to pick up the wrong HDF5 library if you set the path
# wrong. Turn this on for added confirmation that you got it right.
message (DEPRECATION "Include: ${HDF5_INCLUDE_DIR}")

add_subdirectory (src)
add_subdirectory (test)

