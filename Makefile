# makefile

all: midterm1.c timer.c adjust.c
	gcc timer.c adjust.c midterm1.c -o midterm1.o

clean :
	rm -f *.o
	rm -f *.*~
