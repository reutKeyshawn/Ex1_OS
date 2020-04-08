CC = gcc
HELLO_ARIEL_OBJ = hello_Ariel.o 

# program: main1_1.o hello_Ariel.o libAriel.so
# 	$(CC) main1_1.o hello_Ariel.o -o program

lib_ariel.so: $(HELLO_ARIEL_OBJ)
	$(CC) -shared -o $@ $^

main1_1: $(HELLO_ARIEL_OBJ) main1_2.o
	$(CC) -o $@ $^

main1_2: main1_2.o lib_ariel.so 
	$(CC) -o $@ $^
	
%.o: %.c
	$(CC) -fPIC -c $< 

clean: 
	rm -f *.o *.so