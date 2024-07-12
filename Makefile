CC = g++
CXXFLAGS = -std=c++11

PROGRAM = hw04 
OBJS = hw04.o hw04f.o
HEADERS = hw04.h

# Default make target
all: clean $(PROGRAM)

# Link the program
$(PROGRAM): $(OBJS)
	$(CC) $(OBJS) $(CXXFLAGS) -o $(PROGRAM)

# Compilation rules for each object file
hw04.o: hw04.cpp $(HEADERS)
	$(CC) $(CXXFLAGS) -c hw04.cpp -o hw04.o

hw04f.o: hw04f.cpp $(HEADERS)
	$(CC) $(CXXFLAGS) -c hw04f.cpp -o hw04f.o

clean: 
	rm -f *.o
	rm -f hw04 
	rm -f *.scr
	rm -f *.tar 

tar: 
	tar cf hw04.tar hw04.h hw04.cpp hw04f.cpp hw04.scr Makefile
