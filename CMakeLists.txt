cmake_minimum_required(VERSION 3.5)
project(TSADemo  LANGUAGES CXX)


# 设置编译选项
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER "C:\\Program Files\\LLVM\\bin\\clang-cl.exe")
set(CMAKE_CXX_FLAGS "   -Wthread-safety")

# 添加头文件目录
include_directories(include)

# 添加库文件目录和输出目录
link_directories(${PROJECT_SOURCE_DIR}/lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加模块
add_subdirectory(src)
