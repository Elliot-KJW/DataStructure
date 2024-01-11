#pragma once
#include <cstdlib>

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
	void set_data(const value_type& new_data);
	void set_link(Node* new_link);
	value_type data() const;

	const Node* link() const;
	// cannot change value of return node

	Node* link();
	// can change value of return node
};

template <typename T>
size_t list_length(const Node<T>* head_ptr);
// return numbers of nodes in a linked list

template <typename T>
void list_head_insert(Node<T>*& head_ptr, typename Node<T>::value_type& entry);
// insert new node at front of list

template <typename T>
void list_insert(Node<T>* previous_ptr, const typename Node<T>::value_type& entry);
// insert new node at rear of node

template <typename T>
Node<T>* list_search(Node<T>* head_ptr, const typename Node<T>::value_type& target);
// return a Node pointer to the first Node that contains target or NULL

template <typename T>
const Node<T>* list_search(const Node<T>* head_ptr, const typename Node<T>::value_type& target);
// return a Node pointer to the first Node that contains target or NULL

template <typename T>
Node<T>* list_locate(Node<T>* head_ptr, size_t position);
// precondition position >= 0
// Find a node by its position in a linked list and if found, return a pointer to the node

template <typename T>
const Node<T>* list_locate(const Node<T>* head_ptr, size_t position);
// precondition position >= 0
// Find a node by its position in a linked list and if found, return a pointer to the node

template <typename T>
void list_copy(const Node<T>* source_ptr, Node<T>*& head_ptr, Node<T>*& tail_ptr);
// return copied list of source

template <typename T>
void list_head_remove(Node<T>*& head_ptr);

template <typename T>
void list_remove(Node<T>* previous_ptr);
// remove next node of previous_ptr

template <typename T>
void list_clear(Node<T>*& head_ptr);
// remove all nodes of list and make empty list