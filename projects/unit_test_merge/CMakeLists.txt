project(unit_test_merge)

set(MERGE_LIB "merge_sort_lib55555")

add_library(${MERGE_LIB} "")

add_subdirectory(src)
add_subdirectory(test)
