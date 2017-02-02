/*
	@AUTHOR: John Russell, j362r647@ku.edu
	@FILENAME: OpenHashtable.cpp
	@DATE: 2 February 2017
	@PURPOSE: Function definitions for the open hashtable
		  with chaining
*/

#include "OpenHashtable.h"

OpenHashtable::OpenHashtable(int size_of_table)
{
	m_size = size_of_table;
	//create array of size table_size
	m_table = new DoubleLinkedList*[size_of_table];
	for(int x=0; x<size_of_table; x++)
	{
		//instantiate each entry with an empty list
		m_table[x] = new DoubleLinkedList();
	}
}

OpenHashtable::~OpenHashtable()
{
	//delete all lists in the table
	for(int x=0; x<m_size; x++)
	{
		delete(m_table[x]);
	}
	//delete the table proper
	delete(m_table);
}

void OpenHashtable::insert(int value_to_insert)
{
	//hash the value, go to list location in table,
	//use the predefined function to insert
	int table_key = hash(value_to_insert);
	m_table[table_key]->insert( value_to_insert , m_table[table_key]->getFirst() );
	return;
}

void OpenHashtable::deleteNode(int value_to_remove)
{
	//hash value into key
	int table_key = hash(value_to_remove);
	//delete value from corresponding list
	m_table[table_key]->remove( value_to_remove , m_table[table_key]->getFirst() );
	return;
}

void OpenHashtable::print()
{

	for(int x=0; x<m_size; x++)
	{
		//print table row
		std::cout<< x << ": ";
		//call modified print function for list
		m_table[x]->print();
	}
	std::cout<<"\n\n";
	return;
}

int OpenHashtable::hash(int value_to_hash)
{
	//hash is a simple modulus function, where the mod value
	//is the size of the table
	return( value_to_hash % m_size );
}

bool OpenHashtable::find(int value_to_find)
{
	int table_key = hash(value_to_find);
	//pick the list mapping to the table key
	DoubleLinkedList* active_chain = m_table[table_key];
	Node* current_node = active_chain->getFirst();
	//iterate through entirety of list
	while(current_node != nullptr)
	{
		//check if proper value
		if(current_node->getValue() == value_to_find)
		{
			return(true);
		}
		current_node = current_node->getNext();
	}
	return(false);

}


