#pragma once
#include <cstdlib>
#include <cassert>

template <typename T>
class Node {
public:
	typedef T value_type;
private:
	value_type data_filed;
	// 다음 노드를 가리키는 포인터
	Node* link_filed;

public:
	Node(const value_type& init_data = value_type(), const Node* init_link = NULL) {
		this->data_filed = init_data;
		this->link_filed = (Node*)init_link;
	}

	void set_data(const value_type& new_data) {
		this->data_filed = new_data;
	}

	void set_link(Node* new_link) {
		this->link_filed = new_link;
	}

	const value_type data() const {
		return this->data_filed;
	}

	value_type data() {
		return this->data_filed;
	}

	const Node* link() const {
	// cannot change value of return node
		return this->link_filed;
	}

	Node* link() {
	// can change value of return node
		return this->link_filed;
	}
};

template <typename T>
size_t list_length(const Node<T>* head_ptr) {
// return numbers of nodes in a linked list
	size_t answer = 0;
	const Node<T>* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link) {
		answer++;
	}

	return answer;
}

template <typename T>
void list_head_insert(Node<T>*& head_ptr, const typename Node<T>::value_type& entry) {
// insert new node at front of list
	head_ptr = new Node<T>(entry, head_ptr);
}

template <typename T>
void list_insert(Node<T>* previous_ptr, const typename Node<T>::value_type& entry) {
// insert new node at rear of node
	previous_ptr->set_link(new Node<T>(entry, previous_ptr->link()));
}

template <typename T>
Node<T>* list_search(Node<T>* head_ptr, const typename Node<T>::value_type& target) {
// return a Node pointer to the first Node that contains target or NULL
	Node<T>* cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link()) {
		if (cursor->data() == target)
			return cursor;
	}

	return NULL;
}

template <typename T>
const Node<T>* list_search(const Node<T>* head_ptr, const typename Node<T>::value_type& target) {
// return a Node pointer to the first Node that contains target or NULL
	Node<T>* cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link()) {
		if (cursor->data() == target)
			return cursor;
	}

	return NULL;
}

template <typename T>
Node<T>* list_locate(Node<T>* head_ptr, size_t position) {
// precondition position >= 0
// Find a node by its position in a linked list and if found, return a pointer to the node
	assert(position >= 0);

	Node<T>* cursor = head_ptr;

	for (size_t i = 0; cursor != NULL && i < position; i++) {
		cursor = cursor->link();
	}

	return cursor;
}

template <typename T>
const Node<T>* list_locate(const Node<T>* head_ptr, size_t position) {
// precondition position >= 0
// Find a node by its position in a linked list and if found, return a pointer to the node
	assert(position >= 0);

	Node* cursor;

	for (size_t i = 0, cursor = head_ptr; cursor != NULL && i < position; i++) {
		cursor = cursor->link();
	}

	return cursor;
}

template <typename T>
void list_copy(const Node<T>* source_ptr, Node<T>*& head_ptr, Node<T>*& tail_ptr) {
// return copied list of source
	if (source_ptr == NULL) return;

	head_ptr = NULL;
	tail_ptr = NULL;

	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;

	for (source_ptr = source_ptr->link(); source_ptr != NULL; source_ptr = source_ptr->link()) {
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->link();
	}
}

template <typename T>
void list_head_remove(Node<T>*& head_ptr) {
	Node<T>* remove_ptr = head_ptr;

	head_ptr = remove_ptr->link();
	delete remove_ptr;
}

template <typename T>
void list_remove(Node<T>* previous_ptr) {
// remove next node of previous_ptr
	Node<T>* remove_ptr = previous_ptr->link();
	previous_ptr->set_link(remove_ptr->link());
	delete remove_ptr;
}

template <typename T>
void list_clear(Node<T>*& head_ptr) {
// remove all nodes of list and make empty list
	while (head_ptr != NULL)
		list_head_remove(head_ptr);
}