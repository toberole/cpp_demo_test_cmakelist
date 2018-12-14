### 指定版本：
    cmake_minimum_required(VERSION 3.6.0)
### 指定项目名称
    project(xxxx)

### cmake输出信息
    message(" hello world ")

### 设置一些预定义变量的值
    设置C++版本 set(CMAKE_CXX_STANDARD 14)

### 构建库
    构建一个名字为xxxlib 共享库 所需要的源文件是 demo.c demo.h
    add_library(xxxlib SHARED demo.c demo.h ...)

### 构建可执行文件
    add_executable(xxxexe demo.c demo.h)

### 给构建目标添加宏
    给demo_test目标添加一个XXXX_DEFINE宏 可以直接在源代码里面使用
    target_compile_definitions(demo_test PUBLIC XXXX_DEFINE)




