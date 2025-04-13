CC =g++
CFLAGS = -c -Wall

all: prog

prog: lab_08_assignment.o
	$(CC) -o prog lab_08_assignment.o



lab_08_assignment.o:lab_08_assignment.cpp
	$(CC) $(CFLAGS) lab_08_assignment.cpp


clean:
	rm -f prog *.o