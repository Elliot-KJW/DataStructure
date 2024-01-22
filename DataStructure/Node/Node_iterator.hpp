#pragma once
#include "../Node/Node.hpp"
#include <iostream>

template <typename T>
class Node_iterator : public std::iterator<std::forward_iterator_tag, T> {
private:
	Node<T>* current;
public:
	Node_iterator(Node<T>* initial = NULL) {
		this->current = initial;
	}

	typename Node<T>::type_value& operator*() const {
		return this->current->data();
	}

	Node_iterator& operator++() {
		current = current->link();
		return *this;
	}

	Node_iterator& operator++(int) {
		// ���� ���꿡�� original�� ��������� 
		// �������� ���� link()�� ������ ����ȴ�.
		Node_iterator original(current);
		current = current->link();
		return original();
	}

	bool operator== (const Node_iterator other) const {
		return this->current == other.current;
	}

	bool operator!= (const Node_iterator other) const {
		return this->current != other.current;
	}
};