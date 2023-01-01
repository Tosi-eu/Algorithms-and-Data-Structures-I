ARTEFACTS = $(BINARY) static_list.o
UTIL = static_list.c static_list.h
BINARY = main
MAIN = main.c

run: main
	./$(BINARY)
	
main: static_list.o main.c
	gcc -o main static_list.o main.c
	
static_list.o: $(UTIL)
	gcc -c static_list.c

debug:
	gcc -DDEBUG -lm -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full -s --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	rm $(ARTEFACTS)