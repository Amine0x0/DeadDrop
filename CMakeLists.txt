cmake_minimum_required(VERSION 3.15)
project(DeadDropCore CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/core/include)

file(GLOB_RECURSE CORE_SOURCES "src/core/*.cpp")

add_executable(deaddrop_core ${CORE_SOURCES})