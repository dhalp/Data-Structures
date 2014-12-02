# Make file for HW4, CSCI2270
# All compilations occur with -Wall to print warnings, and -g to allow gdb debugging.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = question20 question20.o

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your doubly_linked_list class together
question20: question20.o doubly_linked_list.o
	g++ -std=c++0x -Wall -g question20.o doubly_linked_list.o -o question20 

# this compiles your test program, which is executable
question20.o: doubly_linked_list.h question20.cpp
	g++ -std=c++0x -Wall -g -c question20.cpp -o question20.o

# this deletes all the output files
clean:
	rm -f $(EXPENDABLES)
