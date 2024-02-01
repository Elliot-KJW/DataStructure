#pragma once
#include <iostream>
#include <cassert>

template <typename T>
class ArrayList {
public:
	ArrayList(size_t capacity) {
	// postcondition: create init List with input capacity
		this->data = new T[capacity];
		this->capacity = capacity;
		this->used = 0;
	}
	

	ArrayList(const ArrayList<T>& source) {
	// postcondition: create List copied by source
		this->data = new T[source.capacity];
		this->capacity = source.capacity;
		this->used = source.used;
		std::copy(source.data, source.data + source.used, this->data);
	}

	~ArrayList() {
		delete[] this->data;
	}

	ArrayList<T>& operator =(const ArrayList<T>& source) {
	// precondition: self assingment is not allowed
	// postcondition: return new ArrayList copied by source
		T* new_data;

		if (this == &source) {
			return *this;
		}

		if (capacity != source.capacity) {
			new_data = new T[source.capacity];
			delete[] data;
			this->capacity = source.capacity;
			data = new_data;
		}

		this->used = source.used;
		std::copy(source.data, source.data + used, data);
		return *this;
	}

	void reserve(size_t new_capacity) {
	// postcondition: reserve new capacity 
		if (this->capacity == new_capacity) return;
		if (new_capacity < this->used) new_capacity = this->used;

		T* larger_data = new T[new_capacity];
		std::copy(this->data, this->data + used, larger_data);
		delete[] this->data;
		this->data = larger_data;
		this->capacity = new_capacity;
	}

	void insert(T newEntry) {
	// precondition: used < CAPACITY
	// postcondition: new Entry inserted in list
		if (this->used == this->capacity) {
			this->reserve(used + 1);
		}

		data[this->used++] = newEntry;
	}
	
	T& remove(T target) {
		// precondition: used > 0
		// postcondition: remove one Entry equal to target 
		assert(this->used > 0);

		T result;
		for (int i = 0; i < this->used; i++) {
			if (this->data[i] == target) {
				result = this->data[i];
				for (int j = i; j < this->used - 1; j++) {
					this->data[j] = this->data[j + 1];
				}
				this->used--;
				break;
			}
		}

		return result;
	}

	T& remove_location(size_t index) {
		// precondition: used > 0 && index < size()
		// postcondition: remove one Entry equal to location of index 
		assert(this->used > 0 && index < size());

		T result = this->data[index];
		for (int i = index; i < this->used - 1; i++) {
			this->data[i] = this->data[i + 1];
		}
		this->used--;

		return result;
	}

	ArrayList<T> operator +(const ArrayList<T>& operand) {
		ArrayList<T> result(this->size() + operand.size());
		result += *this;
		result += operand;

		return result;
	}

	void operator +=(const ArrayList<T>& addend) {
		if (this->used + addend.size() > this->capacity) {
			this->reserve(this->used + addend.size());
		}

		std::copy(addend.data, addend.data + addend.size(), this->data + this->used);
		this->used += addend.size();
	}

	size_t size() const {
	// postcondition: return used 
		return this->used;
	}

	size_t occurences(T target) const {
	// postcondition: retunr num of target number in data 
		size_t n = 0;
		for (int i = 0; i < this->used; i++) {
			if (this->data[i] == target) {
				n++;
			}
		}

		return n;
	}

	T& locate(size_t index) {
		assert(this->used >= index);
		return this->data[index];
	}

	bool empty() {
		return this->used == 0;
	}

	bool full() {
		return used == capacity;
	}

	void print() const {
	// postcondition: print list data
		for (size_t i = 0; i < this->used; i++) {
			std::cout << this->data[i] << " ";
		}
		printf("\n");
	}

private:
	T* data;
	size_t used = 0;
	size_t capacity;
};