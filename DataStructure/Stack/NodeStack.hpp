#pragma once
#include <iostream>
#include "Node/Node.hpp"

template <typename T>
class NodeStack {
public:
	NodeStack() {
		this->top_ptr = NULL;
	}

	NodeStack(const NodeStack<T>& source) {
		Node<T>* tail_ptr;
		list_copy(source.top_ptr, this->top_ptr, tail_ptr);
	}

	size_t size() const {
		return list_length(this->top_ptr);
	}

	bool empty() const {
		return this->top_ptr == NULL;
	}

	void push(const T& entry) {
		list_head_insert(this->top_ptr, entry);
	}

	T top() {
		assert(!this->empty());
		return this->top_ptr->data();
	}

	T pop() {
		assert(!this->empty());
		T result = this->top_ptr->data();
		list_head_remove(this->top_ptr);

		return result;
	}

	void print() {
		if (this->empty()) {
			std::cout << "empty stack!" << std::endl;
		}
		else {
			for (Node<T>* cursor = this->top_ptr; cursor != NULL; cursor = cursor->link()) {
				std::cout << cursor->data() << " ";
			}
			std::cout << std::endl;
		}
	}
private:
	Node<T>* top_ptr;
};