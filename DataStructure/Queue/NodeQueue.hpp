#pragma once
#include "../Node/Node.hpp"

template <typename T>
class NodeQueue
{
public:
	NodeQueue() {
		this->count = 0;
		this->front_ptr = NULL;
	}

	NodeQueue(const NodeQueue<T>& source) {
		this->count = source.count;
		list_copy(source, this->front_ptr, this->rear_ptr);
	}

	~NodeQueue() {
		list_clear(this->front_ptr);
	}

	NodeQueue<T>& operator = (const NodeQueue<T>& source) {
		if (this == &source) {
			return *this;
		}
		list_clear(this->front_ptr);
		list_copy(source.front_ptr, this->front_ptr, this->rear_ptr);
		this->count = source.count;

		return *this;
	}

	void enqueue(const T& entry) {
		if (this->empty()) {
			list_head_insert(this->front_ptr, entry);
			this->rear_ptr = this->front_ptr;
		}
		else {
			list_insert(this->rear_ptr, entry);
			this->rear_ptr = this->rear_ptr->link();
		}
		this->count++;
	}

	T dequeue() {
		assert(!this->empty());
		T result = this->front_ptr->data();
		list_head_remove(this->front_ptr);
		this->count--;
		return result;
	}

	bool empty() const {
		return (this->count == 0);
	}

	T front() const {
		assert(!this->empty());
		return this->front_ptr->data();
	}

	T rear() const {
		assert(!this->empty());
		return this->rear_ptr->data();
	}

	size_t size() const {
		return this->count;
	}
private:
	Node<T>* front_ptr;
	Node<T>* rear_ptr;
	size_t count;
};