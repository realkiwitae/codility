cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(codility) #name of your project

include_directories(./)
include_directories(./headers)
add_executable(codility main.cpp)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_compile_options(codility PRIVATE -Wall -ggdb3)
target_link_libraries(codility rt ${OpenCV_LIBS})