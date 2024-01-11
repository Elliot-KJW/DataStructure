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
Node<T>::value_type Node<T>::data() const {
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