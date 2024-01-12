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
private:
	Node<T>* head_ptr;
	size_t many_nodes;
};
