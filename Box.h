/**
 * \file Box.h
 * \brief Contains the definition of the class Box
 * \author Ubu
 * \version 0.1
 * \date 15/01/2012
 */
 
#ifndef BOX_H
#define BOX_H

/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
#include <list>

/* Personnal Headers */


/* ------------------------------------------- CLASS ------------------------------------------- */
/**
 * \class Box
 * \brief Represent one box of the sudoku's grid
 */
class Box
{
	private:
		int value;
		std::list<int> possibleValue;
	
	protected:
    	  
	public:
		// \brief Constructor of the class
		Box();
		
		// \brief Accessor for value attribute
		int getValue() const {return value;}
		
		// \brief Accessor for possibleValue attribute
		const std::list<int>& getPossibleValue() const {return possibleValue;}
		
		// \brief Remove a value in the list of the possible values
		void RemovePossibleValue(int value);
		
		// \brief Add a value in the list of the possible values
		void AddPossibleValue(int value);
		
		// \brief Allow to set the value of the Box
		bool SetValue(int value);
		
		void PrintPossibleValue();
};

#endif
