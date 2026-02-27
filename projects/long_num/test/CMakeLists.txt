set(SOURCES
    test_long_num.cpp
)

add_executable(test_long_num ${SOURCES})

target_link_libraries(test_long_num
    gtest_main
    gmock_main
    long_num
)

add_test(test_long_num test_long_num)
