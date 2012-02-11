/**
 * \file Grid.cpp
 * \brief Contains the definition of class Grid's methods
 * \author Ubu
 * \version 0.1
 * \date 10/02/2012
 */
 
/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
#include <fstream>
#include <time.h>

/* Personnal Headers */
#include "Grid.h"
#include "SudokuError.h"

/* ----------------------------------------- FONCTIONS ----------------------------------------- */
/**
 * \function Grid
 * \details Constructor of the class Grid
 * Initialize values of the attributes
 * \param s: The seed of the greed which will be used to generate random numbers in the grid
 */
Grid::Grid(int s)
{
	int i, j;
	
	if (s == 0) // If the seed is not given by the user, we generate one
	{
		seed = time(NULL);
	}
	else
	{
		seed = s;
	}
	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
			grid[j][i] = new Node(i, j); // Creates every box of the sudoku grid
		}
	}
	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
			grid[j][i]->CreateNeighbours(*this); // Creates links between boxes (lines, columns, areas)
		}
	}
}

/**
 * \function ~Grid
 * \details Destructor of the class Grid
 * Frees the memory allocated in the constructor
 */
Grid::~Grid()
{
	int i, j;
	
	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
			delete grid[j][i];
		}
	}
}

/**
 * \function GetNode
 * \details Accessor for a box in the grid
 * \param positionX: Number of the line of the box on which we will work
 * \param positionY: Number of the column of the box on which we will work
 * \return The function return a constant pointer on the box
 */
const Node* Grid::GetNode(int positionX, int positionY) const
{
	if ((positionX < 0) || (positionX >= LENGTH))
	{
		throw SudokuError("PositionX out of range", 1, CRITICAL);
	}
	if ((positionY < 0) || (positionY >= LENGTH))
	{
		throw SudokuError("PositionY out of range", 1, CRITICAL);
	}
	return grid[positionX][positionY];
}

/**
 * \function Print
 * \details Print the grid on the output which is presised in "main.h"
 * \return Nothing.
 */
void Grid::Print() const
{
	int i, j;
	std::ofstream cout(OUTPUT, std::ios::app);
	
	cout << "================================================================================\n";
	cout << "Seed: " << seed << "\n";
	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
			cout << grid[i][j]->GetValue() << " ";
//			cout << grid[i][j]->GetPositionX() << "," << grid[i][j]->GetPositionY() << " "; // Used for debug
		}
		cout << "\n";
	}
	cout << "================================================================================\n" << "\n";
}

/**
 * \function Print
 * \details Print the value of the box and all the neighbours of the box on the output (which is presised in "main.h")
 * \param x: number of the line of the box we will print.
 * \param y: number of the column of the box we will print.
 * \return Nothing.
 */
void Grid::Print(int x, int y) const
{
	std::ofstream cout(OUTPUT, std::ios::app);
	std::list<const Node*>::iterator it;

	if ((x < 0) || (x >= LENGTH))
	{
		throw SudokuError("PositionX out of range", 1, CRITICAL);
	}
	if ((y < 0) || (y >= LENGTH))
	{
		throw SudokuError("PositionY out of range", 1, CRITICAL);
	}
	cout << "================================================================================\n";
	cout << "grid[" << x << "][" << y << "] = " << grid[x][y]->GetValue() << "\n";
	for (it = grid[x][y]->GetNeighbours().begin(); it != grid[x][y]->GetNeighbours().end(); it++)
	{
		cout << "neighbours: [" << (*it)->GetPositionX() << "][" << (*it)->GetPositionY() << "]" << "\n";
	}
	cout << "================================================================================\n";
}
