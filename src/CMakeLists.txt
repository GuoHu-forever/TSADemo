cmake_minimum_required(VERSION 3.5)
project(main  LANGUAGES CXX)


# 添加子模块
add_subdirectory(InputDispatcher)
add_subdirectory(MiInputDispatcherStubImpl)

# 添加可执行文件
aux_source_directory(. srcs)
add_executable(TSADemo ${srcs})

# 将子模块的库链接到当前的可执行文件
target_link_libraries(TSADemo  InputDispatcher)
