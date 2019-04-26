project(LibraryProject)
set( CMAKE_BUILD_TYPE Debug)


cmake_minimum_required(VERSION 2.6)

add_executable(LibraryProject main.c bookReg.c studentReg.c listFunc.c borrowFunc.c)

target_link_libraries(LibraryProject m)
