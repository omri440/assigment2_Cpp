# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(assigment2_Cpp VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(assigment2_Cpp main.cpp Menu.cpp Product.cpp ShoppingCart.cpp Supplier.cpp)


# Include directories for header files
include_directories(${CMAKE_SOURCE_DIR})

# Add compiler warnings
if (MSVC)
    target_compile_options(assigment2_Cpp PRIVATE /W4 /permissive-)
else()
    target_compile_options(assigment2_Cpp PRIVATE -Wall -Wextra -pedantic)
endif()
