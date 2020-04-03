# definimos las siguientes variables:
# C++: indicará el compilador a usar
# C++.FLAGS: indica las opciones del compilador, en este caso -g para depurar.

PROGRAM_NAME = Calculator
OBJECTS = main_Calculator.cpp Calculator_t.cpp Languages_t.h
C++ = g++
C++.FLAGS = -g

calculator:
	$(C++) $(C++.FLAGS) $(OBJECTS) -o $(PROGRAM_NAME)

clean:
	rm $(PROGRAM_NAME)
