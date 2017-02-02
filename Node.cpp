/*	@AUTHOR: John Russell, 2798357
 *	@EMAIL:  j362r647@ku.edu
 *	@DATE:	 26 January 2017
 *	@FILE:	 Node.cpp
 *	@PURPOSE: implementation file for a Nodes class
*/
//For method definitions, refer to header file.

#include "Node.h"

Node::Node()
{
	m_next = nullptr;
	m_previous = nullptr;
	m_value = 0;
}

Node* Node::getNext()
{
	return(m_next);
}

void Node::setNext(Node* new_next_node)
{
	m_next = new_next_node;
}

Node* Node::getPrevious()
{
	return(m_previous);
}

void Node::setPrevious(Node* new_previous_node)
{
	m_previous = new_previous_node;
}

int Node::getValue()
{
	return(m_value);
}

void Node::setValue(int value_to_use)
{
	m_value = value_to_use;
}
