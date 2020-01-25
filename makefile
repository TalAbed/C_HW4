CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=trie.o
FLAGS= -Wall -g

all: frequency
frequency: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o frequency $(OBJECTS_MAIN) trie.o
trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c
main.o: main.c trie.o
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so frequency

