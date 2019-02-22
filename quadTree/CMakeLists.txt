project(quadtree_start)
set( CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 2.6)

add_executable(quadtree_start main.c buildTree.c writeTree.c destroyTree.c growTree.c)

target_link_libraries(quadtree_start m)