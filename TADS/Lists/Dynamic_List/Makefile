ARTEFACTS = $(BINARY) dyna.o
UTIL = dyna.c dyna.h
BINARY = main
MAIN = main.c

all:
	gcc -Wall -g $(UTIL) $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -lm -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm $(ARTEFACTS)
