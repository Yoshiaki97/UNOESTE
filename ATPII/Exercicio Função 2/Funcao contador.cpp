#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#define tf 100
void levetor(int vetor[tf],int &tl);
void ExibirV(int vetor[tf], int tl);
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
	for(i=0;i<tl-1;i++){
		cont=1;
		for(j=i+1;j<tl;j++)
			if(vetor[i]==vetor[j])
				cont++;
		if(cont>qtdevezes){
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
int binario(int x){
	int bin=0,mult=1;
	while(x>0){
		bin+=(x%2)*mult;
		x/=2;
		mult*=10;
	}
	return bin;
}
void Sub(int vet1[tf],int vet2[tf],int vet3[tf],int TL1,int TL2,int &TL3){
	int i;
	TL3=0;
	for(i=0;i<TL1;i++){
		if(busca(vet2,TL2,vet1[i])==-1)
			if(busca(vet3,TL3,vet1[i])==-1)
				vet3[TL3++]=vet1[i];
	}
}
void Intersec(int vet1[tf],int vet2[tf],int vet3[tf],int TL1,int TL2,int &TL3){
	int i;
	TL3=0;
	for(i=0;i<TL1;i++){
		if(busca(vet2,TL2,vet1[i])>=0)
			if(busca(vet3,TL3,vet1[i])==-1)
				vet3[TL3++]=vet1[i];
	}
}
void ordena(int v[tf],int tl){
	int i,j,menor,pos;
	for(i=0;i<tl-1;i++){
		menor=v[i];
		pos=i;
		for(j=i+1;j<tl;j++)
			if(v[j]<menor){
				menor=v[j];
				pos=j;
			}
		v[pos]=v[i];
		v[i]=menor;
	}
}
void Merge(int vet1[tf],int vet2[tf],int vet3[tf*2],int TL1,int TL2,int &TL3){
	int i=0,j=0;
	TL3=0;
	ordena(vet1,TL1);
	ordena(vet2,TL2);
	while(i<TL1 && j<TL2){
		if(vet1[i]<vet2[j]){
			if(busca(vet3,TL3,vet1[i])==-1)
				vet3[TL3++]=vet1[i];
			i++;
		}
		else{
			if(busca(vet3,TL3,vet2[j])==-1)
				vet3[TL3++]=vet2[j];
			j++;
		}
	}
	while(i<TL1){
		if(busca(vet3,TL3,vet1[i])==-1)
			vet3[TL3++]=vet1[i];
		i++;
	}
	while(j<TL2){
		if(busca(vet3,TL3,vet2[j])==-1)
			vet3[TL3++]=vet2[j];
		j++;
	}
		
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
void Exer_5(int vet1[tf],int TL1,int vet2[tf],int &TL2,int vet3[tf],int TL3){
	Levetor(vet2,TL2);
	clrscr();
	printf("## Vetores ##\n\n");
	printf("Vet1: [");
	ExibirV(vet1,TL1);
	printf("Vet2: [");
	ExibirV(vet2,TL2);

	Sub(vet1,vet2,vet3,TL1,TL2,TL3);
	printf("\n[A] Vet3: [");
	ExibirV(vet3,TL3);
	Intersec(vet1,vet2,vet3,TL1,TL2,TL3);
	printf("\n[B] Vet3: [");
	ExibirV(vet3,TL3);
	Merge(vet1,vet2,vet3,TL1,TL2,TL3);
	printf("\n[C] Vet3: [");
	ExibirV(vet3,TL3);
}
char menu()
{
	clrscr();
	printf("## Menu ##\n\n");
	printf("[A]Ler Vetor\n");
	printf("[B]Exibir Vetor\n");
	printf("[C]Frequencia\n");
	printf("[D]Soma\n");
	printf("[E]Consultar Elemento\n");
	printf("[F]IntToBin\n");
	printf("[G]Exercicio 5\n");
	printf("[J]Ordenar Vetor\n");
	printf("[K]Excluir Elemento\n");
	printf("[ESC]Sair\n");
	printf("\nOpcao: ");
	
	return toupper(getch());
}
void ExibirV(int vetor[tf], int tl){
	
	
	if(tl==0)
		printf("Vetor Vazio!");
	else{	
		for(int i=0;i<tl-1;i++)
			printf("%d ,",vetor[i]);
		printf("%d]\n",vetor[tl-1]);
	}
}
void executar(){
	int v[tf],tam=0,numais,qtde,num;
	int v2[tf],tam2=0,v3[tf*2],tam3=0;
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
				clrscr();
				printf("## Conteudo do vetor ##\n\n");
				if(tam==0)
					printf("Vetor Vazio!");
				else{
					printf("Vetor: [");
					ExibirV(v,tam);
				}
				getch();
				break;
			case 'C':
				if(tam==0)
					printf("Vetor Vazio!");
				else{
					frequencia(v,tam,numais,qtde);
					printf("\nNumero de maior frequencia e: %d",numais);
					printf("\nQuantidade de vezes e: %d\n",qtde);
				}
				getch();
				break;
			case 'D':
				if(tam==0)
					printf("Vetor Vazio!");
				else{
					num=soma(v,tam);
					printf("\nSoma: %d",num);
				}
				getch();
				break;
			case 'E':
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
			case 'F':
				clrscr();
				printf("Numero para a consulta: ");
				scanf("%d",&num);
				printf("Numero transformado: %d",binario(num));
				getch();
				break;
			case 'G':
				if(tam==0)
					printf("Vetor Vazio!");
				else
					Exer_5(v,tam,v2,tam2,v3,tam3);
				getch();
				break;
			case 'J':
				if(tam==0)
					printf("Vetor Vazio!");
				else
					ordena(v,tam);
				break;
		}
		
	}while(tecla!=27);
	
}
int main(void)
{
	executar();
	
	return 0;
}
