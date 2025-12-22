cmake_minimum_required(VERSION 3.31)

project(study)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(didactiyka)
add_subdirectory(sort)
add_subdirectory(unit_test)


set(CMAKE_SUPPRESS_REGENERATION true)

