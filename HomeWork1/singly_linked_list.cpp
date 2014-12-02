#include "singly_linked_list.h"

using namespace std;

void add_node(node*& head_ptr, const int& payload)
{
	if (head_ptr == nullptr)
	{
		node* temp = new node;
		temp -> data = payload;
		temp -> next = nullptr;
		head_ptr = temp;
		return;
	}
	else if (payload <= head_ptr->data)
	{
                node* temp = new node;
                temp -> data = payload;
                temp -> next = head_ptr;
                head_ptr = temp;
                return;
	}
	else
	{
	/*	while (payload <= const node*& head_ptr)
		{
	                node* temp = new node;
               		temp -> data = payload;
               		temp -> next = nullptr;
                	head_ptr = temp;
                	return; */
		node* cursor = head_ptr;
 	        while (cursor -> next != nullptr)
       		{
    //			if (cursor -> next == nullptr) cout<<"YourFucked";
			if ((cursor->next)->data <= payload) cursor = (cursor-> next);
//			if (cursor == nullptr) cout<<"YOUFUCKEDUP";
		/*	{
				node* temp = new node;
				temp -> data = payload;
				temp -> next = nullptr;
				cursor -> next = temp;
				return;
			}
		*/	else
			{
				node* temp = new node;
				temp -> data = payload;
				temp -> next = cursor->next;
				cursor -> next = temp;
				return;
			}
		}
	//	if (cursor == nullptr)
	
			node* temp = new node;
			temp -> data = payload;
			temp -> next = nullptr;
			cursor -> next = temp;
		//	return;
	//	}
	}
/*		node* temp = new node;
		temp -> data = payload;
		temp -> next = head_ptr;
		head_ptr = temp;
         cout << endl;
*//*	//SUDO KODE
	if (The List is EMPTY)
	{
		node.data=payload
		node->next = head_ptr;
		head_ptr = 
		Create New Node 
			payload to nullptr
			head_ptr tonew noad
	
	}
*/
}

bool remove_node(node*& head_ptr, const int& target)
{	

	if (target == head_ptr -> data)
	{
		node* cursor = head_ptr;
		head_ptr = cursor -> next;
		delete cursor;
		return true;
	}

	node* cursor = head_ptr;
	while (cursor -> next != nullptr)
	{
		if (target == (cursor -> next) -> data)
		{
			node* temp = cursor -> next;
			cursor -> next = temp->next;
			delete temp;
			return true;
		}
		cursor = cursor->next;
		if (nullptr == cursor -> next)
		{
			cout<<"YouPutSomeShitInThatAintThere"<<endl;
			return false;
		}
	}
	return false;
}

bool find_list(const node*& head_ptr, const int& target)
{
	const node* cursor = head_ptr;
	while (cursor != nullptr)
	{

		if (cursor -> data == target)
			{
			//	cout<<"yourOK";
				return true;
			}
		cursor = cursor -> next;
		//else cout << "it aint here yet";
	}
	return false;
}

void clear_list(node*& head_ptr)
{
	if(head_ptr == nullptr) return;

	clear_list(head_ptr -> next);
	delete head_ptr;
	head_ptr = nullptr;
	return;
}

void print_list(const node*& head_ptr)
{
	const node* cursor = head_ptr;
	while (cursor != nullptr)
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

void copy_list(const node*& source_ptr, node*& dest_ptr)
{
	clear_list(dest_ptr);
	const node* cursor = source_ptr;
	while (cursor != nullptr)
	{
		add_node(dest_ptr,cursor->data);
		cursor = cursor -> next;
	}

}

