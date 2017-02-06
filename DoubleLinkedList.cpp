/*	@AUTHOR: John Russell, 2798357
 *	@EMAIL:  j362r647@ku.edu
 *	@DATE:	 26 January 2017
 *	@FILE:	 DoubleLinkedList.cpp
 *	@PURPOSE: implementation file for a double linked list class
*/
//PRE, POST, and Return conditions defined in header file
#include "DoubleLinkedList.h"


//constructor
DoubleLinkedList::DoubleLinkedList()
{
	m_first = nullptr;
	m_last = nullptr;
	m_size = 0;
}

//destructor
DoubleLinkedList::~DoubleLinkedList()
{
	//if m_size has not been correctly iterated, this function breaks
	if(m_size == 0)
	{
	}
	else
	{
		Node* temporary_node_pointer = m_first;
		//deletes all but last node(none deleted if size 1)
		while(temporary_node_pointer->getNext() != nullptr)
		{
			m_first = m_first->getNext();
			delete(temporary_node_pointer);
			temporary_node_pointer = m_first;
			m_size--;
		}
		//delete last node (or only node if size 1)
		delete(m_last);
		m_size = 0;
		m_first = nullptr;
		m_last = nullptr;
	}
	
}

//Display list contents to terminal
void DoubleLinkedList::print()
{
	if(m_first == nullptr)
	{
		std::cout<<"List is empty \n";
	}
	else
	{
		Node* current_node_pointer = m_first;
		//prints all but the last node in the list
		//std::cout<<"List is:\n\n";
		while(current_node_pointer->getNext() != nullptr)
		{
			std::cout<< current_node_pointer->getValue() << ", ";
			current_node_pointer = current_node_pointer->getNext();
		}
		//print last node in list
		std::cout<<current_node_pointer->getValue() << " \n";
	}
}

//always call from main with getFirst() as second value
void DoubleLinkedList::insert(int value_to_insert, Node* current_node)
{
	
	//If still in list
	if(current_node != nullptr)
	{
		//check if node value already in list
		if(value_to_insert == current_node->getValue())
		{
			//value already exists in list
			std::cout<<"Value already in list \n";
			return;
		}
		else
		{
			//keep iterating
			insert(value_to_insert, current_node->getNext());
		}
	}
	//Reached end of all values, which means time to insert given value
	else
	{
		//create new Node and put value in it
		Node* insertedNode = new Node();
		insertedNode->setValue(value_to_insert);
		//this works even if list empty, as next just
		//becomes/resumes being nullptr
		insertedNode->setNext(m_first);


		//list empty, this will be only entry
		if(0 == m_size)
		{
			m_first = insertedNode;
			m_last = insertedNode;
			m_size = 1;
			//return;
		}
		else
		{
			//append new entry to first node, 
			//iterate m_first and m_size
			m_first->setPrevious(insertedNode);
			m_first=insertedNode;
			m_size++;
		}
	}
	return;
	
}


void DoubleLinkedList::remove(int value_to_remove, Node* current_node)
{
	//function takes a value (and pointer b/c recursion) in,
	//if value is present remove from list.

	if(m_size==0)
	{
		std::cout<<"No values to remove, operation aborted.\n\n";
		return;
	}
	
	//checks all but the last
	if(nullptr != current_node->getNext())
	{
		//current_node needs deleting if true
		if(current_node->getValue() == value_to_remove)
		{
			//if node to be removed is not the first entry
			if(current_node!=m_first)
			{
				//is not the first element, is not the last
				//element

				//link the two nodes on either side
				Node* before = current_node->getPrevious();
				Node* after = current_node->getNext();
				before->setNext(after);
				after->setPrevious(before);
				//remove node, iterate size.
				delete(current_node);
				m_size--;
				std::cout<<"Value removed \n";
				return;
			}
			else if(current_node==m_first)
			{
				//set next node's previous to nullptr,
				//delete current_node, iterate size.
				//Note that if m_first is the only entry,
				//this part of the function is never reached,
				//and it's handled elsewhere.
				Node* next=current_node->getNext();
				next->setPrevious(nullptr);
				delete(current_node);
				m_first =next;
				m_size--;
				std::cout<<"Value removed \n";
				return;
			}
			
		}
		//value note here, we're not at end of list
		else
		{
			//recursive call
			remove(value_to_remove,current_node->getNext());
			
		}
	}
	//if is only one entry in list
	else if(m_size == 1)
	{
		if(current_node->getValue() == value_to_remove)
		{
			//more or less resets to freshly-constructed state.
			delete(current_node);
			m_first = nullptr;
			m_last = nullptr;
			m_size = 0;
			std::cout<<"Value removed \n";
			return;
		}
		return;
	}
	//can only be last node at this juncture
	else
	{
		if(value_to_remove == current_node->getValue())
		{
			Node* prev = current_node->getPrevious();
			prev->setNext(nullptr);
			delete(current_node);
			m_last=prev;
			m_size--;
			std::cout<<"Value removed \n";
			return;
		}
		//the "else" here is only implied, because the alternative is to
		//just do nothing.
		return;
	}
	//one last catch-all return, just in case.
	return;
}

void DoubleLinkedList::reverse(Node* current_node)
{

	//if size is zero, then we don't need to do anything.	
	if( 0 == m_size)
	{
		return;
	}
	if(current_node->getNext() != nullptr)
	{
		//flip mnext and mprev,
		Node* temp_placeholder = current_node->getNext();
		current_node->setNext(current_node->getPrevious());
		current_node->setPrevious(temp_placeholder);
		
		//recursive call to the "next" node in the list.
		reverse(current_node->getPrevious());
	}
	//this works even if size==1, because current's previous is nullptr
	//and m_first is the same as m_last. Essentially it's a very inefficient way
	//of changing nothing, but it requires fewer checks.
	else if(current_node->getNext() == nullptr)
	{
		//as it's the last entry, change the next to the previous,
		//and set the previous to nothing.
		//then just flip m_first and m_last and the process is complete.
		current_node->setNext(current_node->getPrevious());
		current_node->setPrevious(nullptr);
		Node* temp_placeholder = m_first;
		m_first = m_last;
		m_last = temp_placeholder;
	}
	return;
}

//These just return the values in the private variables.
Node* DoubleLinkedList::getFirst()
{
	return(m_first);
}

Node* DoubleLinkedList::getLast()
{
	return(m_last);
}

int DoubleLinkedList::getSize()
{
	return(m_size);
}
