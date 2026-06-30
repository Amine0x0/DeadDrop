cmake_minimum_required(VERSION 3.15)
project(DeadDropCore CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/core/include)

add_executable(deaddrop_core 
    src/core/main.cpp
)