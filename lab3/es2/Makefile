all: remove_prev compile clean run

remove_prev:
	rm es2

compile:
	gcc -c es2.c -o es2.o
	gcc -o es2 	es2.o

clean:
	rm -f *.o

run:
	./es2
