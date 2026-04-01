#include "vector.hpp"

#include <iostream>

using al::Vector;

template<typename T>
Vector<T>::Vector()
{
	arr = new T[capacity];
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] arr;
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept
{
	return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept
{

	if (size == 0) {
		return false;
	}

	for (std::size_t index = 0; index < size; index++) {
		if (arr[index] == value) {
			return true;
		}
	}

	return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value)
{

	if (position > size) {
		return false;
	}

	if (size == capacity) {
		T* newArr = new T[capacity * 2];

		for (std::size_t index = 0; index < capacity; index++) {
			newArr[index] = arr[index];
		}

		delete[] arr;
		arr = newArr;
		capacity *= 2;
	}

	for (std::size_t move = size; move > position; --move) {
		arr[move] = arr[move - 1];
	}

	arr[position] = value;
	size++;

	return true;
}

template<typename T>
void Vector<T>::print() const noexcept
{
	if (size == 0) {
		std::cout << "the list is empty :c " << std::endl;
		return;
	}

	for (std::size_t index = 0; index < size; index++) {
		std::cout << arr[index] << " ";
	}
	std::cout << std::endl;

	return;
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
	if (size == capacity) {
		T* newArr = new T[capacity * 2];

		for (std::size_t index = 0; index < size; index++) {
			newArr[index] = arr[index];
		}

		delete[] arr;
		arr = newArr;
		capacity *= 2;
	}

	arr[size] = value;
	size++;

	return;
}

template<typename T>
bool Vector<T>::remove_first(const T& value)
{
	for (std::size_t index = 0; index < size; index++) {
		if (arr[index] == value) {
			for (std::size_t move = index; move < size - 1; ++move) {
				arr[move] = arr[move + 1];
			}

			size--;
			return true;
		}
	}

	return false;
}
