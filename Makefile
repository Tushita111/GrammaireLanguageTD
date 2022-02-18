ifdef debug
	debug_flag = -D MAP=1
else
	debug_flag =
endif # Usage : make main debug=1 for debugging  
ifdef valgrind
	debug_flags = $(debug_flag) -g
else
	debug_flags = $(debug_flag)
endif # Usage : make main valgrind=1 for debugging  

flags = $(debug_flags) -pedantic -ansi -Wall -std=c++11


main: main.o lexer.o symbole.o automate.o etat.o expression.o 
	g++ $(flags) ./*.o -o main

%.o: %.cpp
	g++ -c $(flags) $< -o $@

clean:
	rm -f ./*.o ./main