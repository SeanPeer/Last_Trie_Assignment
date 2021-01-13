CC=gcc
AR=ar

FLAGS= -Wall -g

all:  frequency	

frequency: Func.o main.o
	$(CC)  $(FLAGS) -o frequency main.o Func.o

main.o: main.c Trie.h  
	$(CC) $(FLAGS) -c main.c 

Func.o: Func.c Trie.h
	$(CC) $(FLAGS) -c Func.c


.PHONY: frequency  clean all 

clean:
	rm -f *.o *.a *.so  frequency 
