#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct No{
	int numero;
	struct No* prox;
} No;

No* criaNo(int valor){
	No* novoNo = (No*)malloc(sizeof(No));
	novoNo->numero = valor;
	novoNo->prox = NULL;
	return novoNo;
}
void insereNaCabeca(No**cabeca, int valor){
	No*novoNo = criaNo(valor);
	novoNo->prox = *cabeca;
	*cabeca = novoNo;
}
void imprimeLista(No*cabeca){
	No*temp = cabeca;
	while(temp != NULL){
		printf("%d -> ",temp->numero);
		temp = temp->prox;
	}
	printf("NULL\n");
}
void liberaLista(No*cabeca){
	No*temp;
	while(cabeca != NULL){
		temp = cabeca;
		cabeca = cabeca->prox;
		free(temp);
	}
}

main(){
	setlocale(LC_ALL, "Portuguese");

	No* cabeca = NULL;
	int qtd=0, i=0, num=0;
	
	printf("Informe a quantidade de inserções que deseja fazer: \n");
	scanf("%d",&qtd);
	for(i=0;i<qtd;i++){
		printf("Informe o %d número: \n",i+1);
		scanf("%d",&num);
		insereNaCabeca(&cabeca,num);
	}
	
	printf("Lista Encadeada: ");
	imprimeLista(cabeca);

	liberaLista(cabeca);
}
