#include "io.hpp"
#include <vector>
#include <iostream>

// Функция для вывода элементов массива
// arr: указатель на первый элемент массива
// size: количество элементов в массиве
void biv::print_array(const char* const comment, int* arr, const int size) {
    // Проверяем, что указатель не нулевой и размер больше нуля
    if (arr == nullptr || size <= 0) {
        std::cout << "Массив пуст или некорректен" << std::endl;
        return;
    }

    std::cout << comment;
    // Перебираем элементы массива от 0 до size-1
    for (int i = 0; i < size; ++i) {
        // Выводим текущий элемент
        std::cout << arr[i] << " ";
        // Или можно использовать: std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl; // Переходим на новую строку после вывода всех элементов

}
