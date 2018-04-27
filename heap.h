/**
 * @brief Header File containing Heap functionality
 * 
 * @file heap.h
 * @author Patrick Valgento
 * @date 2018-03-19
 */

#pragma once

namespace CSE {

#pragma region Classes

	/**
	 * @brief An integer wrapper class
	 * 
	 */
	class ELEMENT {
	public:
		/**
		 * @brief The value of the integer held by this Element.
		 * 
		 */
		int key;
		/**
		 * @brief Default Constructor
		 *
		*/
		ELEMENT();
		/**
		 * @brief Copy Constructor
		 *
		*/
		ELEMENT(const ELEMENT&);
		/**
		 * @brief Constructor that initializes the key value
		 * 		  
		 * @param key The key value to set in the element
		 */
		ELEMENT(int key);
	};

	/**
	 * @brief Class implementing the Heap data structure.
	 * 
	 */
	class HEAP {
		/**
		 * @brief Capacity of current array of ELEMENT's (1 less than actual size of array).
		 * 
		 */
		int capacity;
		/**
		 * @brief Current perceived size of <see cref="H"/>.
		 * 
		 */
		int size;
		/**
		 * @brief An array of <see cref="ELEMENT"/>s of perceived size <see cref="size"/>.
		 * 
		 */
		ELEMENT* H;

	public:
		/**
		 * @brief Default Constructor.
		 */		
		HEAP();
		/**
		 * @brief Constructor.
		 * 
		 * @param capacity the capacity the Heap will begin with.
		 */
		HEAP(int capacity);
		/**
		 * @brief Copy Constructor.
		 * 
		 * @param h heap to copy
		 */
		HEAP(const HEAP& h);		
		 /**
		 * @brief Destructor.
		 *
		 */
		~HEAP();		
		/**
		* @brief Gets capacity of the heap.
		*
		* @return const int Returns the capacity of the heap.
		*/
		inline const int getCapacity() { return capacity; }
		/**
		 * @brief Gets the size of the heap.
		 * 
		 * @return const int Returns the size of the heap.
		 */
		inline const int getSize() { return size; }
		/**
		* @brief Sets the size of the heap to the given value if valid.
		*
		* @param size The size to set the heap to.
		*/
		void setSize(int size);
		/**
		*@brief Assignment operator
		*
		*/
		HEAP& operator=( const HEAP& other );
		/**
		 *@brief Array indexer operator
		 *
		 *@param index The index 
		 *
		 *@return The element taken from the given index
		*/
		inline ELEMENT &operator[] (const int index) {return H[index];}
		/**
		*@brief Array indexer operator for constants 
		*
		*@param index The index
		*
		*@return The element taken from the given index
		*/
		inline const ELEMENT &operator[] (const int index) const { return H[index]; }
		/**
		 *@brief copies an existing, not-guaranteed-to-be-heapified array into this heap. 
		 *
		 *@param set the data set to assign to the heap.
		 *@param _size the size of the data set.
		 */
		void AssignNewData(ELEMENT* set, int _size);
		/**
		 *@brief Heapifies the heap.
		 *
		 *@param i the index to start with.
		 */
		void Heapify(int i);
	};


#pragma endregion Classes

#pragma region Heap Functions

	// ---------------------------------------------------------
	//            Requested Function Declarations
	// ---------------------------------------------------------

	/**
	 * @brief Initializes a heap.
	 * 
	 * @param capacity The capacity to initially create the heap with.
	 * @return HEAP Returns a pointer to the created heap
	 * 
	 */
	inline HEAP Initialize(int capacity) { return HEAP(capacity); }
	/**
	 * @brief Fills a heap with the array of elements provided by A
	 * 
	 * @param heap The heap to fill.
	 * @param A The array of elements to fill with. 
	 * @param size the size of A
	 */
	void BuildHeap(HEAP &heap, ELEMENT* A, int size);
	/**
	 * @brief Inserts a new element with the given key value into the given heap.
	 * 
	 * @param heap The heap to insert.
	 * @param key The key value of the element being inserted into the heap
	 * @param flag Whether to print the heap before and after this operation.
	 */
	void Insert(HEAP &heap, int key, bool flag);
	/**
	 * @brief Deletes the smallest element and returns its key.
	 * 
	 * @param heap The heap to delete from.
	 * @param flag Whether to print the heap before and after this operation.
	 * @return int Returns the key of the removed element.
	 */
	int DeleteMin(HEAP &heap, bool flag);
	/**
	 * @brief Decrease key of a given element in a heap to the provided value 
	 * (Does no change when value is greater than original)
	 * 
	 * @param heap The heap to reflect this change on.
	 * @param index The index to access in the given heap.
	 * @param value The value to replace the key of the element if it's less than the key.
	 * @param flag Whether to print the heap before and after this operation.
	 */
	void DecreaseKey(HEAP &heap, int index, int value, bool flag);
	/**
	 * @brief Prints the given heap.
	 * 
	 * @param heap The heap to print.
	 */
	void printHeap(HEAP &heap);

	// ---------------------------------------------------------
	//            Helper Function Declarations
	// ---------------------------------------------------------
	
	/**
	 * @brief Gets the parent index of the given index.
	 * 
	 * @param i The index to get the parent index of.
	 * @return int Return the parent index.
	 */
	inline int Parent(int i) { return i / 2; }
	/**
	 * @brief Gets the left child index of the given index.
	 * 
	 * @param i The index to get the left child index of.
	 * @return int Return the left child index.
	 */
	inline int Left(int i) { return 2 * i; }
	/**
	 * @brief Gets the right child index of the given index.
	 * 
	 * @param i The index to get the right child index of.
	 * @return int Return the left child index.
	 */
	inline int Right(int i) { return 2 * i + 1; }

#pragma endregion Heap Functions

}