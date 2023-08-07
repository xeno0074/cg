cmake_minimum_required(VERSION 3.16)

project(COMP VERSION 0.1
        DESCRIPTION "Coding Practice"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -fno-omit-frame-pointer -faligned-new -fno-builtin")

add_subdirectory(${CMAKE_SOURCE_DIR}/Test)
