#pragma once

template <typename T>
class ArrayList {
public:
	ArrayList();
	void insert(T newEntry);
	// precondition: used < CAPACITY
	// postcondition: new Entry inserted in list
	void remove(T target);
	size_t size() const;
	// postcondition: return used 
	size_t occurences(T target) const;

public:
	static const size_t CAPACITY = 20;

private:
	T data[CAPACITY];
	size_t used;
};