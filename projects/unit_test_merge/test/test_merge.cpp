#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sortings.hpp"

TEST(ArraysEqual, AnyElementsCount) {
    int* actual = new int[]{1, 8, 2, 5, 3, 11};
    int actual_size = 6;
    sort::mergeSort(actual, 0, actual_size - 1);
    int* expected = new int[]{1, 2, 3, 5, 8, 11};
    int expected_size = 6;
    ASSERT_EQ(expected_size, actual_size)
        << "Разные размеры массивов";
    for (int i = 0; i < actual_size; i++) {
        ASSERT_EQ(expected[i], actual[i])
        << "Отличие массивов в элементе с индексом " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
