#pragma once
#include <cassert>
#include <iostream>

template <class RecordType>
class HashTable {

public:
	HashTable() {
		for (size_t i = 0; i < CAPACITY; i++) {
			data[i].key = NEVER_USED;
		}
		used = 0;
	}

	void insert(const RecordType& entry) {
		bool already_present;
		size_t index;
		assert(entry.key >= 0);

		find_index(entry.key, already_present, index);

		if (!already_present) {
			assert(size() < CAPACITY);
			index = hash(entry.key);
			while (!is_vacant(index)) {
				index++;
			}
			++used;
		}

		data[index] = entry;
	}

	void remove(int key) {
		bool already_present;
		size_t index;
		assert(key >= 0);

		find_index(key, already_present, index);
		
		if (already_present) {
			data[index].key = PREVIOUSLY_USED;
			used--;
		}
	}

	bool is_present(int key) const {
		return false;
	}

	void find_index(int key, bool& found, size_t& index) const {
		index = hash(key);
		found = false;

		for (; index < CAPACITY; index++) {
			if (data[index].key == key || never_used(index)) {
				found = true;
				return;
			}
		}
	}

	size_t size() const { return used; }

	void print() {
		for (size_t i = 0; i < CAPACITY; i++) {
			if (data[i].key != NEVER_USED && data[i].key != PREVIOUSLY_USED) {
				std::cout << i << ": (" << data[i].key << ", " << data[i].data << ")" << std::endl;
			}
		}

		std::cout << std::endl;
	}

private:
	static const size_t CAPACITY = 200;
	static const int NEVER_USED = -1;
	static const int PREVIOUSLY_USED = -2;
	
	RecordType data[CAPACITY];
	size_t used;
	inline size_t hash(int key) const {
		return key % CAPACITY;
	}
	inline bool never_used(size_t index) const
	{
		return (data[index].key == NEVER_USED);
	}

	inline bool is_vacant(size_t index) const
	{
		return (data[index].key == NEVER_USED) || (data[index].key == PREVIOUSLY_USED);
	}
};