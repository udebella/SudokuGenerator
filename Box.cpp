/**
 * \file Box.cpp
 * \brief Contains the definition of class Box's methods
 * \author Ubu
 * \version 0.1
 * \date 15/01/2012
 */
 
/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
//#include <list>

/* Personnal Headers */
#include "Box.h"

/* ----------------------------------------- FONCTIONS ----------------------------------------- */
/**
 * \details Constructor of the class Box
 * Initialize values of the attributes
 * \param
 */
Box::Box(): value(0)
{
	int i;
	
	for (i = 1; i < 10; i++)
	{
		possibleValue.push_back(i);
	}
}

/**
 * \function RemovePossibleValue
 * \details Allow to remove a value in the list of the possible values
 * \param value: The value we want to remove
 */
void Box::RemovePossibleValue(int value)
{
	possibleValue.remove(value);
}

/**
 * \function AddPossibleValue
 * \details Allow to add a value in the list of the possible values
 * \param value: The value we want to add
 */
void Box::AddPossibleValue(int value)
{
	possibleValue.push_back(value);
}

/**
 * \function SetValue
 * \details Set the value of the box if it is possible
 * \param value: The value we want to set for the box
 * \return true if the value has been set and false otherwise
 */
bool Box::SetValue(int value)
{
	std::list<int>::iterator it = possibleValue.begin();
	bool notPossible = false;
	
	while ((value != *it) && (it != possibleValue.end()))
	{
		it++;
	}
	if (value == *it)
	{
		notPossible = true;
		this->value = value;
	}
	return notPossible;
}

#include <iostream>
void Box::PrintPossibleValue()
{
	std::list<int>::iterator it;
	
	for(it = possibleValue.begin(); it != possibleValue.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
}
