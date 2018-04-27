README {#index}
=========

This program implements an array-based, min-heap data structure with dynamic capacity and provides terminal interaction functionality allowing the user to interact with the data structure. Written in C++.

## File List

* heap.cpp
* heap.h
* main.cpp
* README.md 
* util.cpp
* util.h
* HEAPinput.txt
* Makefile
* Doxyfile
* html.zip

## Getting Started

Unzip all file contents into the same folder. 

### Prerequisites

* g++ compiler
* gnu++11 (gnu++0x)
* anything that can execute linux command `make`

### Installing

1. Navigate to the contents-containing folder directory in your terminal.

2. If this has not previously been run or a file has been changed:	`make`

3. To run:	`./run`

##Generating Documentation
For the user's convenience, the generated html.zip is already included

1. If html.zip is already made, skip to step 5.

2. Ensure you have Doxygen installed

3. In the directory terminal: `doxygen <Doxyfile>`

4. with xgd-open installed, in the same directory: `xdg-open ./html/index.html`

5. Enter: `unzip html.zip`

##Commands

* `S` Exit the program
* `C i` Initialize a heap with capacity given by `i`.
* `R` Read HEAPinput.txt and will make a heap using its contents.
* `W` Display the current heap contents.
* `I k f` Insert an element with the value `k` into the heap. Having `f` be non-zero will print the heap before and after the change. 
* `D f` Delete the head element in the heap and print its value. Having `f` be non-zero will print the heap before and after the change. 
* `K i v f` Decrease the key value of the element at heap index `i` to value `v` (does nothing if its value is already lower than or equal to `v`). Having `f` be non-zero will print the heap before and after the change. 

## Authors

* **Patrick Valgento** 
