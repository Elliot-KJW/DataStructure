#pragma once

template <typename T>
class ArrayList {
public:
	ArrayList();
	void insert(T newEntry);
	// precondition: used < CAPACITY
	// postcondition: new Entry inserted in list

	void remove(T target);
	// precondition: used > 0
	// postcondition: remove one Entry equal to target 

	void operator +=(const ArrayList<T>& addend);

	size_t size() const;
	// postcondition: return used 

	size_t occurences(T target) const;
	// postcondition: retunr num of target number in data 

	void print() const;
	// postcondition: print list data
public:
	static const size_t CAPACITY = 20;

private:
	T data[CAPACITY];
	size_t used;
};