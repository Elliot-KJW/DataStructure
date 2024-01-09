#pragma once
#include "List.hpp"
#include <cstdlib>

class node {
public:
	typedef double value_type;
private:
	value_type data_filed;
	// ���� ��带 ����Ű�� ������
	node* link_filed;

public:
	node(const value_type& init_data = value_type(), const node* init_link = NULL) {
		this->data_filed = init_data;
		this->link_filed = (node*)init_link;
	}
	void set_data(const value_type& new_data);
	void set_link(node* new_link);
	value_type data() const;
	const node* link() const;
	node* link();

};

// ù��° ��带 ����Ŵ
node* head_ptr;
// ������ ��带 ����Ŵ
node* tail_ptr;