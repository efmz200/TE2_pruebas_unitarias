project(Google_test)
add_subdirectory("lib/googletest-master")
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})