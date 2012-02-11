/**
 * \file main.cpp
 * \brief Contains the main function of the software
 * \author Ubu
 * \version 0.1
 * \date 11/02/2012
 */
 
/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
#include <cstdlib>
#include <fstream>

/* Personnal Headers */
#include "Grid.h"
#include "Node.h"
#include "SudokuError.h"
#include "main.h"

/* --------------------------------------- MAIN FUNCTION --------------------------------------- */
/**
 * \function main
 * \brief Main function of the software
 */
 int main(int argc, char* argv[])
 {
 	Grid gridTest;
 	
 	gridTest.Print();
 	try
 	{
// 		gridTest.Print(4, 9);
 	}
 	catch (std::exception const& e)
	{
		std::ofstream cerr(ERROR_OUTPUT, std::ios::app);
		if (cerr)
		{
			cerr << e.what() << std::endl;
		}
	}
 	return EXIT_SUCCESS;
 }
