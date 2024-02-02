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
		*this = source;
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
		else if (data_count > MAXIMUM) {
			Set<T> new_root;
			new_root.subset[new_root.child_count++] = new Set<T>(*this);

			*this = new_root;

			fix_excess(0);
		}
		return true;
	}

	void print(size_t depth) {
		if (child_count > 0) {
			for (size_t i = child_count - 1; i > child_count / 2; i--) {
				subset[i]->print(depth + 1);
			}
		}

		std::cout << std::setw(MAXIMUM * depth * 6) << "[";
		for (int i = 0; i < data_count - 1; i++) {
			std::cout << data[i] << ", ";
		}
		std::cout << data[data_count - 1] << "]";

		if (child_count > 0) {
			size_t subset_datacount = subset[child_count / 2]->data_count;

			std::cout << std::setw(MAXIMUM * 2 + 1) << "[";
			for (int i = 0; i < subset_datacount - 1; i++) {
				std::cout << subset[child_count / 2]->data[i] << ", ";
			}
			std::cout << subset[child_count / 2]->data[subset_datacount - 1] << "]";
		}
		std::cout << std::endl;

		for (int i = 0; i < child_count / 2; i++) {
			subset[i]->print(depth + 1);
		}
	}

	Set<T>& operator =(const Set<T>& source) {
		if (this == &source) return *this;

		this->data_count = source.data_count;
		this->child_count = source.child_count;
		std::copy(source.data, source.data + source.MAXIMUM + 1, this->data);
		for (size_t i = 0; i < this->child_count; i++) {
			this->subset[i] = new Set<T>(*(source.subset[i]));
		}

		return *this;
	}

private:
	static const size_t MININUM = 1;
	static const size_t MAXIMUM = 2 * MININUM;
	size_t data_count;
	T data[MAXIMUM + 1];
	size_t child_count;
	Set<T>* subset[MAXIMUM + 2];
	bool is_leaf() const { return (child_count == 0); }
	bool loose_insert(const T& entry) {
		for (int i = 0; i <= data_count; i++) {
			if (i == data_count) {
				if (is_leaf()) {
					data[i] = entry;
					data_count++;
					return true;
				}
				else {
					bool b = subset[i]->loose_insert(entry);
					if (subset[i]->data_count > MAXIMUM) {
						fix_excess(i);
					}
					return b;
				}
			}

			if (data[i] == entry) {
				return false;
			}
			else if (data[i] > entry && is_leaf()) {
				for (size_t j = data_count; j > i; j--) {
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
		for (size_t j = child_count; j > i; j--) {
			subset[j + 1] = subset[j];
		}

		data[data_count++] = subset[i]->data[MININUM];
		subset[i + 1] = new Set<T>();
		for (size_t j = 0; j < MININUM; j++) {
			subset[i + 1]->data[j] = subset[i]->data[MININUM + j + 1];
		}
		subset[i]->data_count = MININUM;
		subset[i + 1]->data_count = MININUM;
		child_count++;
	}
};