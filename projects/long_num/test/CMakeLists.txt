add_executable(test_long_num test_long_num.cpp)
add_executable(busko_test_long_number busko_test_long_number.cpp)

target_link_libraries(test_long_num
    gtest_main
    gmock_main
    long_num
)

target_link_libraries(busko_test_long_number
    gtest_main
    gmock_main
    long_num
)

add_test(test_long_num test_long_num)
add_test(busko_test_long_number busko_test_long_number)
