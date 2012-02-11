/**
 * \file Grid.h
 * \brief Contains the definition of the class Grid
 * \author Ubu
 * \version 0.1
 * \date 10/02/2012
 */
 
#ifndef GRID_H
#define GRID_H

/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */


/* Personnal Headers */
#include "Node.h"
#include "main.h"

class Node;
/* ------------------------------------------- CLASS ------------------------------------------- */
/**
 * \class Grid
 * \brief
 */
class Grid
{
	private:
		int seed;
		Node* grid[LENGTH][LENGTH]; // First is column, second is line
    	  
	public:
		// \brief Constructor of the class
		Grid(int s = 0);
		
		// \brief Destructor of the class
		~Grid();
		
		// \brief Accessor for one box in the grid
		const Node* GetNode(int positionX, int positionY) const;
		
		// \brief Print the grid in the output
		void Print() const;
		
		// \brief Print one box in the output
		void Print(int i, int j) const;
};

#endif
