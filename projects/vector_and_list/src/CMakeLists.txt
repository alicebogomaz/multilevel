add_library(vector vector.cpp)
add_library(list doubly_linked_list.cpp)

target_include_directories(vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
