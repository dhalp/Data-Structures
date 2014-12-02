EXPENDABLES = question23.o question23 bintree.o 

all:
	@make $(EXPENDABLES)

bintree.o: bintree.cpp bintree.h
	g++ -Wall -std=c++0x -g -c bintree.cpp -o bintree.o

# this compiles your test program and your binary_search_tree classes together
question23: question23.o binary_search_tree.o bintree.o
	g++ -Wall -std=c++0x -g question23.o bintree.o binary_search_tree.o -o question23

question23.o: binary_search_tree.h binary_search_tree.o bintree.h question23.cpp
	g++ -Wall -std=c++0x -g -c question23.cpp -o question23.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)
