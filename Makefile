CC = gcc
OBJECT_LIB = hello_Ariel.o 
OBJECT_MAIN = main1_1.o

program: main1_1.o hello_Ariel.o libAriel.so
	$(CC) main1_1.o hello_Ariel.o -o program

libAriel.so: $(OBJECT_LIB) hello_Ariel.h
	$(CC) -shared -o libAriel.so $(OBJECT_LIB)

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) -c main1_1.c

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) -c hello_Ariel.c

clean: 
	rm -f *.o