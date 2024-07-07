CC = g++

PROGRAM = hw04 
OBJS = hw02.o add_student_record.o delete_student_record.o display_all_records.o save_exit.o
HEADERS = hw04.h

# Default make target
all: $(PROGRAM)

# Link the program
$(PROGRAM): $(OBJS)
        $(CC) $(OBJS) -o $(PROGRAM)

		 hw04.cpp hw04f.cpp hw04.scr Makefile

# Compilation rules for each object file
hw02.o: hw04.cpp $(HEADERS)
        $(CC) -c hw04.cpp -o hw04.o

hw04f.o: hw04f.cpp $(HEADERS)
        $(CC) -c hw04f.cpp -o hw04f.o


clean: 
	rm -f *.o
	rm -f hw02 
	rm -f *.scr
	rm -f *.tar 

tar: 
	tar cf hw04.tar hw04.h hw04.cpp hw04f.cpp hw04.scr Makefile