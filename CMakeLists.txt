cmake_minimum_required(VERSION 3.6.0)

project(demo_test)

set(CMAKE_CXX_STANDARD 14)

message("++++++++++ 开始编译 ++++++++++")

# 检测系统是否有支持工程使用的API
include (CheckFunctionExists)
# 检测printf 系统API是否存在
# 存在则定义HAVE_PRINTF宏
check_function_exists (printf HAVE_PRINTF)

# 添加编译开关
option(ENABLE_MAX "---- enable max ----" OFF)

# 添加全局的宏 子模块和主模块的代码里面可以直接使用
# 可以作为开关使用 控制代码的编译逻辑
if (ENABLE_MAX)
    add_definitions(-DSWI_ENABLE_MAX)
endif ()

# 设置变量 .h.in文件里面可以使用
set(CMKAE_MAX_COUNT 2000)
set(HAVE_PRINTF_XXX 3000)

# 可以在执行ccmake命令的时候输入
set(XXX_EXPIRE "" CACHE STRING "xxx_expire value")

# 给指定的目标添加宏
# target_compile_definitions()

# 添加源文件
AUX_SOURCE_DIRECTORY(./src LOCAL_SRCS)

# 添加 ./include 下面的头文件 到list变量HEADERS里面
list(APPEND HEADERS ./include)

# 添加子模块
add_subdirectory(module_1)

# 指定头文件的位置
list(APPEND HEADERS ./module_1/include)
# include_directories(./module_1/include)

# 添加 module_1_lib_out库到 list变量EXERA_LIBS里面
list(APPEND EXERA_LIBS  module_1_lib_out)

# 指定头文件
include_directories(${HEADERS})

# 生成可执行文件main_exec
add_executable(main_exec ${LOCAL_SRCS})

target_link_libraries(main_exec ${EXERA_LIBS})