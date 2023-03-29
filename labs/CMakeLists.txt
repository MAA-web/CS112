cmake_minimum_required(VERSION 3.0.0)
project(CS112-Labs VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(CS112-Labs lab_I_structs_2.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
