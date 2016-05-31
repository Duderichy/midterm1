# makefile
all: midterm1.c timer.h timer.c adjust.c adjust.h
	gcc timer.h timer.c adjust.c midterm1.c adjust.h
