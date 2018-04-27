/**
 * @brief Allows user to test functions on the <see cref="HEAP"/> class.
 * 
 * @file main.cpp
 * @author Patrick Valgento
 * @date 2018-03-19
 */

#include "heap.h"
#include "util.h"
#include <fstream>
#include <iostream>

 /**
 * @brief Allows user to test functions on the <see cref="HEAP"/> class.
 *
 */
int main() {
		
	CSE::HEAP heap;							
	int choice, i= 0, v = 0, f= 0;
	
	
	printf("Heap Program\n------------\n\n");
	printf("S: Stop Program\nC (n): New Heap Capacity (n)\nR: Read from File\nW: Print Heap\n");
		printf("I (k f), Insert (k) to heap, (f) to display before/after\nD (f): Delete minimum, (f) to display before/after\n");
		printf("K (i v f): decrease (i)'th element to value of (v), (f) to display before/after");
		printf("\n-----------------------------------------------------------------\n");
	
	while (true) {		
		choice = CSE::nextCommand(&i, &v, &f);
		CSE::performCommand(heap, choice, i, v, f);
	}
	return 0;
}
