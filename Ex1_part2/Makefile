CC = gcc
FLAG = -Wall
MAIN = main2_1 main2_2 main2_3 

all: $(MAIN) main2_4
	./main2_4

main2_1: main2_1.c
	$(CC) $(FLAG) main2_1.c -g -o main2_1

main2_2: main2_2.c
	$(CC) $(FLAG) main2_2.c -g -o main2_2

main2_3: main2_3.c
	$(CC) $(FLAG) main2_3.c -o main2_3

main2_4: main2_4.c
	$(CC) $(FLAG) main2_4.c -o main2_4

.PHONY: clean
clean: 
	rm -f *.o *.a *.so $(MAIN) main2_4
