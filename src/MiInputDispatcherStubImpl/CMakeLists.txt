cmake_minimum_required(VERSION 3.5)
project(MiInputDispatcher  LANGUAGES CXX)


# 添加动态库
aux_source_directory(. srcs)
add_library(MiInputDispatcherStubImpl SHARED ${srcs})
target_link_libraries(MiInputDispatcherStubImpl  InputDispatcher)
