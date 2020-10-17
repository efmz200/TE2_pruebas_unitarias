project(Google_test)
add_subdirectory("lib/googletest-master")
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

add_executable(Google_Test_run ConverterTest.cpp AbsoluteDateTest.cpp)
target_link_libraries(Google_Test_run "/home/drump1/Desktop/te 2/TE2_pruebas_unitarias/servidor")
target_link_libraries(Google_Test_run gtest gtest_main)
