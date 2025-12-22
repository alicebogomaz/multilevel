set(SOURCES
    test_bubble.cpp
)

#target_include_directories(test_bubble PRIVATE
#    "../src/"
#)

add_executable(test_bubble ${SOURCES})

target_link_libraries(test_bubble
    gtest_main
    gmock_main
    bubble_sort_lib
)

add_test(test_bubble test_bubble)
