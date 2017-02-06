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
		@PRE:	is passed a positive integer for table size
		@POST:	creates an open hashtable w/ chaining of given size,
			and empty doublelinkedlists in each "slot"
		@RETURN:none
	*/
	OpenHashtable(int size_of_table);

	/*
		@PRE:	No illegal actions have occurred on the table
		@POST:	hashtable and all lists therein are destroyed
		@RETURN:none
	*/
	~OpenHashtable();

	/*
		@PRE:	is passed an integer value
		@POST:	inserts value to front of list in corresponding key
			slot. If value is already present, then insertion is
			aborted without warning, and it goes back to user
			interfacing
		@RETURN:none
	*/
	void insert(int value_to_insert);

	/*
		@PRE:	is passed an integer value
		@POST:	value is removed from its table key list, if present.
			If not present, then operation is aborted without warning,
			and program returns to whatever it was doing prior.
		@RETURN:none
	*/
	void deleteNode(int value_to_remove);

	/*
		@PRE:	none
		@POST:	table is printed out to terminal
		@RETURN:none
	*/
	void print();

	/*
		@PRE:	is passed an integer and table was correctly instantiated
		@POST:	none
		@RETURN:the hashed/table key value of passed value
	*/
	int hash(int value_to_hash);

	/*
		@PRE:	none
		@POST:	none
		@RETURN:"true" if value has been inserted and is currently a member
			of the table, false otherwise.
	*/
	bool find(int value_to_find);


	private:
	int m_size;

	//Array of pointers to DoubleLinkedLists
	DoubleLinkedList **m_table;

};

#endif
