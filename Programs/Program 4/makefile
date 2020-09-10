# First Make File
# This file will compile the program and exicute it

exec: exe
	./exe

exe: main.o
	gcc -o exe main.o

main.o: main.c
	gcc -c main.c

clean: 
	rm -rf *.o
	rm -rf exe
