project(thinking_in_cpp)

# GLOB_RECURSE 批量添加了当前子目录下的所有源码和头文件
file(GLOB_RECURSE THINKING_IN_CPP_SRC CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE THINKING_IN_CPP_HDR CONFIGURE_DEPENDS *.hpp)

add_executable(${PROJECT_NAME}
        ${THINKING_IN_CPP_SRC} ${THINKING_IN_CPP_HDR}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${THINKING_IN_CPP_HDR})