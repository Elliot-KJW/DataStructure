#include "Node.hpp"

template <typename T>
Node<T>* Node<T>::link() {
	return this->link_filed;
}

template <typename T>
const Node<T>* Node<T>::link() const{
	return this->link_filed;
}

template <typename T>
void Node<T>::set_data(const value_type& new_data) {
	this->data_filed = new_data;
}

template <typename T>
void Node<T>::set_link(Node* new_link) {
	this->link_filed = new_link;
}

template <typename T>
typename Node<T>::value_type Node<T>::data() const {
	return this->data_filed;
}

template <typename T>
size_t list_length(const Node<T>* head_ptr) {
	size_t answer = 0;
	const Node<T>* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link) {
		answer++;
	}

	return answer;
}

template <typename T>
void list_head_insert(Node<T>*& head_ptr, typename Node<T>::value_type& entry) {
	head_ptr = new Node<T>(entry, head_ptr);
}

template <typename T>
void list_insert(Node<T>* previous_ptr, const typename Node<T>::value_type& entry) {
	previous_ptr->set_link(new Node<T>(entry, previous_ptr->link()));
}

template <typename T>
Node<T>* list_search(Node<T>* head_ptr, const typename Node<T>::value_type& target) {
	Node<T>* cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link()) {
		if (cursor->data() == target)
			return cursor;
	}

	return NULL;
}

template <typename T>
const Node<T>* list_search(const Node<T>* head_ptr, const typename Node<T>::value_type& target) {
	Node<T>* cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link()) {
		if (cursor->data() == target)
			return cursor;
	}

	return NULL;
}

template <typename T>
const Node<T>* list_locate(const Node<T>* head_ptr, size_t position) {
	assert(position >= 0);

	Node* cursor;
	
	for (size_t i = 0, cursor = head_ptr; cursor != NULL && i < position; i++) {
		cursor = cursor->link(),
	}

	return cursor;
}

template <typename T>
void list_copy(const Node<T>* source_ptr, Node<T>*& head_ptr, Node<T>*& tail_ptr) {
	if (source_ptr == NULL) return NULL;

	head_ptr = NULL;
	tail_ptr = NULL;
	
	list_head_insert(head_ptr, source_ptr->data);
	tail_ptr = head_ptr;

	for (Node<T>* cursor = source_ptr->link(); cursor != NULL; cursor = cursor->link()) {
		list_insert(tail_ptr, cursor->data);
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
	Node<T>* remove_ptr = previous_ptr->link();
	previous_ptr->set_link(remove_ptr->link());
	delete remove_ptr;
}

template <typename T>
void list_clear(Node<T>*& head_ptr) {
	while (head_ptr != NULL)
		list_head_remove(head_ptr);
}