all:compile run memcheck clean
compile:program4.o tournament.o
	gcc tournament.o program4.o -o program4
program4.o:program4.c
	gcc -c program4.c -o program4.o
tournament.o:tournament.c
	gcc -c tournament.c -o tournament.o
run:compile
	./program4
memcheck:
	valgrind ./program4
clean:
	rm -rf program4.o tournament.o
