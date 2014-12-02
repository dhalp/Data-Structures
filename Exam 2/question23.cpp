#include "bintree.h"
#include "binary_search_tree.h"
#include <iostream>

using namespace std;

int tree_min_recursive(const binary_tree_node* root_ptr)
{
    binary_tree_node* cnode = root_ptr;
	while (cnode -> left != NULL){
        cnode = cnode->left;
    }
    cout << "min number: " << cnode->data << endl;    
    return 0;	
}

int tree_max_recursive(const binary_tree_node* root_ptr)
{
	return 0;	
}

int main()
{
	binary_tree_node* root_ptr1 = nullptr;
	insert(root_ptr1, 6);  
	
	cout << "Single node tree " << endl;
	
	print(root_ptr1, 0);
	
	cout << "Min of single node tree " << tree_min_recursive(root_ptr1) << endl;
	cout << "Max of single node tree " << tree_max_recursive(root_ptr1) << endl;
	
	for (unsigned int k = 0; k < 20; ++k)
	{
		int number = rand() % 100;
		insert(root_ptr1, number);
	}
	
	print(root_ptr1, 0);
	
	cout << "Min of random tree " << tree_min_recursive(root_ptr1) << endl;
	cout << "Max of random tree " << tree_max_recursive(root_ptr1) << endl;
	
	tree_clear(root_ptr1);
	
	for (unsigned int k = 0; k < 10; ++k)
	{
		int number;
		cout << "Enter a number: ";
		cin >> number;
		insert(root_ptr1, number);
	}

	print(root_ptr1, 0);
	
	cout << "Min of manually entered tree " << tree_min_recursive(root_ptr1) << endl;
	cout << "Max of manually entered tree " << tree_max_recursive(root_ptr1) << endl;

	tree_clear(root_ptr1);			
}
