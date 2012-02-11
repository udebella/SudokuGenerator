/**
 * \file Node.h
 * \brief Contains the definition of the class Node
 * \author Ubu
 * \version 0.1
 * \date 10/02/2012
 */
 
#ifndef NODE_H
#define NODE_H

/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
#include <list>

/* Personnal Headers */
#include "main.h"
#include "Grid.h"

/* ---------------------------------------- DECLARATION ---------------------------------------- */
class Grid;

/* ------------------------------------------- CLASS ------------------------------------------- */
/**
 * \class Node
 * \brief This class represent one box of the sudoku's grid.
 */
class Node
{
	private:
		int value;                         /*!< Value of the box */
		int positionX;                     /*!< Number of the Line of the box */
		int positionY;                     /*!< Number of the Column of the box */
		std::list<const Node*> neighbours; /*!< List of boxes which must have a different value than the actual box */
    	  
	public:
		// \brief Constructor of the class
		Node(int x, int y);
		
		// \brief Creates links with other boxes which must have a different value
		void CreateNeighbours(const Grid& g);
		
		// \brief Accessor for the value
		int GetValue() const;
		
		// \brief Accessor for the neighbours
		std::list<const Node*>& GetNeighbours();
		
		// \brief Accessor for the PositionX
		int GetPositionX() const;
		
		// \brief Accessor for the PositionY
		int GetPositionY() const;
};

#endif
