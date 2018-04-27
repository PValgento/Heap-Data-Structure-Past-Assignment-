/**
 * @brief Implementations of matching header file.
 * 
 * @file util.cpp
 * @author Patrick Valgento
 * @date 2018-03-19
 */
#include "util.h"
#include <string>			// std::string
#include <fstream>			// std::ifstream , printf()
#include <ctype.h>			// toupper(char)
#include <stdexcept>		// std::stoi exceptions

const static std::string FILENAME = "HEAPinput.txt";

namespace CSE {

	int nextCommand(int *i, int *v, int *f)	{
		
		char c = '0'; 

		while (1) {
			scanf("%c", &c);
			if (c == ' ' || c == '\t' || c == '\n') {
				continue;
			}
			if (c == 'S' || c == 'R' || c == 'W' || c == 's' || c == 'r' || c == 'w') {
				break;
			}
			if (c == 'C' || c == 'c') {
				scanf("%d", i);
				break;
			}
			if (c == 'I' || c == 'i') {
				scanf("%d", i); scanf("%d", v);
				break;
			}
			if (c == 'D' || c == 'd') {
				scanf("%d", i);
				break;
			}
			if (c == 'K' || c == 'k') {
				scanf("%d", i); scanf("%d", v); scanf("%d", f);
				break;
			}
			printf("Invalid Command\n");
		}
		printf("\n");
		
		return c;
	}
	
	void performCommand(HEAP &heap, char choice, int i, int v, int f) {
			
		choice = toupper(choice);		

		if ( heap.getCapacity() == 0 )
			if ( choice != 'C' && choice != 'S' ) {
				printf("Heap has not been initialized, please initialize first for this operation.\n");
				return;
			}

		switch (choice) {
			case 'S': printf("COMMAND: %c. \n\nProgram will be terminated.", choice ); exit(EXIT_SUCCESS);  
			case 'C': printf("COMMAND: %c %d. \n\n", choice, i); heap = Initialize(i); break; 
			case 'R': printf("COMMAND: %c. \n\n", choice); readHeapArray(heap); break; 
			case 'W': printf("COMMAND: %c. \n\n", choice); printHeap(heap); break; 
			case 'I': printf("COMMAND: %c %d %d.\n\n", choice, i, v); Insert(heap, i, v); break; 
			case 'D': printf("COMMAND: %c %d. \n\n", choice, i); printf("%d\n\n",DeleteMin(heap, i)); break; 
			case 'K': printf("COMMAND: %c %d %d %d. \n\n", choice, i, v, f); DecreaseKey(heap, i, v, f); 			
			default: break;
		}
	}

	void readHeapArray(HEAP &heap) {
		std::ifstream heapInput(FILENAME);
		std::string fileLine = "";
		
		if (heapInput.is_open()) {
		
			std::getline(heapInput, fileLine);							//grab first line
			int size;
			try {
				size = std::stoi(fileLine);								//assign value as size of array
			}
			catch (...) {		
				printf("Contents of file do not correctly match what the program is expecting, setting heap size to 0\n");
				heap.setSize(0);				
				return;
			}

			if (heap.getCapacity() < size){
				printf("please  increase capacity of the heap to at least %d\n",size);
				return;
			}
			
			ELEMENT* h = new ELEMENT[size+1];

			for (int i = 1; i <= size; ++i) {
				std::getline(heapInput, fileLine);						//grab next line				
				try { 
					h[i].key = std::stoi(fileLine);						//place a new element with the key set to the value of the number on the current line
				}
				catch (...) {	
					printf("Contents of file do not correctly match what the program is expecting, setting heap size to 0\n");
					heap.setSize(0);
					delete []h;
					h = nullptr;
					return;
				}
			}
			heapInput.close();

			BuildHeap(heap,h,size);
			
			delete[]h;
			h = nullptr;

		}
		else
			printf("\nFile wasn't open/found!\n");
		return;
	}
}
