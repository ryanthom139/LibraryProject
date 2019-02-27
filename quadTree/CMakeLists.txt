project(quadTree)
set( CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-std=c99")

cmake_minimum_required(VERSION 2.6)

add_executable(quadTree tests.c buildTree.c writeTree.c valueTree.c)

target_link_libraries(quadTree m)


