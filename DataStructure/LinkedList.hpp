#include "Node.cpp"
#include "List.hpp"

template <typename T>
class LinkedList : List<T> {
private:
	Node<T>* head_ptr;
	// 마지막 노드를 가리킴
	Node<T>* tail_ptr;
};
