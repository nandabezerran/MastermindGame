//Fernanda Bezerra Nascimento - Matricula: 388834

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "listaenc.c"
#include "cores.h"

int main(int argc, char *argv[]){

	//Vetor base com as cores possiveis
	Cor base[6];
	base[0].cor = "vm";
	base[1].cor = "vd";
	base[2].cor = "am";
	base[3].cor = "az";
	base[4].cor = "mg";
	base[5].cor = "ci";
	
	
	int PC, Lim, N, *vetcomp, *vetusu, cod, contTent, iaux = 0;
	char *strusu;
	long int auxvetusu = 0;
	senhausu *psusu;
	//Iniciacao do Jogo	
	printf("%s || Bem-vindo ao Jogo da senha ||\n", COR_NORMAL);
	printf("Por favor, digite a possibilidade de cores entre 3 e 6 \n>>> ");
	scanf("%d",&PC);
	printf("Por favor, digite o limite de tentativas de adivinhacao a partir de 1 \n>>> ");
	scanf("%d",&Lim);
	printf("Por favor, digite o tamanho da senha entre 4 a 12 \n>>> ");
	scanf("%d",&N);

	//Validacao entradas
	while(PC < 3 || PC > 6){
		
			printf("Possibilidade de cores inv�lida digite novamente outra entre 3 e 6:\n>>> ");
			scanf("%d",&PC);
		
	}
	while(Lim < 1){
		
			printf("Limite de tentativas de adivinha��o inv�lido digite outro maior que 1:\n>>> ");
			scanf("%d", &Lim);
		
	}
	while(N < 4 || N > 12){
		
			printf("Tamanho de senha inv�lido digite novamente outro entre 4 e 12:\n>>> ");
			scanf ("%d", &N);	
		
	}
	//Mostrando para o usuario as cores disponiveis de acordo com PC
	if (PC == 3){
		printf("Entre uma combina��o de %d elementos dentre as 3 cores seguintes\n%s- vm: vermelho\n%s- vd: verde\n%s- am: amarelo\n", N, COR_VERMELHO, COR_VERDE, COR_AMARELO);
	}

	if (PC == 4){
		printf("Entre uma combina��o de %d elementos dentre as 4 cores seguintes\n%s- vm: vermelho\n%s- vd: verde\n%s- am: amarelo\n%s- az: azul\n", N, COR_VERMELHO, COR_VERDE, COR_AMARELO, COR_AZUL);
	}

	if (PC == 5){
		printf("Entre uma combina��o de %d elementos dentre as 5 cores seguintes\n%s- vm: vermelho\n%s- vd: verde\n%s- am: amarelo\n%s- az: azul\n%s- mg: magenta\n", N, COR_VERMELHO, COR_VERDE, COR_AMARELO, COR_AZUL, COR_MAGENTA);
	}
	
	if (PC == 6){
		printf("Entre uma combina��o de %d elementos dentre as 6 cores seguintes\n%s- vm: vermelho\n%s- vd: verde\n%s- am: amarelo\n%s- az: azul\n%s- mg: magenta\n%s- ci: ciano\n", N, COR_VERMELHO, COR_VERDE, COR_AMARELO, COR_AZUL, COR_MAGENTA, COR_CIANO);

	}

	//Random senha computador
	vetcomp = (int *)malloc(N * sizeof(int)); //Aloca��o do vetor de inteiros para a senha do computador
	srand((unsigned)time(NULL));
	while ((iaux) < N){//La�o para a senha do computador ter o tamanho indicado pelo usuario
		
		cod = (rand()%PC);//Randomiza��o de cada elemento da senha do computador, nas possibilidades de cores indicadas pelo usuario
		vetcomp[iaux] = cod;//Associa��o de cada senha
		iaux++;
	}
	

	//Iniciando lista usuario
	psusu = (senhausu *) malloc(sizeof(senhausu *));
	iniciarListaUsu(psusu);
	

	//La�o para rodar o jogo ate acabar as tentativas
	contTent = 0;
	while (contTent < Lim){
		contTent++;


	//Alocando a senha
		strusu = ((char*) malloc(((N*2 )+ ((N-1) * 2)) * sizeof(char)));//Alocando a string para senha do usuario
		
		if (strusu == NULL){
			printf("Mem�ria insuficiente");
			return EXIT_FAILURE;
		}

		
	//Lendo a senha do usuario
		else{
			
			int contsi = 1;//Inicialiaza��o do contador que indica se o usuario ja colocou aquela senha
			int contquebras = 0;
			int validcor=1;
			char *separador;
			int i;
				while (contquebras != N || validcor !=0 || contsi != 0){//La�o de repeti��o caso a senha seja invalida
					
						contquebras = 0;//contador para validar o tamanho da senha
						validcor= 0;//validador para ver se as cores estao dentro da possibilidade de cores
						printf("%sEntre sua tentativa separando os elementos por virgula:\n>>> ", COR_NORMAL);
						getchar();

						scanf("%[^\n]s",strusu);
						fflush(stdin);
				
	//Quebrando a senha do usuario
				
				
						vetusu = (int *)malloc(N * sizeof(int));//Aloca��o do vetor de inteiros para a senha do usuario
				
						separador = strtok(strusu, ", ");//fun��o para separar a senha em cada ", "
						i=0;
				
						while(separador != NULL){	
							for(iaux = 0; iaux < 6; iaux++){
								if (strcmp(base[iaux].cor, separador) == 0){
									vetusu[i] = iaux;//Associando cada cor a um numero para formar o vetor senha do usuario
									contquebras++;
			//Mostrando a propria senha para o usuario
									if (iaux == 0){
										printf("%so ", COR_VERMELHO);							
									}
									if (iaux == 1){
										printf("%so ", COR_VERDE);							
									}
									if (iaux == 2){
										printf("%so ", COR_AMARELO);							
									}
									if (iaux == 3){
										printf("%so ", COR_AZUL);							
									}
									if (iaux == 4){
										printf("%so ", COR_MAGENTA);							
									}
									if (iaux == 5){
										printf("%so ", COR_CIANO);							
									}	
	
									i++;
								}
							
							}
										
							separador = strtok(NULL, ", ");//passando para o proximo componente da string								
						}

						for (i=0; i <N; i++){
							if (vetusu[i]>=PC)//se houver algum int no vetor maior ou igual a possibilidade de cores, a senha esta invalida
								validcor = 1;						
						}
					if (validcor==1)
						printf("\n%sCores invalidas\n", COR_NORMAL);
					if (contquebras != N){
						printf("\n%sTamanho invalido de senha\n", COR_NORMAL);
					}
				


	//Transformando o a senha do usuario em um unico long int, para salvar na lista encadeada
			auxvetusu=0;//zerando a variavel
			for (i=0; i<N; i++){
				auxvetusu += (pow(10,(6-i))*(vetusu[i])) + 1;//Aqui, uma na variavel aux � formado um unico long int correspondente a o vetor senha usuario
				
			}

	//Buscando se essa senha ja foi utilizada
			contsi = buscarlista(psusu, auxvetusu);//Se a senha for encontrada retorna 1, se n�o retorna 0
					
			if(contsi == 1){
				printf("%s A senha ja existe, tente novamente\n", COR_NORMAL);
			}						 
			
		}

	//Inserindo a senha do usuario
		inserirlista(&psusu, auxvetusu);//Inserindo a senha somente se nao for encontrada na lista
	
	//Comparando as senhas e mostrando ao usuario ! e @;
	// Mostrar !'s e @'s de modo que faz a verifica��o de caso a cor seja a mesma e na mesma posi��o, mostrar @
	// e caso for uma cor igual e em coloca�ao diferente por o !, sendo que caso seja posto um ou outro
	// a verica��oda proxima cor ser� a partir da pr�xima j� que a mesma ja est� no local certo
		int contig, ind, ind1, buscaSenhaComp;
		contig=0;
		buscaSenhaComp = 0;
		printf("%s -> ", COR_NORMAL);
		for (ind = 0; ind < N; ind++){
			for (ind1 = buscaSenhaComp; ind1 < N; ind1++){	
				if ((vetusu[ind] == vetcomp[ind1]) && ind==ind1){
					printf("@");
					ind1 = N;
					contig++;
					buscaSenhaComp++;
				}
				else if((vetusu[ind] == vetcomp[ind1]) && ind!=ind1){
					if(contig == (N-1)){
						printf("@");
						contig++;//contador de igualdade entre as senhas
						buscaSenhaComp++;
					}
					printf("!");
					ind1 = N;
				}
			}
		}
				
	//Mostrar ao usuario se acertou ou erro

		if (contig == N){
			printf("\nVoc� acertou em %d tentativas :D\n", contTent);
				return EXIT_SUCCESS;	
		}

		else{
			
			printf("\nEssa foi a tentativa de numero %d. Voce nao acertou :( \n", contTent);
									
														
		}

		free(vetusu);// liberando o vetor da senha do usuario
							
		}
		
	}
	printf("\nA senha do computador e:\n>>> ");
			for(iaux = 0; iaux < N; iaux++){
				if (vetcomp[iaux] == 0){
					printf("%so ", COR_VERMELHO);							
				}
				if (vetcomp[iaux] == 1){
					printf("%so ", COR_VERDE);							
				}
				if (vetcomp[iaux] == 2){
					printf("%so ", COR_AMARELO);							
				}
				if (vetcomp[iaux] == 3){
					printf("%so ", COR_AZUL);							
				}
				if (vetcomp[iaux] == 4){
					printf("%so ", COR_MAGENTA);							
				}
				if (vetcomp[iaux] == 5){
				printf("%so ", COR_CIANO);							
				}	
			}
	printf("\n");
	return EXIT_SUCCESS;

}
