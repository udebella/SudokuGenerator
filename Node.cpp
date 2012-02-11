/**
 * \file Node.cpp
 * \brief Contains the definition of class Node's methods
 * \author Ubu
 * \version 0.1
 * \date 10/02/2012
 */
 
/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */


/* Personnal Headers */
#include "Node.h"

/* ----------------------------------------- FONCTIONS ----------------------------------------- */
/**
 * \function Node
 * \details Constructor of the class Node
 * Initialize values of the attributes
 * \param x: That is the line number of the box
 * \param y: That is the column number of the box
 */
Node::Node(int x, int y)
{
	positionX = x;
	positionY = y;
	value = 0;
}

/**
 * \function CreateNeighbours
 * \details This function is used to creates links between boxes in the grid.
 * For example, boxes which are on the same line must not have the same value. Thoses boxes are linked as neighbours.
 * \param g: That is the grid in which the box are neighbours.
 * \return Nothing.
 */
void Node::CreateNeighbours(const Grid& g)
{
	int i, j;
	int positionXInitial = positionX / NBR_ZONES;
	int positionYInitial = positionY / NBR_ZONES;
	int sizeZones = LENGTH / NBR_ZONES;

	// adding neighbours
	for (i = (positionXInitial * sizeZones); i < ((positionXInitial + 1) * sizeZones); i++)
	{
		for (j = (positionYInitial * sizeZones); j < ((positionYInitial + 1) * sizeZones); j++)
		{
			if ((i != positionX) || (j != positionY))
				neighbours.push_back(g.GetNode(i, j)); // All Nodes in the same area
		}
	}
	for (i = 0; i < LENGTH; i++)
	{
		if ((i < (positionXInitial * sizeZones)) || (i >= ((positionXInitial + 1) * sizeZones)))
			neighbours.push_back(g.GetNode(i, positionY)); // All Nodes on the same line
		if ((i < (positionYInitial * sizeZones)) || (i >= ((positionYInitial + 1) * sizeZones)))
			neighbours.push_back(g.GetNode(positionX, i)); // All Nodes on the same Column
	}
}

/**
 * \details A simple accessor which return the value of the box
 */
int Node::GetValue() const
{
	return value;
}

/**
 * \details A simple accessor which return the neighbours' list of the box
 */
std::list<const Node*>& Node::GetNeighbours()
{
	return neighbours;
}

/**
 * \details A simple accessor which return the line number of the box
 */
int Node::GetPositionX() const
{
	return positionX;
}

/**
 * \details A simple accessor which return the column number of the box
 */
int Node::GetPositionY() const
{
	return positionY;
}
