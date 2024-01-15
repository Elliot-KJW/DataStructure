#pragma once
#include "Node.hpp"
#include <iostream>

template <typename T>
class LinkedList {
public:
	LinkedList() {
		this->head_ptr = NULL;
		this->many_nodes = 0;
	}

	LinkedList(const LinkedList<T>& source) {
		Node<T>* tail_ptr;
		list_copy(source.head_ptr, this->head_ptr, tail_ptr);
		this->many_nodes = source.many_nodes;
	}

	~LinkedList() {
		list_clear(this->head_ptr);
	}

	size_t size() {
		return many_nodes;
	}

	LinkedList<T>& operator =(const LinkedList<T>& source) {
		if (this == &source) return *this;

		Node<T>* tail_ptr;
		list_clear(this->head_ptr);
		list_copy(source.head_ptr, this->head_ptr, tail_ptr);
		this->many_nodes = source.many_nodes;

		return *this;
	}

	void operator +=(const LinkedList<T>& addend) {
		if (this->head_ptr == NULL) {
			*this = addend;
		} else if (addend.many_nodes > 0) {
			Node<T>* tail_ptr = list_locate(this->head_ptr, this->many_nodes - 1);

			Node<T>* copy_head_ptr, *copy_tail_ptr;
			list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);

			tail_ptr->set_link(copy_head_ptr);
			this->many_nodes += addend.many_nodes;
		}
	}

	void print() {
		for (Node<T>* cursor = this->head_ptr; cursor != NULL; cursor = cursor->link()) {
			std::cout << cursor->data() << " ";
		}
		std::cout << std::endl;
	}

	void insert(const typename Node<T>::value_type& entry) {
		if (this->many_nodes == 0) {
			list_head_insert(this->head_ptr, entry);
		}
		else {
			Node<T>* tail_ptr = list_locate(this->head_ptr, this->many_nodes - 1);
			tail_ptr->set_link(new Node<T>(entry, NULL));
		}
		this->many_nodes++;
	}

	bool erase_one(const typename Node<T>::value_type& target){
		if (this->head_ptr->data() == target) {
			list_head_remove(this->head_ptr);
			return true;
		}

		Node<T>* previous = this->head_ptr;
		for (Node<T>* cursor = this->head_ptr->link(); cursor != NULL; cursor = cursor->link()) {
			if (cursor->data() == target) {
				list_remove(previous);
				return true;
			}
			previous = cursor;
		}

		return false;
	}

	size_t count(const typename Node<T>::value_type& target) {
		size_t result = this->head_ptr->data() == target ? 1 : 0;
	
		Node<T>* cursor = this->head_ptr;
		while ((cursor = list_search(cursor->link(), target)) != NULL) {
			result++;
		}

		return result;
	}

	typename Node<T>::value_type grab() {
		assert(size() > 0);

		size_t position = rand() % this->size();

		return ((Node<T>*)list_locate(this->head_ptr, position))->data();
	}
private:
	Node<T>* head_ptr;
	size_t many_nodes;
};
