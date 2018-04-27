EXEC = run
CC = g++
CFLAGS = -c -Wall
SUPPORT = -std=gnu++0x
REGION_WARNINGS = -Wno-unknown-pragmas #just to hide #pragma region warnings

$(EXEC) :main.o util.o heap.o
	$(CC) -o $(EXEC) main.o util.o heap.o

main.o: main.cpp
	$(CC) $(CFLAGS) $(SUPPORT) $(REGION_WARNINGS) main.cpp 
util.o :util.h util.cpp
	$(CC) $(CFLAGS) $(SUPPORT) $(REGION_WARNINGS) util.cpp
heap.o :heap.h heap.cpp
	$(CC) $(CFLAGS) $(SUPPORT) $(REGION_WARNINGS) heap.cpp
clean :
	rm *.o
