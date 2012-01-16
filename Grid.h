/**
 * \file Grid.h
 * \brief Contains the definition of the class Grid
 * \author Ubu
 * \version 0.1
 * \date 15/01/2012
 */
 
#ifndef GRID_H
#define GRID_H

/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */


/* Personnal Headers */
#include "GridPart.h"

/* ----------------------------------------- CONSTANTS ----------------------------------------- */
//const int SUDOKU_LENGTH = 3;

/* ------------------------------------------- CLASS ------------------------------------------- */
/**
 * \class Grid
 * \brief Represent the grid of sudoku
 */
class Grid
{
	private:
		GridPart grid[LENGTH][LENGTH]; // First is column, second is line
	
	protected:
    	  
	public:
		// \brief Constructor of the class
		Grid();
		
		// \brief Allow to print a grid
		void Print();
		
		// \brief Allow to set the value of a Box of the grid
		bool SetValue(int line, int column, int value);
		
		// \brief Create a grid
		void Initialize();
		
		void PrintPossibleValue(int line, int column);
};

#endif
