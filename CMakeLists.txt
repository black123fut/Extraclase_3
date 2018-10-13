cmake_minimum_required(VERSION 3.10)
project(Algoritmo_LZW)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algoritmo_LZW main.cpp encoder.cpp)

add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )
add_definitions( -DWITH_ImageMagick=0 )
find_package(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(Algoritmo_LZW ${ImageMagick_LIBRARIES})

