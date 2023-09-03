#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#define tf 100
void levetor(int vetor[tf],int &tl);
void ordenaV(int v[tf],int tl){
	int i,j,menor,pos;
	for(i=0;i<tl-1;i++){
		menor=v[i];
		pos=i;
		for(j=i+1;j<tl;j++)
			if(menor>v[j]){
				menor=v[j];
				pos=j;
			}
		v[pos]=v[i];
		v[i]=menor;
	}
		
}
int busca(int vet[tf],int tl,int x){
	int pos=0;
	while(pos<tl && vet[pos]!=x)
		pos++;
	if(pos<tl)
		return pos;
	else
		return -1;
}

void frequencia(int vetor[tf],int tl,int &valor,int &qtdevezes)
{
	int i,j,cont=1;
	qtdevezes=0;
	clrscr();
	for(i=0;i<tl-1;i++)
	{
		cont=1;
		for(j=i+1;j<tl;j++)
		{
			if(vetor[i]==vetor[j])
			{
				cont++;
			}	
		}
		
		if(cont>qtdevezes)
		{
			qtdevezes=cont;
			valor=vetor[i];
		}
	}
	
}
int soma(int vet[tf],int tl){
	int soma=0;
	for(int i=0;i<tl;i++)
		soma+=vet[i];
	return soma;
}

void Levetor(int vetor[tf],int &tl)
{
	int num;
	clrscr();
	do
	{
		printf("Digite o numero da posicao [%d]: \n",tl);
		scanf("%d",&num);
		
		if(num>0)
		{
			vetor[tl]=num;
			tl++;	
		}
		
	}while(tl<tf&&num>0);
}

char menu()
{
	clrscr();
	printf("\n## Menu ##\n");
	printf("[A]Ler Vetor\n");
	printf("[B]Exibir Vetor\n");
	printf("[C]Frequencia\n");
	printf("[D]Consultar Elemento\n");
	printf("[E]Ordenar Vetor\n");
	printf("[F]Excluir Elemento\n");
	printf("[ESC]Sair\n");
	printf("\nOpcao: ");
	
	return toupper(getch());
}
void ExibirV(int vetor[tf], int tl){
	clrscr();
	printf("## Conteudo do vetor ##\n\n");
	if(tl==0)
		printf("Vetor Vazio!");
	else{
		printf("Vetor: [");
		for(int i=0;i<tl-1;i++)
			printf("%d ,",vetor[i]);
		printf("%d]\n",vetor[tl-1]);
	}
	getch();
}
void executar(){
	int v[tf],tam=0,numais,qtde,num;
	char tecla;
	
	do{
		tecla=menu();
		switch(tecla){
			case 'A':
				if(tam==tf)
					printf("Vetor Cheio!\n");
				else{
					Levetor(v,tam);
					printf("\nElementos Inseridos !\n");
				}
				getch();	
				break;
			case 'B':
				ExibirV(v,tam);
				break;
			case 'C':
				if(tam==0)
					printf("Vetor Vazio!");
				else{
					frequencia(v,tam,numais,qtde);
					printf("\nNumero de maior frequencia e: %d",numais);
					printf("\nQuantidade de vezes e: %d\n",qtde);
					getch();
				}
				break;
			case 'D':
				if(tam==0)
					printf("Vetor Vazio!");
				else{
					clrscr();
					printf("Numero para a consulta: ");
					scanf("%d",&num);
					int x=busca(v,tam,num);
					if(x>=0)
						printf("%d Esta Contido na pos.[%d] !",num,x);
					else
						printf("%d Nao esta contido !",num);
				}
				getch();
				break;
			case 'E':
				if(tam==0)
					printf("Vetor Vazio!");
				else{
					ordenaV(v,tam);
				}
				break;
		}
		
	}while(tecla!=27);
	
}
int main(void)
{
	executar();
	
	
	
	
	return 0;
}
