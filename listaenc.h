//Fernanda Bezerra Nascimento - Matricula: 388834

typedef struct reg Cor;
typedef struct regU senhausu; 

void iniciarListaUsu(senhausu *pont);

void inserirlista(senhausu **psusu, long int x);
//Recebe um long int, insere na lista encadeada e n�o retorna nada

int buscarlista(senhausu *psusu, long int x);
//Recebe um long int, procura na lista encadeada se ele existe, se sim retorna 1 se nao retorna 0
