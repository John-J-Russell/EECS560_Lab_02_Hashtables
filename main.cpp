/*
	@AUTHOR: John Russell, j362r647@ku.edu
	@FILENAME: main.cpp
	@DATE: 2 February 2017
	@PURPOSE: Handles user input and file input to create and
		  alter hashtable
*/

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "OpenHashtable.h"

void printMenu()
{
	std::cout<<"Please choose one of the following commands: \n";
	std::cout<<"1) insert\n";
	std::cout<<"2) delete\n";
	std::cout<<"3) print\n";
	std::cout<<"4) exit\n\n";
}

int main()
{
	//declare variables
	bool continue_program=true;
	int user_input;
	OpenHashtable* interactive_table;
	std::string file_input_line;
	std::ifstream data_file("data.txt");
	//import from file
	
	//table size gets done here
	try
	{
		if(data_file.is_open())
		{
			//read first line from file
			getline(data_file,file_input_line);
			//make table properly, parse string to int and pass to constructor
			interactive_table = new OpenHashtable(std::stoi(file_input_line));
			//get rest of table inputs
			while(getline(data_file , file_input_line) )
			{
				interactive_table->insert(std::stoi(file_input_line));
			}
		}
		else
		{
			std::cout<<"An error occurred when opening the file.\n\n";
		}
	}
	catch(std::runtime_error& e)
	{
		std::cout<<"An error occured while reading the file.\n";
		std::cout<<"Error is: " << e.what() <<"\n\n";

	}

	//interact with user
	while(continue_program == true)
	{
		printMenu();
		std::cin>>user_input;
		switch(user_input){
			case 1:
				std::cout<<"Please insert an integer to add:\n";
				std::cin>>user_input;
				//insert value to table. Note that there is no
				//type check that occurs here. Invalid input breaks this.
				interactive_table->insert(user_input);
				break;
			case 2:
				std::cout<<"Please insert an integer to remove:\n";
				std::cin>>user_input;
				//calls remove with given value, but like insert it performs
				//no typecheck on the input.
				interactive_table->deleteNode(user_input);
				break;
			case 3:
				interactive_table->print();
				break;
			case 4:
				std::cout<<"Goodbye.\n\n";
				continue_program=false;
				break;
			default:
				std::cout<<"Input invalid.\n\n";
				break;
		}
	}



	delete(interactive_table);


	return(0);
}
