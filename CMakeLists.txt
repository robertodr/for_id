cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
# Set CMake policies here
if(CMAKE_VERSION VERSION_GREATER 2.8.3)
   # CMP0017 was introduced in CMake 2.8.4
   # Always prefer system modules to local ones
   cmake_policy(SET CMP0017 NEW)
endif()

#  Declare project name and programming languages
project(for_id CXX)

set(CMAKE_BUILD_TYPE Release)

# Modules
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_SOURCE_DIR}/cmake
    )

find_package(Boost 1.54.0)
if (NOT Boost_FOUND)
    include_directories(boost)
endif()
include_directories(src)

add_executable(example.x example.cpp)
add_executable(example_1D.x example_1D.cpp)
