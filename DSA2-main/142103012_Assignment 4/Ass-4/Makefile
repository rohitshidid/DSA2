final: main.o Avl.o
	cc main.o Avl.o -o final
main.o: main.c
	cc -c main.c
Avl.o: Avl.h Avl.c
	cc -c Avl.c
clean:
	rm *.o final
