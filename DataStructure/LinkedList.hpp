#include "Node.cpp"
#include "List.hpp"

template <typename T>
class LinkedList : List<T> {
private:
	Node<T>* head_ptr;
	// ������ ��带 ����Ŵ
	Node<T>* tail_ptr;
};
