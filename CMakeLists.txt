cmake_minimum_required(VERSION 3.5)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
ELSE ()
    set(CMAKE_CXX_COMPILER "C:\\Program Files\\LLVM\\bin\\clang-cl.exe")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

project(TSADemo  LANGUAGES CXX)


# 设置编译选项
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "   -Wthread-safety")
# 用于因为Windows旧的SDK定义有一个byte的类型，
# 但在C++17里也有定义std::byte类型，这样就会造成重复定义
add_definitions(-D_HAS_STD_BYTE=0)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加库文件目录和输出目录
link_directories(${PROJECT_SOURCE_DIR}/lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加模块
add_subdirectory(src)
