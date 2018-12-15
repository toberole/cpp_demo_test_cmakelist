cmake_minimum_required(VERSION 3.6.0)

configure_file(
        "${CMAKE_CURRENT_LIST_DIR}/src/config.h.in"
        "${CMAKE_BINARY_DIR}/config.h"
)

# 添加 ./src 下面的所有文件到变量DIR_SRCS
AUX_SOURCE_DIRECTORY(./src DIR_SRCS)

# 指定头文件的位置
include_directories(./include)
include_directories(${CMAKE_BINARY_DIR})

add_library(module_1_lib_out ${DIR_SRCS})

# install 指定library的安装路径
