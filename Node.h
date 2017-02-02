/*	@AUTHOR: John Russell, 2798357
 *	@EMAIL:  j362r647@ku.edu
 *	@DATE:	 26 January 2017
 *	@FILE:	 Node.h
 *	@PURPOSE: Header file for a Node class
*/

#ifndef NODE_H
#define NODE_H

//TODO: Add all the pre,post,return conditions

class Node
{
	public:
	//Create Node with null pointers, default value of zero
	/*
		@PRE: None
		@POST: creates a node with value 0 and nullptrs for
			next and previous
		@Return: None
	*/
	Node();

	//return pointer to next connected node
	/*
		@PRE: Node off of which function is being called exists
		@POST: none
		@Return: Node* to the next node in the chain

	*/
	Node* getNext();

	/*
		@PRE:	Node exists, is passed a valid Node*
		@POST:	the nextpointer for the node is changed to the 
			given pointer
		@Return:none

	*/
	void setNext(Node* new_next_node);

	//return pinter to previous connected node
	/*
		@PRE:	Node exists
		@POST:	none
		@Return:node* to previous Node in chain
	*/
	Node* getPrevious();

	/*
		@PRE:	Node exists, is passed a valid Node*
		@POST:	previous pointer for node changed to given pointer
		@Return:none
	*/
	void setPrevious(Node* new_next_node);

	//Retrieve the node's value content
	/*
		@PRE:	Node exists
		@POST:	none
		@Return:value stored in node (default for unmodified node is 0)
	*/
	int getValue();

	//Set the node's value content.
	/*
		@PRE:	Node exists, is being passed an int
		@POST:	m_value changed to value_to_use
		@Return:none
	*/
	void setValue(int value_to_use);


	private:
	//the next node in the chain
	Node* m_next;
	//the previous node in the chain
	Node* m_previous;
	//the value stored in the node
	int m_value;

};

#endif
