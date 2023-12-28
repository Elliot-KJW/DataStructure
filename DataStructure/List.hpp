#pragma once

template <typename T>
class List {
public:
	virtual void insert(T newEntry) = 0;
	// precondition: used < CAPACITY
	// postcondition: new Entry inserted in list

	virtual void remove(T target) = 0;
	// precondition: used > 0
	// postcondition: remove one Entry equal to target 

	virtual size_t size() const = 0;
	// postcondition: return used 

	virtual size_t occurences(T target) const = 0;
	// postcondition: retunr num of target number in data 

	virtual void print() const = 0;
	// postcondition: print list data
};