all: remove_prev compile clean run

remove_prev:
	rm es1

compile:
	gcc -c es1.c -o es1.o
	gcc -o es1 	es1.o

clean:
	rm -f *.o

run:
	./es1 &
