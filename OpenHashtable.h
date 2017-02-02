/*
	@AUTHOR: John Russell, j362r647@ku.edu
	@FILENAME: OpenHashtable.h
	@DATE: 2 February 2017
	@PURPOSE: Header file for open hashtable with chaining
*/

#ifndef OPEN_HASHTABLE_H
#define OPEN_HASHTABLE_H

#include "DoubleLinkedList.h"
#include <iostream>

class OpenHashtable
{
	public:
	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	OpenHashtable(int size_of_table);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	~OpenHashtable();

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	void insert(int value_to_insert);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	void deleteNode(int value_to_remove);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	void print();

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	int hash(int value_to_hash);

	/*
		@PRE:	
		@POST:	
		@RETURN:
	*/
	bool find(int value_to_find);


	private:
	int m_size;

	//Array of pointers to DoubleLinkedLists
	DoubleLinkedList **m_table;

};

#endif
