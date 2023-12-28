#include "ArrayList.hpp"
#include <iostream>
#include <algorithm>
#include <cassert>

template <typename T>
 void ArrayList<T>::insert(T newEntry) {
	assert(used < CAPACITY);
	
	data[used++] = newEntry;
}

template <typename T>
void ArrayList<T>::remove(T target) {
	assert(used > 0);

	for (int i = 0; i < used; i++) {
		if (data[i] == target) {
			data[i] = data[--used];
			break;
		}
	}
}

template <typename T>
void ArrayList<T>::operator +=(const ArrayList<T>& addend) {
	assert(used + addend.size() <= CAPACITY);

	std::copy(addend.data, addend.data + addend.size(), data + used);
	this->used += addend.size();
}

template <typename T>
size_t ArrayList<T>::size() const {
	return this->used;
}

template <typename T>
void ArrayList<T>::print() const{
	for(size_t i = 0; i < used; i++) {
		std::cout << data[i] << " ";
	}
	printf("\n");
}

template <typename T>
size_t ArrayList<T>::occurences(T target) const {
	size_t n = 0;
	for (int i = 0; i < used; i++) {
		if (data[i] == target) {
			n++;
		}
	}

	return n;
}
