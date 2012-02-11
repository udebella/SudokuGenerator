/**
 * \file SudokuError.cpp
 * \brief Contains the definition of class SudokuError's methods
 * \author Ubu
 * \version 0.1
 * \date 04/02/2012
 */
 
/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
#include <sstream>
#include <ctime>

/* Personnal Headers */
#include "SudokuError.h"

/* ----------------------------------------- FONCTIONS ----------------------------------------- */
/**
 * \details Constructor of the class SudokuError
 * Initialize values of the attributes
 * \param d: The description of the exception
 * \param n: Number of the exception
 * \param s: Severity of the exception
 */
SudokuError::SudokuError(const std::string& d, int n, Severity s) throw()
{
	description = d;
	number = n;
	severity = s;
}

const char* SudokuError::what() const throw()
{
	std::string returnError; //= "Error n°" + number + ": " + description;
	std::ostringstream n;
	time_t t = time(NULL); 
	
	n << number;
	returnError += "================================================================================\nDate: ";
	returnError += ctime(&t);
	returnError += "\nError n°" + n.str() + "[";
	switch (severity)
	{
		case NOT_CRITICAL:
			returnError += "NOT_CRITICAL";
			break;
		case CRITICAL:
			returnError += "CRITICAL";
	}
	returnError += "]: " + description + "\n";
	return returnError.c_str();
}
