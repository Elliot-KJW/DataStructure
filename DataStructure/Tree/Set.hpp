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

	bool erase(const T& target) {
		if (!loose_erase(target)) {
			return false;
		}
		else if (data_count == 0 && child_count == 1) {
			*this = *subset[0];
		}
		return true;
	}

	void print(size_t depth) {
		if (child_count > 0) {
			for (size_t i = child_count - 1; i >= child_count / 2; i--) {
				subset[i]->print(depth + 1);
			}
		}

		std::cout << std::setw(MAXIMUM * depth * 6) << "[";
		for (int i = 0; i < data_count - 1; i++) {
			std::cout << data[i] << ", ";
		}
		std::cout << data[data_count - 1] << "]" << std::endl;

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
			if (i == data_count || (data[i] > entry && !is_leaf())) {
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

	bool loose_erase(const T& target) {
		for (int i = 0; i <= data_count; i++) {
			if (is_leaf()) {
				if (i == data_count) {
					return false;
				}
				else if (data[i] == target) {
					for (int j = i; j < data_count - 1; j++) {
						data[i] = data[i + 1];
					}
					data_count--;
					return true;
				}
			}
			else {
				if (data[i] == target) {
					subset[i]->remove_biggest(data[i]);
					if (subset[i]->data_count < MININUM) {
						fix_shortage(i);
					}
					return true;
				}
				else {
					subset[i]->loose_erase(target);
					if (subset[i]->data_count < MININUM) {
						fix_shortage(i);
					}
					return false;
				}
			}
			return false;
		}
	}
	void fix_shortage(size_t i) {
		if (i == 0) {
			if (subset[i + 1]->data_count > MININUM) {
				subset[i]->data[data_count++] = data[i];
				data[i] = subset[i + 1]->data[0];

				for (int i = 0; i < subset[i + 1]->data_count - 1; i++) {
					subset[i + 1]->data[i] = subset[i + 1]->data[i + 1];

				}
				subset[i + 1]->child_count--;

				if (!subset[i + 1]->is_leaf()) {
					subset[i]->subset[subset[i]->child_count++] = subset[i + 1];
					subset[i + 1]->data_count--;
					for (int i = 0; i < subset[i + 1]->data_count - 1; i++) {
						subset[i + 1]->subset[i] = subset[i + 1]->subset[i + 1];
					}
				}
			}
			else {

			}
		} else if (i < data_count) {
			if (subset[i - 1]->data_count > MININUM) {

			}
			else {

			}
		}
	}
	void remove_biggest(T& removed_entry) {
	}
};