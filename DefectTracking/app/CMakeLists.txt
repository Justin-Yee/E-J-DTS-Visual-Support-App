


cmake_minimum_required(VERSION 3.4.1)

add_library(native-lib, SHARED, src/main/cpp/login.cpp)

include_directories(src/main/cpp/include/)