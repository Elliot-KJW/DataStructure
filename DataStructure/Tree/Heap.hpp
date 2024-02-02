#include "../List/ArrayList.hpp"

template <typename T>
class Heap {
private:
	ArrayList<T>* data;

public:
	Heap() {
		data = new ArrayList<T>(10);
	}

	void insert(const T target) {
		data->insert(target);
		if (data->size() == 1) return;
		else {
			size_t index = data->size() - 1;
			while (index > 0) {
				size_t parent_index = (index - 1) / 2;

				if (data->locate(parent_index) < target) {
					data->locate(index) = data->locate(parent_index);
					data->locate(parent_index) = target;
					index = parent_index;
				}
				else {
					break;
				}
			}
		}
	}

	T& remove_top() {
		T& remove = data->locate(0);

		if (data->size() == 0) {
			data->remove(remove); 
			return remove;
		}

		data->locate(0) = data->locate(data->size() - 1);
		data->remove_location(data->size() - 1);

		size_t index = 0;
		for (int i = 1; i < data->size(); i++) {
			if (data->locate(index) < data->locate(i)) {
				T temp = data->locate(index);
				data->locate(index) = data->locate(i);
				data->locate(i) = temp;

				index = i;
			}
		}

		return remove;
	}

	void print() {
		data->print();
	}
};