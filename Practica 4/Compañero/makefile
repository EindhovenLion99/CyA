main: main_commenteraser.c++ alphabet.o state.o transition.o automaton.o commenteraser.o

	g++ -g -Wall -o programa main_commenteraser.c++ alphabet.o state.o transition.o automaton.o commenteraser.o

alphabet.o: alphabet.h alphabet.c++

	g++ -g -c alphabet.h alphabet.c++

state.o: state.h state.c++

	g++ -g -c state.h state.c++

transition.o: transition.h transition.c++ 

	g++ -g -c transition.h transition.c++ 

automaton.o: automaton.h automaton.c++ 

	g++ -g -c automaton.h automaton.c++ 

commenteraser.o: commenteraser.h commenteraser.c++ 

	g++ -g -c commenteraser.h commenteraser.c++ 

.PHONY:clean

clean:

	rm -rf *.o
	rm -rf *.gch
	rm programa
