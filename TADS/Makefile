ARTEFACTS = $(BINARY)
UTIL = Queue.c Queue.h Stack.c Stack.h utils.c utils.h
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

zip:
	@zip -r 1.zip * 
