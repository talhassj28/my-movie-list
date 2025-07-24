cmake_minimum_required(VERSION 3.20)

project(MyMovieList)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include/)

add_library(MyMovieListLib STATIC src/my_movie_list.cpp src/cli.cpp)

add_executable(Main src/main.cpp)

target_link_libraries(Main MyMovieListLib)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Tests tests/test_my_movie_list.cpp)

target_link_libraries(Tests gtest_main MyMovieListLib)

include(GoogleTest)

gtest_discover_tests(Tests)
