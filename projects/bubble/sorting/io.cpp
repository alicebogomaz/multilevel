#include "io.hpp"
#include <vector>
#include <iostream>

void ABogomaz::print_array(const char* const comment, int* arr, const int size) {
    if (arr == nullptr || size <= 0) {
        std::cout << "Массив пуст или некорректен" << std::endl;
        return;
    }

    std::cout << comment;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 

}
