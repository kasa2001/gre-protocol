cmake_minimum_required(VERSION 3.17)
project(gre_protocol)

set(CMAKE_CXX_STANDARD 14)

add_executable(gre_protocol main.cpp src/cpp/Router.cpp src/hpp/Router.h src/cpp/Network.cpp src/hpp/Network.h src/cpp/Package.cpp src/hpp/Package.h)