cmake_minimum_required(VERSION 3.5)
project(RPNCalculator VERSION 0.1.0 LANGUAGES C CXX)

# Add the main library
add_library(RPNCalculator RPNCalculator.cpp
        main.cpp)

# Enable testing
enable_testing()

# Add GoogleTest subdirectory
add_subdirectory(googletest)

# Include directories
include_directories(googletest/include)

# Add executable for tests
add_executable(RPNCalculatorTests RPNCalculatorTests.cpp)

# Link GoogleTest library
target_link_libraries(RPNCalculatorTests PRIVATE gtest)

# Discover and include GoogleTest
include(GoogleTest)
gtest_discover_tests(RPNCalculatorTests)