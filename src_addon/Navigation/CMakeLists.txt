cmake_minimum_required (VERSION 3.2.3)

project (Navigation)

source_group("Source" ${PROJECT_SOURCE_DIR})

add_library(Navigation GameNavigation.h GameNavigation.cpp)
