cmake_minimum_required(VERSION 3.20)

project(MyMovieList)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTING "Enable building tests" OFF)

include_directories(include/)

add_library(MyMovieListLib STATIC src/my_movie_list.cpp src/cli.cpp)

add_executable(Main src/main.cpp)
target_link_libraries(Main MyMovieListLib)

if(BUILD_TESTING)
    find_package(GTest REQUIRED)

    enable_testing()

    add_executable(Tests tests/test_my_movie_list.cpp)
    target_link_libraries(Tests GTest::gtest_main MyMovieListLib)

    include(GoogleTest)
    gtest_discover_tests(Tests)
endif()
