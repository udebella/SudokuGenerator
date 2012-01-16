/**
 * \file GridPart.h
 * \brief Contains the definition of the class GridPart
 * \author Ubu
 * \version 0.1
 * \date 15/01/2012
 */
 
#ifndef GRIDPART_H
#define GRIDPART_H

/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */


/* Personnal Headers */
#include "Box.h"

/* ----------------------------------------- CONSTANTS ----------------------------------------- */
const int LENGTH = 3;


/* ------------------------------------------- CLASS ------------------------------------------- */
/**
 * \class GridPart
 * \brief That's a part of the sudoku grid (there are 3 grid 3x3 in a sudoku grid)
 */
class GridPart
{
	private:
		Box gridPart[LENGTH][LENGTH]; // First is column, second is line
	
	protected:
    	  
	public:
		// \brief Constructor of the class
		GridPart();
		
		// \brief Access to an item of the gridPart
		Box& getItem(int line, int column) {return gridPart[column][line];}
		
		// \brief Print a line of the gridPart
		void PrintLine(int line) const;
		
		// \brief Remove a value in every box of the gridPart
		void RemovePossibleValue(int value);
		
		// \brief Remove a value in every column of the line of the gridPart
		void RemovePossibleValueLine(int line, int value);
		
		// \brief Remove a value in every line of the column of the gridPart
		void RemovePossibleValueColumn(int column, int value);
};

#endif
