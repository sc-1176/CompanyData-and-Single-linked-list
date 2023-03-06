#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

//PLEASE NOTE: I got real lazy with naming conventions about halfway through. The notes are more helpful the further down you scroll.

void singleLinkedList::list() {							//initializer class
	head = NULL;
	tail = NULL;
	num_items = -1;										/*Okay this looks weird but I can explain.
														I'm using num_items as a pseudo-index in different parts of the code and to check for an empty list.
														It was easier to set num_items as a negative integer to begin with since an index can be zero in the code
														Thus, this is zero. No reason other than sheer convenience.
														*/
}

void singleLinkedList::display() {						//standard print function with a tab between node values

	node* temp = new node;								//temporary node
	temp = head;										//start at the beginning
	while (temp != NULL)								//break when you hit the end, tail is 'NULL'
	{
			cout << temp->item << "\t";
			temp = temp->next;							//iterate to the next node
	}
	cout << endl << "There are " << num_items+1 << " elements in this list." << endl;
}

void singleLinkedList::push_front(const int value) {	//puts a value at the beginning of the list

	node* newHead = new node;							//declaring a new node that will become the head
	newHead->item = value;								//giving it a variable to hold
	newHead->next = head;								//setting it before the current existing head
	head = newHead;										//setting it as the new head
	num_items += 1;										//noting that an item has been added to the list

}

void singleLinkedList::push_back(const int value) {		//puts a value at the end of the list

	node* tempNode = new node;							//setting up a temporary node to do all of the work to
	tempNode->item = value;								//giving it the user-inputting value that will be added to the list
	tempNode->next = NULL;								//setting it at the end of the list
	if (head == NULL) {									//check to see whether or not the list is empty by checking if there is a previous node
		head = tempNode;								//if the list is empty, set the head as the temporary node
		tail = tempNode;								//same as above, basically making a one-item list
		tempNode = NULL;								//nulling out the old temporary node
	}
	else {
		tail->next = tempNode;							//if not empty, add a 'next node' to the tail and attach the temporary node
		tail = tempNode;								//declare temporary node as the new tail
	}	
	num_items += 1;										//note that an item has been added to the list

}

void singleLinkedList::pop_front() {					//removes the head of the list and establishes the next item in the list as the new head, 'deletion'

	node* temporaryNode = new node;						//create a stand in
	temporaryNode = head;								//the temporary item is the node at the head of the list
	head = head->next;									//declare the new head as being the next item in the list
	delete temporaryNode;								//delete the old head
	num_items -= 1;										//note that an item has been removed from the list

}

void singleLinkedList::pop_back() {						//removes the last item in the list

	node* currentNode = new node;						//establishes a node to work with
	node* previousNode = new node;						//establishes a node so i can work on previous nodes at the same time
	currentNode = head;									//start at the head of the list
	while (currentNode->next != NULL) {					//Check to see if we're at the end of the list
		previousNode = currentNode;						//change the previous node to be the one we're on
		currentNode = currentNode->next;				//iterate the current node to the next node
	}
	tail = previousNode;								//declare the tail to be the 'previous' node, the node behind the current node
	previousNode->next = NULL;							//cut the current node's link to the rest of the list off
	delete currentNode;									//nuke the current node straight into orbit
	num_items -= 1;										//note that an item has been removed

}

const int singleLinkedList::front() const{				//returns the value at the front of the list
	node* tempNode = new node;
	tempNode = head;									//set the temporary node to the top of the list
	cout << tempNode->item << endl;
	return tempNode->item;								//return the item value of the head
}

const int singleLinkedList::back() const {				//returns the value at the back of the list
	node* tempNode = new node;
	tempNode = tail;									//set the temporary node to the end of the list
	cout << tempNode->item << endl;
	return tempNode->item;								//return the item value of the tail
}

bool singleLinkedList::empty() {						//checks to see if a list is empty

	if (num_items < 0) {								//using the num_items established earlier, check to see if anything at all has been added
		cout << "This list is empty." << endl;
		return true;									//if nothing has been added, num_items is still negative, so return true
	}
	else {												//if something has been added
		cout << "This list is not empty." << endl;
		return false;
	}

}

void singleLinkedList::insert(size_t index, const int value)		//inserts at a specific point of the list
{
	node* previous = new node;							//created for iteration - see pop_back for a more detailed explanation
	node* current = new node;							//created for iteration
	node* temporary = new node;							//created for manipulation
	current = head;										//start at the top of the list

		if (index < num_items && index >= 0) {			//num_items is used as an impromptu index for the rest of the list, used here to make sure the index isn't out of bounds
			for (int i = 0; i < index; i++)				//iteration loop to get to the desired index
			{
				previous = current;
				current = current->next;

			}
			temporary->item = value;					//add a value to the temporary node
			previous->next = temporary;					//cut off the old node from the back half of the list by making the previous node point to the temporary node
			temporary->next = current;					//link the temporary node to the rest of the list by pointing it to the old current node
			num_items += 1;								//note that an item has been added to the list
		}
		else {
			cout << "That index is out of bounds. Adding " << value << " to the end of the list." << endl;		//inform the user something went wrong
			tail->next = temporary;						//add the node to the end of the list
			temporary->item = value;					
			temporary->next = NULL;						//make sure there is no next value
			num_items += 1;								//note that an item has been added
		}

}

bool singleLinkedList::remove(size_t index) {			//removes an item at a certain index

	node* current = new node;							//created for iteration
	node* previous = new node;							//created for iteration
	current = head;										//start at the front of the list
	if (index < num_items && index >= 0)				//check to verify that the index is within the bounds of the list - num_items used as an impromptu list max
	{
		for (int i = 0; i < index; i++) {				//iterate through the list
			previous = current;
			current = current->next;
		}
		if (current->next != NULL) {					//check to see if you've hit the tail or not, vital for the next part
			previous->next = current->next;				//cutting the node out of the list without outright deleting it, current next CANNOT be NULL
			cout << "Removal successful." << endl;
			num_items -= 1;								//note that an item has been removed and return true
			return true;
		}
		else {
			cout << "Removal unsuccessful." << endl;	//failsafe false if the above criteria are not met
			return false;
		}
	}
	else {												//returns false - index is out of the scope
		cout << "Removal unsuccessful." << endl;
		return false;
	}
}

size_t singleLinkedList::find(const int value) {		//find a value in the list
	node* previous = new node;							//created for iteration
	node* current = new node;							//created for iteration
	current = head;										//start at the top of the list
	for (int i = 0; i < num_items; i++) {				//using num_items as a max index, iterate through the list up to the max index
		if (current->item == value) {					//check to see if the current node's data is equal to the desired value
			cout << "The index of this item is " << i << endl;
			return current->index;						//if so, return the index
		}
		previous = current;								//the actual iteration loop
		current = current->next;
	}
		cout << "Item could not be found." << endl;		//failsafe if the item cannot be found in the list
		return current->index;							//since the program has to return something to exit, return the tail index (technically the 'size' of the index)

}