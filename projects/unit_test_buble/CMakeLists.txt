project(unit_test)

set(BUBBLE_LIB "bubble_sort_lib")

add_library(${BUBBLE_LIB} "")

add_subdirectory(src)
add_subdirectory(test)
