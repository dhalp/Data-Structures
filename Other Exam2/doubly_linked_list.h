#include <iostream>

struct node {
	int data;
	node* next;
	node* prev;
};

node* secret_list1();
node* secret_list2();
node* secret_list3();
node* secret_list4();

void delete_circular(node*& head_ptr);

void add_node(node*& head_ptr, node*& tail_ptr, const int& payload);

bool remove_node(node*& head_ptr, node*& tail_ptr, const int& target);

void print_list(const node* head_ptr);

void print_list_backwards (const node* tail_ptr);

bool find_list(const node* head_ptr, const int& target);

void clear_list(node*& head_ptr, node*& tail_ptr);

void copy_list(const node* source_head_ptr,
	node*& dest_head_ptr, node*& dest_tail_ptr);

