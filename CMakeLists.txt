cmake_minimum_required(VERSION 3.0)
project(6502_simulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Include Google Test in the build process
add_subdirectory(extern/googletest)

# Ensure your project can find the Google Test headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_library(MyLibrary src/simple_lib.cpp)

add_executable(6502_simulator src/main.cpp)



# Add the tests
add_executable(runSimpleLibTest test/test_simple_lib.cpp src/simple_lib.cpp)
target_link_libraries(runSimpleLibTest gtest gtest_main)
