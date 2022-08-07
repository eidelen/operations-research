cmake_minimum_required(VERSION 3.14.7)

project(CMakeORTools VERSION 1.0 LANGUAGES CXX)

include_directories(/Users/eidelen/dev/libs/or-tools_MacOsX-12.2.1_v9.3.10497/include)

link_directories(/Users/eidelen/dev/libs/or-tools_MacOsX-12.2.1_v9.3.10497/lib)

add_executable(CMakeORTools main.cpp)
target_compile_features(CMakeORTools PUBLIC cxx_std_17)
target_link_libraries(CMakeORTools ortools)
