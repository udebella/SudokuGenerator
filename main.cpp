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

/* Personnal Headers */
#include "Grid.h"
#include "Box.h"

/* --------------------------------------- MAIN FUNCTION --------------------------------------- */
/**
 * \function main
 * \brief Main function of the software
 */
 int main(int argc, char* argv[])
 {
 	Grid gridTest;
 	gridTest.Initialize();
 	gridTest.Print();
 	gridTest.PrintPossibleValue(7, 2);
 	gridTest.PrintPossibleValue(7, 0);
 	return EXIT_SUCCESS;
 }
