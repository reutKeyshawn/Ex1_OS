CC = gcc
HELLO_ARIEL_OBJ = hello_ariel.o 

all: main1_1 main1_2 main1_3

lib_ariel.so: $(HELLO_ARIEL_OBJ)
	$(CC) -shared -o $@ $^
	# sudo cp $@ /usr/lib

main1_1: $(HELLO_ARIEL_OBJ) main1_1.o
	$(CC) -o $@ $^

main1_2: main1_2.o lib_ariel.so 
	$(CC) -o $@ $< -l_ariel

main1_3: main1_3.o lib_ariel.so
	$(CC) -o $@ $< -ldl

%.o: %.c
	$(CC) -fPIC -c $< 

clean: 
	rm -f *.o *.so main1_1 main1_2 main1_3