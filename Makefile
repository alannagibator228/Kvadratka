all: Kvadratka

Kvadratka: solver.o tester.o main.o
	gcc main.o tester.o solver.o -o Kvadratka -lm

main.o: main.c
	gcc -c main.c -o main.o -lm

solver.o: solver.c 
	gcc -c solver.c -o solver.o -lm
tester.o: tester.c 
	gcc -c tester.c -o tester.o -lm