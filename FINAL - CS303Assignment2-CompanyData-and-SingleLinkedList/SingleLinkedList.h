#pragma once
#include <iostream>

using namespace std;


/*Build a Single_Linked_List class. Your class should have the data members: head, tail,
and num_items. Write the following member functions, which perform the same operations as the
corresponding functions in the standard list class:
• size_t find(const Item_Type& item): Return the position of the first occurrence of item if it is
found. Return the size of the list if it is not found.*/

class singleLinkedList {
	public:

		void list();									//initializer class
		void display();									//displays the list

		void push_front(const int value);				//adds a node to the front of the list
		void push_back(const int value);				//adds a node to the end of the list
		void pop_front();								//deletes the node at the front of the list
		void pop_back();								//deletes the node at the back of the list
		const int front() const;						//returns the value of the node at the front of the list
		const int back() const;							//returns the value of the node of the back of the list
		bool empty();									//returns true if the list is empty
		void insert(size_t index, const int item);		//inserts a node at the index using the given value
		bool remove(size_t index);						//removes a node at an index
		size_t find(const int item);					//finds an item in the list


	private:
		struct node {
			int item;
			size_t index;
			node* next;
		};

		node * head, * tail;
		int num_items;
};
