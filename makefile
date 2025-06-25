#yoav1.nach@gmail.com

all: Main.o MyContainer.o
	g++ -o program Main.o MyContainer.o

Main.o: Main.cpp
	g++ -c Main.cpp

MyContainer.o:MyContainer.cpp
	g++ -c MyContainer.cpp

clean:
	rm -f Main.o MyContainer.o program test tests.o

test: tests.o MyContainer.o
	g++  MyContainer.cpp  tests.o -o test

tests.o: tests.cpp
	g++ -c -o tests.o tests.cpp

valgrind: all
	valgrind ./program