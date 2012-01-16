/**
 * \file GridPart.cpp
 * \brief Contains the definition of class GridPart's methods
 * \author Ubu
 * \version 0.1
 * \date 15/01/2012
 */
 
/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
#include <iostream>

/* Personnal Headers */
#include "GridPart.h"

/* ----------------------------------------- FONCTIONS ----------------------------------------- */
/**
 * \details Constructor of the class GridPart
 * Initialize values of the attributes
 * \param
 */
GridPart::GridPart()
{
}

/**
 * \function PrintLine
 * \details Print a line of the gridPart
 * \param line: line which will be printed
 */
void GridPart::PrintLine(int line) const
{
	int i;
	
	for (i = 0; i < LENGTH; i++)
	{
		std::cout<<gridPart[i][line].getValue()<<" ";
	}
}

/**
 * \function RemovePossibleValue
 * \details Remove a value in every box of the gridPart
 * \param value: value which will be removed from possibilities for every box of the gridPart
 */
void GridPart::RemovePossibleValue(int value)
{
	int i, j;
	
	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
			gridPart[i][j].RemovePossibleValue(value);
		}
	}
}
		

/**
 * \function RemovePossibleValueLine
 * \details Remove a value in every column of the line of the gridPart
 * \param line: line we will consider
 * \param value: value which will be removed from possibilities for every box of the gridPart
 */
void GridPart::RemovePossibleValueLine(int line, int value)
{
	int i;
	
	for (i = 0; i < LENGTH; i++)
	{
		gridPart[i][line].RemovePossibleValue(value);
	}
}


/**
 * \function RemovePossibleValueColumn
 * \details Remove a value in every line of the column of the gridPart
 * \param column: column we will consider
 * \param value: value which will be removed from possibilities for every box of the gridPart
 */
void GridPart::RemovePossibleValueColumn(int column, int value)
{
	int i;
	
	for (i = 0; i < LENGTH; i++)
	{
		gridPart[column][i].RemovePossibleValue(value);
	}
}
