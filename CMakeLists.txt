cmake_minimum_required(VERSION 3.6.0)

project(demo_test)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(./src SRC_DIRS)

include_directories(./include)


configure_file(
        "${CMAKE_CURRENT_LIST_DIR}/src/config.h.in"
        "${CMAKE_CURRENT_LIST_DIR}/src/test_config.h"
)

option(ENABLE_TEST_OPTITION "ENABLE_TEST_OPTITION DESC" OFF)

# 设置一个自定义的宏变量
if (ENABLE_TEST_OPTITION)
    set(TEST_OPTITION 1)
endif ()


# 生成库
add_library(demo_lib_hello SHARED ${SRC_DIRS} include/Bus.h src/test_extern.h src/test_extern.c)

# 生成可执行文件
add_executable(demo_test ${SRC_DIRS} include/Bus.h src/test_extern.h src/test_extern.c)


# 通过cmakelist脚本添加宏 可以直接在源代码里面使用
# 这样可以通过cmakelist脚本控制代码逻辑
target_compile_definitions(demo_test PUBLIC ADD_DEFINE)