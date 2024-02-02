#pragma once
#include <iostream>
#include <iomanip>

template <typename T>
class Set {
public:
	Set() {
		data_count = 0;
		child_count = 0;
	}

	Set(const Set<T>& source) {
		this->data_count = source.data_count;
		this->child_count = source.child_count;
		std::copy(source.data, source.data + source.data_count, this->data);
		std::copy(source.subset, source.subset + source.child_count, this->subset);
	}

	~Set() {
		for (int i = 0; i < child_count; i++) {
			delete subset[i];
		}
	}

	size_t count(T target) {
		for (int i = 0; i <= data_count; i++) {
			if (i < data_count && data[i] == target) {
				return 1;
			}
			else if(is_leaf()) {
				return 0;
			}
			else {
				return subset[i]->count(target);
			}
		}

	}

	bool insert(const T& entry) {
		if (!loose_insert(entry)) {
			return false;
		}
		else if (data_count > MAXIMUN) {
			Set<T> new_root;
			new_root.subset[0] = new Set<T>(*this);
			*this = new_root;
			fix_excess(0);
		}

		return true;
	}

	void print(size_t depth) {
		for (size_t i = child_count / 2; i < child_count; i++) {
			subset[i]->print(depth+1);
		}

		std::cout << std::setw(4 * depth) << "";
		for (int i = 0; i < data_count; i++) {
			std::cout << data[i] << ", ";
		}

		std::cout << std::endl;
		for (int i = 0; i < child_count / 2; i++) {
			subset[i]->print(depth + 1);
		}
	}

private:
	static const size_t MININUM = 200;
	static const size_t MAXIMUN = 2 * MININUM;
	size_t data_count;
	T data[MAXIMUN + 1];
	size_t child_count;
	Set<T>* subset[MAXIMUN + 2];
	bool is_leaf() const { return (child_count == 0); }
	bool loose_insert(const T& entry) {
		for (int i = 0; i <= data_count; i++) {
			if (i == data_count || data[i] > entry) {
				bool b = subset[i]->loose_insert(entry);
				if (subset[i]->data_count > MAXIMUN) {
					fix_excess(i);
				}
				return b;
			}

			if (data[i] == entry) {
				return false;
			}
			else if (data[i] > entry && is_leaf()) {
				for (size_t j = data_count; j > i; j++) {
					data[j] = data[j - 1];
				}
				data[i] = entry;
				data_count++;
				return true;
			}
		}

		return false;
	}
	void fix_excess(size_t i) {
		for (size_t j = child_count; j > i; j++) {
			subset[j + 1] = subset[j];
		}

		data[data_count++] = subset[i]->data[MININUM];
		Set<T> new_set;
		for (int i = 0; i < MININUM; i++) {
			new_set.data[i] = this->data[MININUM + i];
		}
		this->data_count = MININUM;
		new_set.data_count = MININUM;
		this->subset[i + 1] = &new_set;
	}
};