project(smart_pointer)

#指定二进制文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

# GLOB_RECURSE 批量添加了当前子目录下的所有源码和头文件
file(GLOB_RECURSE CPP_SRC CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE CPP_HDR CONFIGURE_DEPENDS *.hpp)

add_executable(${PROJECT_NAME}
        ${CPP_SRC} ${CPP_HDR}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CPP_HDR})