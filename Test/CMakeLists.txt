# Set common header file directory paths

set(doctest_dir ${CMAKE_SOURCE_DIR}/Test/Tools/doctest/)

list(APPEND inc_dir ${doctest_dir})
include_directories(${inc_dir})

# Set source files for build
# Add any newly added source file below

# file(GLOB arraySrc ${CMAKE_SOURCE_DIR}/Array/*.cpp)
# file(GLOB arraySlidingWindowSrc ${CMAKE_SOURCE_DIR}/Array/sliding-window/*.cpp)
# list(APPEND arraySrc ${arraySlidingWindowSrc})

file(GLOB ftSrc ${CMAKE_SOURCE_DIR}/DNC/FenwickTree/*.cpp)

list(APPEND src ${arraySrc})
list(APPEND src ${ftSrc})
message(src=${src})

# Build executable

add_executable(Comp Test.cpp ${src})