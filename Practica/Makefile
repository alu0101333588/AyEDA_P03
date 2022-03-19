TARGET  = ciclovida

# Select Compiler and flags
CC=g++
CFLAGS=-std=c++14 -g -Wall   # Compiler options (C++14, preserve debug symbols and warn all)


SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)

# Special include directories
INCLUDE = -I.

# Special libraries (none for now)
LIB =

$(TARGET): main.o Cell.o Grid.o State.h StateDead.o StateAlive.o GridWithOpenBorder.o GridWithPeriodicBorder.o GridWithReflectiveBorder.o
	$(CC) -o $@ $^ $(LIB)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

Cell.o: Cell.cpp Cell.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

Grid.o: Grid.cpp Grid.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

State.o: State.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

StateAlive.o: StateAlive.cpp StateAlive.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

StateDead.o: StateDead.cpp StateDead.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

GridWithReflectiveBorder.o: GridWithReflectiveBorder.cpp GridWithReflectiveBorder.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

GridWithOpenBorder.o: GridWithOpenBorder.cpp GridWithOpenBorder.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

GridWithPeriodicBorder.o: GridWithPeriodicBorder.cpp GridWithPeriodicBorder.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
	rm -f *~