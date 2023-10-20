#include<stdio.h>

struct TpPessoa{
	int matricula;
	char nome[30];
};
void exibir(){
	FILE *PtrArq=fopen("Pessoas.dat","rb");
	TpPessoa x;
	while(fread(&x,sizeof(x),1,PtrArq)!=0){
		printf("Matricula: %d\n", x.matricula);
        printf("Nome: %s\n", x.nome);
	}
	fclose(PtrArq);
}
void cadastro(){
	FILE *PtrArq=fopen("Pessoas.dat","ab");
	TpPessoa x;
	printf("Matricula da pessoa: ");
	scanf("%d",&x.matricula);
	while(x.matricula>0){
		printf("Nome: ");
		fflush(stdin);
		gets(x.nome);
		fwrite(&x,sizeof(x),1,PtrArq);
		
		printf("Matricula da pessoa: ");
		scanf("%d",&x.matricula);
	}
	fclose(PtrArq);
}
int main(){
	cadastro();
	exibir();
	return 0;
}
