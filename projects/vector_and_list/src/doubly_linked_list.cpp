#include "doubly_linked_list.hpp"

#include <iostream>

using al::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() noexcept: begin(nullptr), end(nullptr), list_size(0) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node* current = begin;

	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}

	begin = nullptr;
	end = nullptr;
	list_size = 0;
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept
{
	return list_size;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept
{
	if (list_size == 0) {
		return false;
	}

	Node* current = begin;

	while (current != nullptr) {

		if (current->value == value) {
			return true;
		}
		current = current->next;
	}

	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept
{
	if (list_size == 0) {
		std::cout << "the list is empty! :c " << std::endl;

		return;
	}

	Node* current = begin;

	while (current != nullptr) {
		std::cout << current->value << " ";
		current = current->next;
	}

	std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value)
{
	Node* newNode = new Node(value);

	if (list_size == 0) {
		begin = newNode;
		end = newNode;

		list_size++;

		return;
	}

	Node* prevNode = end;
	prevNode->next = newNode;
	newNode->prev = prevNode;
	end = newNode;

	list_size++;
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept
{
	if (list_size == 0) {
		return false;
	}

	Node* current = begin;

	while (current != nullptr) {

		if (current->value != value) {
			current = current->next;

			continue;
		}

		if (begin == end) {
			begin = nullptr;
			end = nullptr;
		}

		else if (begin == current) {
			begin = current->next;
			begin->prev = nullptr;
		}

		else if (end == current) {
			end = current->prev;
			end->next = nullptr;
		}

		else {
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}

		delete current;
		list_size--;

		return true;
	}

	return false;
}
