#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sortings.hpp"

TEST(ArraysEqual, AnyElementsCount) {
//    std::vector<int> actual = {1, 8, 2, 5, 3, 11};
    int actual[] = {1, 8, 2, 5, 3, 11};
    int actual_size = sizeof(actual) / sizeof(actual[0]);
    ABogomaz::sortings::bubble_sort(actual, actual_size);
//    std::vector<int> expected = {1, 2, 5, 3, 8, 11};
    int expected[] = {1, 2, 5, 3, 8, 11};
    int expected_size = sizeof(expected) / sizeof(expected[0]);
    
//    ASSERT_EQ(expected.size(), actual.size())
    ASSERT_EQ(expected_size, actual_size)
        << "Разные размеры массивов";
    
//    for (int i = 0; i < actual.size(); i++) {
    for (int i = 0; i < actual_size; i++) {
        ASSERT_EQ(expected[i], actual[i])
        << "Отличие массивов в элементе с индексом " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
