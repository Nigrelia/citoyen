citoyen:citoyen.o main.o
	gcc citoyen.o main.o -o citoyen
citoyen.o:citoyen.c
	gcc -c citoyen.c
main.o:main.c
	gcc -c main.c
