# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)
project(ISayHello)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(entry SHARED hello.cpp)
add_library(entry2 SHARED test_djinni_wrapper.cpp)
add_subdirectory(aki)
target_link_libraries(entry PUBLIC aki_jsbind)
target_link_libraries(entry2 PUBLIC aki_jsbind)