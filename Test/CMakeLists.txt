# Set common header file directory paths

set(doctest_dir ${CMAKE_SOURCE_DIR}/Test/Tools/doctest/)

list(APPEND inc_dir ${doctest_dir})
include_directories(${inc_dir})

# Set source files for build
# Add any newly added source file below

# file(GLOB arraySrc ${CMAKE_SOURCE_DIR}/Array/*.cpp)
file(GLOB arraySlidingWindowSrc ${CMAKE_SOURCE_DIR}/Array/sliding-window/*.cpp)
list(APPEND arraySrc ${arraySlidingWindowSrc})

list(APPEND src ${arraySrc})
message(src=${src})

# Build executable

add_executable(Comp Test.cpp ${src})