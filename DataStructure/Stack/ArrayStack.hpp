#pragma once
#include <iostream>

template <typename T>
class ArrayStack {
public:
	ArrayStack(size_t capacity) {
		this->data = new T[capacity];
		this->used = 0;
		this->capacity = capacity;
	}

	size_t size() const {
		return this->used;
	}

	bool empty() const {
		return used == 0;
	}

	void push(const T& entry) {
		assert(this->size() < capacity);
		data[used++] = entry;
	}

	T& top() {
		assert(!this->empty());
		return this->data[used - 1];
	}

	T& pop() {
		assert(!this->empty());
		T& result = this->data[used - 1];
		--used;

		return result;
	}

	void print() {
		if (this->empty()) {
			std::cout << "empty stack!" << std::endl;
		}
		else {
			for (int i = 0; i < used; i++) {
				std::cout << data[i] << ' ';
			}
			std::cout << std::endl;
		}
	}
private:
	size_t capacity;
	T* data;
	size_t used;
};