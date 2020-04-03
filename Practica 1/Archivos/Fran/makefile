main: main_lenguaje.cpp lenguaje.o cadena.o

	valgrind g++ -g -o calculadora_l main_lenguaje.cpp lenguaje.o cadena.o 


lenguaje.o: lenguaje.h lenguaje.c++

	g++ -g -c lenguaje.h lenguaje.c++

cadena.o: cadena.h cadena.c++

	g++ -g -c cadena.h cadena.c++

.PHONY:clean

clean:

	rm -rf *.o
	rm -rf *.gch
	rm calculadora_l
