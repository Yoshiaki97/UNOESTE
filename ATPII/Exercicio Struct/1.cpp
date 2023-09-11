#include<stdio.h>
#include<conio2.h>
#include<string.h>
#define tf 5
struct TpEnt{
	char rua[50];
	char comp[30];
	char bairro[20];
	char cid[30];
	int num;
	int cep;
};
struct TpPessoa{
	char nome[30];
	TpEnt end;
	int telefone;
};
void ordena(TpPessoa vetor[tf],int tl){
	int i,j,me;
	TpPessoa temp;
	for(i=0;i<tl-1;i++){
		for(j=i+1;j<tl;j++)
			if(strcmp(vetor[j].nome,vetor[i].nome)<0)
                me=j;
			strcpy(temp.nome, vetor[i].nome);
            strcpy(temp.end.rua, vetor[i].end.rua);
            strcpy(temp.end.comp, vetor[i].end.comp);
            strcpy(temp.end.bairro, vetor[i].end.bairro);
            strcpy(temp.end.cid, vetor[i].end.cid);
            temp.end.num = vetor[i].end.num;
            temp.end.cep = vetor[i].end.cep;
            temp.telefone = vetor[i].telefone;

            strcpy(vetor[i].nome, vetor[me].nome);
            strcpy(vetor[i].end.rua, vetor[me].end.rua);
            strcpy(vetor[i].end.comp, vetor[me].end.comp);
            strcpy(vetor[i].end.bairro, vetor[me].end.bairro);
            strcpy(vetor[i].end.cid, vetor[me].end.cid);
            vetor[i].end.num = vetor[me].end.num;
            vetor[i].end.cep = vetor[me].end.cep;
            vetor[i].telefone = vetor[me].telefone;

            strcpy(vetor[me].nome, temp.nome);
            strcpy(vetor[me].end.rua, temp.end.rua);
            strcpy(vetor[me].end.comp, temp.end.comp);
            strcpy(vetor[me].end.bairro, temp.end.bairro);
            strcpy(vetor[me].end.cid, temp.end.cid);
            vetor[me].end.num = temp.end.num;
            vetor[me].end.cep = temp.end.cep;
            vetor[me].telefone = temp.telefone;	
	}
}
void cadastro(TpPessoa x[tf],int &tl){
	int i;
	char aux[30];
	printf("Nome[%d]: ",tl);
	gets(aux);
	while(tl<tf && strcmp(aux,"\0")!=0){
		strcpy(x[tl].nome,aux);
		printf("Endereco:\n   Rua: ");
		gets(x[tl].end.rua);
		printf("   num.: ",x[i].end.num);
		scanf("%d",&x[tl].end.num);
		printf("   Compl.: ",x[i].end.comp);
		fflush(stdin);
		gets(x[tl].end.comp);
		printf("   Bairro: ",x[i].end.bairro);
		gets(x[tl].end.bairro);
		printf("   Cidade: ",x[i].end.cid);
		gets(x[tl].end.cid);
		printf("   CEP: ",x[i].end.cep);
		scanf("%d",&x[tl].end.cep);
		printf("Telefone: ",x[i].telefone);
		scanf("%d",&x[tl].telefone);
		tl++;
		printf("\nNome[%d]: ",tl);
		fflush(stdin);
		gets(aux);
	}
}
void exibe(TpPessoa x[tf],int tl){
	for(int i=0;i<tl;i++){
		printf("Nome: %s\n",x[i].nome);
		printf("Endereco:\n   Rua: %s\n",x[i].end.rua);
		printf("   num.: %d\n",x[i].end.num);
		printf("   Compl.: %s\n",x[i].end.comp);
		printf("   Bairro: %s\n",x[i].end.bairro);
		printf("   Cidade: %s\n",x[i].end.cid);
		printf("   CEP: %d\n",x[i].end.cep);
		printf("Telefone: %d\n\n",x[i].telefone);
	}
		
}
int main(){
	TpPessoa x[tf]={"Jorge","Esperanca do Nada","Casa","Vila Top","Presidente Prudente",69,75290043,18987462340,
					"Ana","Washington Luiz","Casa","Jd.Jardim","Londrina",77,47508932,18968583987};
	int tl=2;
	cadastro(x,tl);
	ordena(x,tl);
	clrscr();
	exibe(x,tl);
}
