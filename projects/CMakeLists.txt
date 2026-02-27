cmake_minimum_required(VERSION 3.31)

project(multilevel)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(didactiyka)
add_subdirectory(bubble)
add_subdirectory(merge)
add_subdirectory(unit_test_merge)
add_subdirectory(unit_test_buble)

add_subdirectory(long_num)

set(CMAKE_SUPPRESS_REGENERATION true)

