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
 void ArrayList<T>::insert(T newEntry) {
	assert(this->used < this->capacity);
	
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
void ArrayList<T>::operator +=(const ArrayList<T>& addend) {
	assert(this->used + addend.size() <= this->capacity);

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
