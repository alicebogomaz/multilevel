add_executable(test_vector test_vector.cpp)
add_executable(test_list test_doubly_linked_list.cpp)

target_link_libraries(test_vector
    gtest_main
    gmock_main
    vector
)

target_link_libraries(test_list
    gtest_main
    gmock_main
    list
)

add_test(test_vector test_vector)
add_test(test_list test_list)
