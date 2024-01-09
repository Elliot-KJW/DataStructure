#pragma once
#include "List.hpp"
#include <cstdlib>

class node {
public:
	typedef double value_type;
private:
	value_type data_filed;
	// 다음 노드를 가리키는 포인터
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

// 첫번째 노드를 가리킴
node* head_ptr;
// 마지막 노드를 가리킴
node* tail_ptr;