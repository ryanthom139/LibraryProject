project(LibraryProject)
set( CMAKE_BUILD_TYPE Debug)


cmake_minimum_required(VERSION 2.6)

add_executable(LibraryProject main.c bookReg.c studentReg.c listFunc.c borrowFunc.c)
add_executable(test_bookReg bookRegTest.c unity/unity.c bookReg.c)
add_executable(test_studentReg studentRegTest.c unity/unity.c studentReg.c)
add_executable(test_borrowFunc borrowFuncTest.c unity/unity.c borrowFunc.c studentReg.c bookReg.c)


