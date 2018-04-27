/**
 * @brief Utility functions including the functionality required to interact with the terminal.
 * 
 * @file util.h
 * @author Patrick Valgento
 * @date 2018-03-19
 */ 

#pragma once
#include "heap.h"

namespace CSE {
	/**
	 * @brief Scans the terminal until it receives a command
	 * 
	 * @param i Potential first field.
	 * @param v Potential second field.
	 * @param f Potential third field.
	 * @return int The function choosing value.
	 */
	int nextCommand(int *i, int *v, int *f);
	/**
	 * @brief Will perform whatever command was requested 
	 * 
	 * @param H A HEAP to process.
	 * @param choice The command choice.
	 * @param i The first field
	 * @param v The second field.
	 * @param f The third field.
	 */
	void performCommand(HEAP &H, char choice, int i, int v, int f);
	/**
	 * @brief Reads heap array from the file.
	 * 
	 * @param heap the heap to put the array into.
	 */
	void readHeapArray(HEAP &heap);
}