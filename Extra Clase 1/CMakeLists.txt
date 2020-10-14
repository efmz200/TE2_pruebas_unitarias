cmake_minimum_required(VERSION 3.17)
project(TE2_pruebas_unitarias)

set(CMAKE_CXX_STANDARD 14)

add_executable(TE2_pruebas_unitarias ../main.cpp)
target_link_libraries(TE2_pruebas_unitarias gtest_main)