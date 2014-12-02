#include "doubly_linked_list.h"
#include <iostream>

using namespace std;


// write this code to decide if a node is in a circularly linked list
bool circular_list_simple(node* some_ptr)
{
	return false;
}


// write this code to decide if a node is in a circularly linked list
bool circular_list_smarter(node* some_ptr)
{
	return false;
}

int main()
{
	node* some_node = nullptr;
	
	if (circular_list_simple(some_node))
		cout << "Empty lists aren't circular!" << endl;
	else
		cout << "OK for empty list" << endl;
	
	some_node = new node;
	some_node->data = 3;
	some_node->next = some_node;
	some_node->prev = some_node;
	if (circular_list_simple(some_node))
		cout << "Correct answer; list is circular!" << endl;
	else
		cout << "Wrong answer; list is circular" << endl;
	delete_circular(some_node);
	
	some_node = new node;
	some_node->data = 3;
	some_node->next = nullptr;
	some_node->prev = nullptr;
	if (circular_list_simple(some_node))
		cout << "Wrong answer; list is not circular!" << endl;
	else
		cout << "Correct answer; list is not circular" << endl;
	clear_list(some_node, some_node);
	
	some_node = secret_list1();
	if (circular_list_simple(some_node))
		cout << "Correct answer; list is circular!" << endl;
	else
		cout << "Wrong answer; list is circular" << endl;
	delete_circular(some_node);
	
	some_node = secret_list2();
	if (circular_list_simple(some_node))
		cout << "Correct answer; list is circular!" << endl;
	else
		cout << "Wrong answer; list is circular" << endl;
	delete_circular(some_node);
	
	some_node = secret_list3();
	if (circular_list_simple(some_node))
		cout << "Wrong answer; list is not circular" << endl;
	else
		cout << "Correct answer; list is not circular" << endl;
	clear_list(some_node, some_node);
	
	some_node = secret_list4();
	if (circular_list_simple(some_node))
		cout << "Wrong answer; list is not circular" << endl;
	else
		cout << "Correct answer; list is not circular" << endl;
	clear_list(some_node, some_node);
	
	some_node = nullptr;
	
	if (circular_list_smarter(some_node))
		cout << "Empty lists aren't circular!" << endl;
	else
		cout << "OK for empty list" << endl;
	
	some_node = new node;
	some_node->data = 3;
	some_node->next = some_node;
	some_node->prev = some_node;
	if (circular_list_simple(some_node))
		cout << "Correct answer; list is circular!" << endl;
	else
		cout << "Wrong answer; list is circular" << endl;
	delete_circular(some_node);
	
	some_node = new node;
	some_node->data = 3;
	some_node->next = nullptr;
	some_node->prev = nullptr;
	if (circular_list_simple(some_node))
		cout << "Wrong answer; list is not circular!" << endl;
	else
		cout << "Correct answer; list is not circular" << endl;
	clear_list(some_node, some_node);
	
	some_node = secret_list1();
	if (circular_list_smarter(some_node))
		cout << "Correct answer; list is circular!" << endl;
	else
		cout << "Wrong answer; list is circular" << endl;
	delete_circular(some_node);
	
	some_node = secret_list2();
	if (circular_list_smarter(some_node))
		cout << "Correct answer; list is circular!" << endl;
	else
		cout << "Wrong answer; list is circular" << endl;
	delete_circular(some_node);
	
	some_node = secret_list3();
	if (circular_list_smarter(some_node))
		cout << "Wrong answer; list is not circular" << endl;
	else
		cout << "Correct answer; list is not circular" << endl;
	clear_list(some_node, some_node);
	
	some_node = secret_list4();
	if (circular_list_smarter(some_node))
		cout << "Wrong answer; list is not circular" << endl;
	else
		cout << "Correct answer; list is not circular" << endl;
	clear_list(some_node, some_node);
	
	
	
}
