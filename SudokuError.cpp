/**
 * \file SudokuError.cpp
 * \brief Contains the definition of class SudokuError's methods
 * \author Ubu
 * \version 0.1
 * \date 04/02/2012
 */
 
/* ------------------------------------------ INCLUDE ------------------------------------------ */
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
