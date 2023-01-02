cmake_minimum_required(VERSION 3.23)
project(array-source)

set(CMAKE_CXX_STANDARD 14)

add_executable(CmakeProject driver.cpp Array.cpp Array.h)
