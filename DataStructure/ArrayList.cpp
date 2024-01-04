#include "ArrayList.hpp"
#include <iostream>
#include <algorithm>
#include <cassert>

template <typename T>
ArrayList<T>::ArrayList(size_t capacity) {
	this->data = new T[capacity];
	this->capacity = capacity;
	this->used = 0;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& source) {
	this->data = new T[source.capacity];
	this->capacity = source.capacity;
	this->used = source.used;
	std::copy(source.data, source.data + source.used, this->data);
}

template <typename T>
 ArrayList<T>::~ArrayList() {
	delete[] this->data;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator =(const ArrayList<T>& source) {
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

template <typename T>
void ArrayList<T>::reserve(size_t new_capacity) {
	if (this->capacity == new_capacity) return;
	if (new_capacity < this->used) new_capacity = this->used;

	T* larger_data = new T[new_capacity];
	std::copy(this->data, this->data + used, larger_data);
	delete[] this->data;
	this->data = larger_data;
	this->capacity = new_capacity;
}

template <typename T>
 void ArrayList<T>::insert(T newEntry) {
	 if (this->used == this->capacity) {
		 this->reserve(used + 1);
	 }
	
	data[this->used++] = newEntry;
}

template <typename T>
void ArrayList<T>::remove(T target) {
	assert(this->used > 0);

	for (int i = 0; i < this->used; i++) {
		if (this->data[i] == target) {
			this->data[i] = this->data[--this->used];
			break;
		}
	}
}

template <typename T>
ArrayList<T> ArrayList<T>::operator+ (const ArrayList<T>& operand) {
	ArrayList<T> result(this->size() + operand.size());
	result += *this;
	result += operand;

	return result;
}

template <typename T>
void ArrayList<T>::operator +=(const ArrayList<T>& addend) {
	if (this->used + addend.size() > this->capacity) {
		this->reserve(this->used + addend.size());
	}

	std::copy(addend.data, addend.data + addend.size(), this->data + this->used);
	this->used += addend.size();
}

template <typename T>
size_t ArrayList<T>::size() const {
	return this->used;
}

template <typename T>
void ArrayList<T>::print() const{
	for(size_t i = 0; i < this->used; i++) {
		std::cout << this->data[i] << " ";
	}
	printf("\n");
}

template <typename T>
size_t ArrayList<T>::occurences(T target) const {
	size_t n = 0;
	for (int i = 0; i < this->used; i++) {
		if (this->data[i] == target) {
			n++;
		}
	}

	return n;
}
