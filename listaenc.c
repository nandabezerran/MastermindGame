//Fernanda Bezerra Nascimento - Matricula: 388834

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaenc.h"

typedef struct reg{
	char *cor;
} Cor;


typedef struct regU{
	long int x;
	struct regU *prox;

} senhausu;


void iniciarListaUsu(senhausu *pont){
	pont->prox=NULL;

}

void inserirlista(senhausu **psusu, long int x){
	senhausu *p;
	p = (senhausu*)malloc(sizeof(senhausu));
	p->x=x;
	p->prox=*psusu;
	*psusu=p;
}

int buscarlista(senhausu *psusu, long int x){
	senhausu *p;
	if (psusu == NULL)
		return 0;	
	p = psusu;
	while(p != NULL){
		if(p->x == x)
			return 1;	
		p = p->prox	;
	}
	return 0;
}
