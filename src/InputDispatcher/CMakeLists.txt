cmake_minimum_required(VERSION 3.5 )
project(InputDispatcher  LANGUAGES CXX)


# 添加动态库
aux_source_directory(. srcs)
add_library(InputDispatcher SHARED ${srcs})
