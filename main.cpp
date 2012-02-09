/**
 * \file main.cpp
 * \brief Contains the main function of the software
 * \author Ubu
 * \version 0.1
 * \date 14/01/2012
 */
 
/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
#include <cstdlib>
#include <iostream>

/* Personnal Headers */
#include "Grid.h"
#include "Box.h"
#include "SudokuError.h"

/* --------------------------------------- MAIN FUNCTION --------------------------------------- */
/**
 * \function main
 * \brief Main function of the software
 */
 int main(int argc, char* argv[])
 {
	try
	{
 		Grid gridTest;
 		gridTest.Initialize();
 		gridTest.Print();
	}
	catch (std::exception const& e)
	{
		std::cerr<<"ERREUR : "<<e.what()<<std::endl;
	}
 	/*try
 	{
 		gridTest.SetValue(0,0,11);
 	}
 	catch (SudokuError e)
 	{
 		std::cerr<<"\nError "<<e.getNumber()<<": "<<e.getDescription()<<std::endl<<std::endl;
 		if (e.getSeverity() == CRITICAL)
 			exit(e.getNumber());
 	}*/
 	/*gridTest.PrintPossibleValue(0, 7);
 	gridTest.PrintPossibleValue(1, 7);*/
 	return EXIT_SUCCESS;
 }
