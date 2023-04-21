cmake_minimum_required(VERSION 3.24)
project(cpp_task_15)

set(CMAKE_CXX_STANDARD 20)
add_executable(cpp_task_15 cpp_task_15.cpp sha256.cpp)
link_directories(hash-library)
