#include "ArrayList.hpp"
#include <cassert>

template <typename T>
ArrayList<T>::ArrayList() {
	this->used = 0;
}

template <typename T>
void ArrayList<T>::insert(T newEntry) {
	assert(used < CAPACITY);
	
	data[used++] = newEntry;
}

template <typename T>
size_t ArrayList<T>::size() const {
	return this->used;
}