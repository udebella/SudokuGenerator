/**
 * \file Grid.cpp
 * \brief Contains the definition of class Grid's methods
 * \author Ubu
 * \version 0.1
 * \date 15/01/2012
 */
 
/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
#include <iostream>
#include <cstdlib>
#include <time.h>

/* Personnal Headers */
#include "Grid.h"

/* ----------------------------------------- FONCTIONS ----------------------------------------- */
/**
 * \details Constructor of the class Grid
 * Initialize values of the attributes
 * \param
 */
Grid::Grid()
{
}

/**
 * \function Print
 * \details Allow to print the grid in a console
 */
void Grid::Print()
{
	int i, j, k;
	
	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
			for (k = 0; k < LENGTH; k++) // Print a line of the entire grid
			{
				grid[k][i].PrintLine(j);
			}
			std::cout<<std::endl;
		}
	}
}

/**
 * \function SetValue
 * \details Allow to set the value of a Box of the grid
 * \param line: number of the line
 * \param column: number of the column
 * \param value: value we want to put
 * \return true if the value has been set else it returns false
 */
bool Grid::SetValue(int line, int column, int value)
{
	int gridLine = line / LENGTH;
	int gridColumn = column / LENGTH;
	int i;
	bool returnValue = false;
	
	if (grid[gridColumn][gridLine].getItem(line % LENGTH, column % LENGTH).SetValue(value))
	{
		grid[gridColumn][gridLine].RemovePossibleValue(value);
		for (i = 0; i < LENGTH; i++)
		{
			grid[gridColumn][i].RemovePossibleValueColumn(column % LENGTH, value);
			grid[i][gridLine].RemovePossibleValueLine(line % LENGTH, value);
		}
		returnValue = true;
	}
	return returnValue;
}

/**
 * \function Initialize
 * \details Initialize the grid with random values
 */
void Grid::Initialize()
{
	int i, j;
	int randomValue;
	
	srand(time(NULL));
	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
			randomValue = rand() % (10-1) + 1;
			while (SetValue(i, j, randomValue) == false)
				randomValue = rand() % (10-1) + 1;
		}
	}
	for (i = 3; i < 6; i++)
	{
		for (j = 3; j < 6; j++)
		{
			randomValue = rand() % (10-1) + 1;
			while (SetValue(i, j, randomValue) == false)
				randomValue = rand() % (10-1) + 1;
		}
	}
	for (i = 3; i < 6; i++)
	{
		for (j = 0; j < 3; j++)
		{
			randomValue = rand() % (10-1) + 1;
			while (SetValue(i, j, randomValue) == false)
				randomValue = rand() % (10-1) + 1;
		}
	}
}

void Grid::PrintPossibleValue(int line, int column)
{
	int gridLine = line / LENGTH;
	int gridColumn = column / LENGTH;
	
	std::cout<<"PossibleValue["<<column<<"]["<<line<<"] = ";
	grid[gridColumn][gridLine].getItem(line % LENGTH, column % LENGTH).PrintPossibleValue();
}
