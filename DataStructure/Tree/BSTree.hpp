#include "../Node/BTNode.hpp"

template <typename T>
class BSTree {
private:
	BTNode<T>* root_ptr;
public:
	BSTree() {
		root_ptr = NULL;
	}

	BSTree(const BSTree<T>& source) {
		root_ptr = tree_copy(source);
	}

	~BSTree() {
		tree_clear(root_ptr);
	}

	size_t size() const {
		if (root_ptr == NULL) {
			return 0;
		}

		BSTree<T>* left_subtree(root_ptr->left());
		BSTree<T>* right_subtree(root_ptr->right());

		return 1 + left_subtree->size() + right_subtree->size();
	}

	BSTree<T>& operator =(const BSTree<T>& source) {
		if (&source == this) {
			return;
		}
		
		tree_clear(this->root_ptr);
		this->root_ptr = tree_copy(source.root_ptr);

		return *this;
	}

	void insert(T target) {
		if (root_ptr == NULL) {
			root_ptr = new BTNode<T>(target);
			return;
		} else {
			BTNode<T>* compare_node = root_ptr;

			while (true) {
				if (target <= compare_node->data()) {
					if (compare_node->left() == NULL) {
						compare_node->set_left(new BTNode<T>(target));
						return;
					}
					else {
						compare_node = compare_node->left();
					}
				}
				else {
					if (compare_node->right() == NULL) {
						compare_node->set_right(new BTNode<T>(target));
						return;
					}
					else {
						compare_node = compare_node->right();
					}
				}
			}
		}
	}

	void erase_one(T target) {
		bst_remove(root_ptr, target);
	}

	void print(size_t depth) {
		tree_print(root_ptr, depth);
		if (root_ptr != NULL) {
			std::cout << "----------------------------------------------------------------------" << std::endl;
		}
	}

	void clear() {
		tree_clear(root_ptr);
	}


	void insert_all(const BTNode<T>* tree_ptr) {
		if (tree_ptr != NULL) {
			insert(tree_ptr->data());
			insert_all(tree_ptr->left());
			insert_all(tree_ptr->right());
		}
	}

	void operator +=(const BSTree<T>& addend) {
		if (this == &addend) {
			BTNode<T>* copy = tree_copy(addend.root_ptr);
			insert_all(copy);
			tree_clear(copy);
		}
		else {
			insert_all(addend.root_ptr);
		}
	}

	size_t count(const T& target) {
		return tree_count(root_ptr, target);
	}
};