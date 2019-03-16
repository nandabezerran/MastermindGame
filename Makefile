all: CORES LISTAENC
	gcc main.c listaenc.h cores.h -lm -o main
CORES: LISTAENC
	gcc -c cores.h
LISTAENC:
	gcc -c listaenc.h listaenc.c
