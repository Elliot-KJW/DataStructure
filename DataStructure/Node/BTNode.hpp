#pragma once
#include <cstdlib>
#include <iomanip>
#include <iostream>

template <typename T>
class BTNode {
private:
	T data_field;
	BTNode* left_field;
	BTNode* right_field;

public:
	BTNode(const T& init_data = T(),
		BTNode* init_left = NULL,
		BTNode* init_right = NULL) {
		this->data_field = init_data;
		this->left_field = init_left;
		this->right_field = init_right;
	}

	T& data() {
		return this->data_field;
	}

	const T& data() const {
		return this->data_field;
	}

	BTNode*& left() {
		return this->left_field;
	}

	const BTNode* left() const {
		return this->left_field;
	}

	BTNode*& right() {
		return this->right_field;
	}

	const BTNode* right() const {
		return this->right_field;
	}

	void set_data(const T& new_data) {
		this->data_field = new_data;
	}


	void set_left(BTNode* new_left) {
		this->left_field = new_left;
	}

	void set_right(BTNode* new_right) {
		this->right_field = new_right;
	}

	bool is_left() const {
		return this->left_field == NULL && this->right_field == NULL;
	}
};

template <typename T>
void tree_clear(BTNode<T>*& root_ptr) {
	if (root_ptr != NULL) {
		tree_clear(root_ptr->left());
		tree_clear(root_ptr->right());
		delete root_ptr;
		root_ptr = NULL;
	}
}

template <typename T>
BTNode<T>* tree_copy(BTNode<T>* root_ptr) {
	BTNode<T>* l_ptr;
	BTNode<T>* r_ptr;

	if (root_ptr == NULL)
		return NULL;
	else {
		l_ptr = tree_copy(root_ptr->left());
		r_ptr = tree_copy(root_ptr->right());
		return new BTNode<T>(root_ptr->data(), l_ptr, r_ptr);
	}
}

template <typename Process, typename T>
void preorder(Process f, const BTNode<T>* root_ptr) {
	if (root_ptr != NULL) {
		f(root_ptr->data());
		preorder(f, root_ptr->left());
		preorde(f, root_ptr->right());
	}
}

template <typename Process, typename T>
void inorder(Process f, const BTNode<T>* root_ptr) {
	if (root_ptr != NULL) {
		inorder(f, root_ptr->left());
		f(root_ptr->data());
		inorder(f, root_ptr->right());
	}
}

template <typename Process, typename T>
void postorder(Process f, const BTNode<T>* root_ptr) {
	if (root_ptr != NULL) {
		postorder(f, root_ptr->left());
		postorder(f, root_ptr->right());
		f(root_ptr->data());
	}
}

template <typename T, typename SizeType>
void tree_print(const BTNode<T>* root_ptr, SizeType depth) {
	//printing the nodes in a tree-like (90` rotated) form

	if (root_ptr != NULL) {
		tree_print(root_ptr->right(), depth + 1);
		std::cout << std::setw(4 * depth) << "" << root_ptr->data() << std::endl;
		tree_print(root_ptr->left(), depth + 1);
	}
}

template <typename T>
void bst_remove(BTNode<T>*& root_ptr, const T& target) {
	if (root_ptr == NULL) return;

	if (target < root_ptr->data()) {
		bst_remove(root_ptr->left(), target);
	}
	else if (target > root_ptr->data()) {
		bst_remove(root_ptr->right(), target);
	}
	else {
		if (root_ptr->left() == NULL) {
			BTNode<T>* oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right();
			delete oldroot_ptr;
		}
		else {
			bst_remove_max(root_ptr->left(), root_ptr->data());
		}
	}
}

template <typename T>
void bst_remove_max(BTNode<T>*& root_ptr, T& removed) {
	if (root_ptr->right() == NULL) {
		removed = root_ptr->data();
		BTNode<T>* oldroot_ptr = root_ptr;
		root_ptr = root_ptr->left();
		delete oldroot_ptr;
	}
	else {
		bst_remove_max(root_ptr->right(), removed);
	}
}

template <typename T>
size_t tree_count(BTNode<T>*& root_ptr, const T& target) {
	if (root_ptr != NULL) {
		size_t result = root_ptr->data() == target ? 1 : 0;
		return result + tree_count(root_ptr->left(), target) + tree_count(root_ptr->right(), target);
	}
	else return 0;
}