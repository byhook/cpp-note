cmake_minimum_required(VERSION 3.27)

project(cpp-note)

set(CMAKE_CXX_STANDARD 17)

#指定二进制文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

#C++编程思想
add_subdirectory(thinking_in_cpp)