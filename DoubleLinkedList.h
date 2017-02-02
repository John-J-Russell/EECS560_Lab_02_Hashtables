/*	@AUTHOR: John Russell, 2798357
 *	@EMAIL:  j362r647@ku.edu
 *	@DATE:	 26 January 2017
 *	@FILE:	 DoubleLinkedList.h
 *	@PURPOSE: Header file for a double linked list class
*/

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include "Node.h"


//Functions assume that they are being passed integer values.
//Anything else will probably break this horribly, as there is no
//implemented type checking.
class DoubleLinkedList
{
	public:
	
	//Constructor
	/*
		@PRE:	none
		@POST:	DLL of size zero with nullptrs instantiated
		@Return:none
	*/
	DoubleLinkedList();

	//Destructor
	/*
		@PRE:	none
		@POST:	all nodes in list deleted, pointers set to nullptr
		@Return:none
	*/
	~DoubleLinkedList();

	/*
		@PRE:	list exists
		@POST:	contents of list (m_values of nodes) printed
			to terminal
		@Return:none
	*/
	void print();

	/*
		@PRE:	Is called with integer, and from outside method it *MUST*
			be called with m_first (via the getFirst() function)
		@POST:	If value not already in list, then Node with insert_value
			is added to the front of list
		@Return:none
	*/
	void insert(int insert_value, Node* current_node);

	/*
		@PRE:	Is called with integer, and from outside method it *MUST*
			be called with m_first (via the getFirst() function)
		@POST:	if value is in list, then Node containing that value is deleted.
		@Return:none
	*/
	void remove(int value_to_remove, Node* current_node);

	
	/*
		@PRE:	list exists
		@POST:	the order of the list is flipped, with what was previously
			m_first in m_last, and all other entries similarly changed.
			e.g. "1,2,4,6" becomes "6,4,2,1" in order.
		@Return:none
	*/
	void reverse(Node* current_node);
	
	/*
		@PRE:	list exists.
		@POST:	none
		@Return:Node* to first entry. If list is empty, returns nullptr.
	*/
	Node* getFirst();

	/*
		@PRE:	list exists
		@POST:	none
		@Return:Node* to last entry. If list is empty, then returns nullptr.
	*/
	Node* getLast();

	/*
		@PRE:	list exists
		@POST:	none
		@Return:the integer number for how many Nodes are in list.
	*/
	int getSize();

	private:
	//First Node in list
	Node* m_first;
	//Last Node in list
	Node* m_last;
	//number of nodes in list
	int m_size;

};

#endif
