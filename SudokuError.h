/**
 * \file SudokuError.h
 * \brief Contains the definition of the class SudokuError
 * \author Ubu
 * \version 0.1
 * \date 04/02/2012
 */
 
#ifndef SUDOKUERROR_H
#define SUDOKUERROR_H

/* ------------------------------------------ INCLUDE ------------------------------------------ */
/* Standard Libraries */
#include <exception>
#include <string>

/* -------------------------------------- TYPE DEFINITION -------------------------------------- */
enum Severity
{
	NOT_CRITICAL, CRITICAL
};
typedef enum Severity Severity;

/* ------------------------------------------- CLASS ------------------------------------------- */
/**
 * \class SudokuError
 * \brief Class which will allow to handle exceptions
 */
class SudokuError: public std::exception
{
	private:
		std::string description; /*!< Description of the problem */
		int number;              /*!< Number of the exception problem */
		Severity severity;       /*!< Severity of the exception */
    	  
	public:
		// \brief Constructor of the class
		SudokuError(const std::string& d, int n, Severity s) throw();
		
		// \brief Accessor to the description
		const std::string& getDescription() const throw() {return description;}
		
		// \brief Accessor to the number of the exception
		int getNumber() const throw() {return number;}
		
		// \brief Accessor to the severity of the exception
		Severity getSeverity() const throw() {return severity;}
		
		// \brief Reimplementation of the standard function what()
		virtual const char* what() const throw();
		
		// \brief Destructor of the class
		virtual ~SudokuError() throw() {}
};

#endif
