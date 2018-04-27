/**
 * @brief Implementations of matching header file.
 * 
 * @file heap.cpp
 * @author Patrick Valgento
 * @date 2018-03-19
 */

#include "heap.h"
#include <algorithm> 			// std::swap
#include <fstream>				// printf()

namespace CSE {
	
#pragma region Class Definitions
//=====================================================
//                   ELEMENT Definitions
//=====================================================
	ELEMENT::ELEMENT() : key(0) {}
	ELEMENT::ELEMENT(int key) : key(key) {}
	ELEMENT::ELEMENT(const ELEMENT&) = default;

//=====================================================
//                    HEAP Definitions
//=====================================================

	HEAP::HEAP() : capacity(0), size(0), H(nullptr) {}
	HEAP::HEAP(int _capacity) : capacity(_capacity < 1 ? 1 : _capacity), size(0), H(new ELEMENT[capacity + 1]) {}
	HEAP::HEAP(const HEAP& h) : capacity(h.capacity), size(h.size), H(new ELEMENT[h.capacity+1]) {
		//Make copy have its own array so that death of another heap doesn't delete or change this one's data.
		for (int i = 1; i <= size;++i)		
			H[i] = h[i];
	}		
	HEAP::~HEAP() {	
		delete[]H; 
	}
	void HEAP::setSize (int _size) {

		if (capacity == 0){									//Only happens in "uninitialized" case. 
			size = _size;
			capacity = 2*size;
			H = new ELEMENT[capacity + 1];
			return;
		}

		if (_size < 0) {									//Won't perform invalid command
			printf("\nSize cannot be negative.\n");
			return;
		}				
		if (_size <= capacity ) {							//No need to copy contents if capacity doesn't have to change
			size = _size;
			return;
		}

		while ( capacity < _size ) 
			capacity *=2;

		ELEMENT* toReplace = new ELEMENT[capacity + 1];		//Otherwise capacity needs to be expanded.
		for (int i = 1; i <= size; ++i) {					//Copy original contents
			toReplace[i] = H[i];
		}
		delete[]H;											//Clear old allocated array space
		H = toReplace;

		size = _size;
	}
	HEAP& HEAP::operator=( const HEAP& other ) {
		
		if (capacity != other.capacity) {					// if capacity not exactly the same no need to reallocate its existing H variable
			delete[]H;
			H = new ELEMENT[other.capacity + 1];
			capacity = other.capacity;
		}
		for (int i = 1; i <= other.size; ++i)				// Copy the contents of the assigning heap
			H[i] = other[i];
		
		size = other.size;									// Set size to the assigning heap's size
	
		return *this;
	}
	void HEAP::AssignNewData(ELEMENT* set, int _size){
		if (_size <= capacity)
			size = _size;
		else {
			delete[]H;
			H = new ELEMENT[_size+1];
			capacity = _size;
			size = _size;
		}

		for (int i = 1; i <= size; ++i)
			H[i] = set[i];

		for (int i = size/2; i >=1; --i)
			Heapify(i);
	}
	void HEAP::Heapify(int i){
		int left, right, smallest;

		left = Left(i);
		right = Right(i);

		if (left <= size && H[left].key < H[i].key)
			smallest = left;
		else
			smallest = i;
		if (right <= size && H[right].key < H[smallest].key)
			smallest = right;
		if (smallest != i){
			std::swap(H[i],H[smallest]);
			Heapify(smallest);
		}
	}


#pragma endregion Class Definitions

#pragma region Heap Functions
	
//=====================================================
//             Requested Function Definitions
//=====================================================

	void BuildHeap(HEAP &heap, ELEMENT* A, int Asize) {
		
		if (Asize <= 0) {										// Invalid or 0 entry will just set size to 0
			printf("\nInvalid size, size will be set to default 0\n)");
			heap.setSize(0);
			return;
		}		
		heap.AssignNewData(A, Asize); 							//heapify is embedded in this so that no public access to the heap can compromise its integrity by using this function and not following by heapify.
	}
	void Insert(HEAP &heap, int key, bool flag) {
		if (flag)
			printHeap(heap);
		
		heap.setSize( heap.getSize() + 1);						// Increment size

		int index = heap.getSize();								

		heap[index].key = key;									// Add the key to the end of the current perceived array
		
		while (index > 1) {										// Swap with parent if parent is larger
			if (key < heap[Parent(index)].key) {
				std::swap(heap[index], heap[Parent(index)]);
				index = Parent(index);
			}
			else 
				break;
		}
		if (flag)
			printHeap(heap);
	}
	int DeleteMin(HEAP &heap, bool flag) {
		if (flag)
			printHeap(heap);
		
		if (heap.getSize() == 0){								// If heap is already empty nothing needs to be done
			printf("\nNothing to delete, size is 0\n");
			return 0;
		}
		
		int toReturn = heap[1].key;								// Save the key that will be deleted

		int oldLast = heap[heap.getSize()].key;					// Grab the key of the last element in the heap
		
		heap.setSize( heap.getSize() - 1);						// Decrement the size of the heap 

		heap[1].key = oldLast;									// Place the old last element into the head of the heap

		heap.Heapify(1);										// Make the new head find its correct place in the heap

		if (flag)
			printHeap(heap);

		return toReturn;
	}
	void DecreaseKey(HEAP &heap, int index, int value, bool flag) {		

		if (flag)
			printHeap(heap);
		
		int size = heap.getSize();

		if (index > size || index <= 0) {						// If the index is invalid nothing is done
			if (flag)
				printf("\nNot a valid index\n");
			return;
		}		

		int key = heap[index].key;								

		if (value >= key) {										// If the value is greater than the value at the indexed element nothing is done
			if (flag) 
				printHeap(heap);
			return;
		}

		heap[index].key = value;								// Now we know that it's a valid index and is a smaller value
		
		while (index > 1) {										// Update the position of the element so that the heap is maintained
			if (value < heap[Parent(index)].key) {
				std::swap(heap[index], heap[Parent(index)]);
				index = Parent(index);
			}
			else
				break;
		}
		
		if (flag)
			printHeap(heap);
	}
	void printHeap(HEAP &heap) {
		int size = heap.getSize();
		int capacity = heap.getCapacity();
		
		printf("Capacity: %d\n", capacity);						// Print Capacity
		printf("Size: %d\n", size);								// Print Size		
		for (int i = 1; i <= size; ++i) {						// Print the values of the heap
			printf("%d\n", heap[i].key);		
		}	
		printf("\n");
		
	}

#pragma endregion Heap Functions
}
