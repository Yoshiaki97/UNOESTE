#include<stdio.h>
#include<conio2.h>
#include<ctype.h>
#include<string.h>
#define tf 100
struct TpEnt{
	char rua[40];
	char comp[30];
	char bairro[20];
	char cid[30];
	char estado[20];
	char pais[20];
	int num;
	int cep;
};
struct TpData{
	int d,m,a;
};
struct TpPessoa{
	char nome[30];
	char email[30];
	TpEnt end;
	TpData data;
	int tele;
	
};
int buscaOrde(TpPessoa x[tf],int tl,char nome[30]){
	int pos=0;
	while(pos<tl && stricmp(x[pos].nome,nome)<0)
		pos++;
	return pos;
}
int busca(TpPessoa x[tf],int tl,char nome[30]){
	int pos=0;
	while(pos<tl && stricmp(x[pos].nome,nome)!=0)
		pos++;
	return pos;
}
void ExibePos(TpPessoa x[tf],int i){
	printf("\n Nome: %s\n",x[i].nome);
	printf(" E-mail: %s\n",x[i].email);
	printf(" Endereco:\n   Rua: %s\n",x[i].end.rua);
	printf("   num.: %d\n",x[i].end.num);
	printf("   Compl.: %s\n",x[i].end.comp);
	printf("   Bairro: %s\n",x[i].end.bairro);
	printf("   Cidade: %s\n",x[i].end.cid);
	printf("   Estado: %s\n",x[i].end.estado);
	printf("   Pais: %s\n",x[i].end.pais);
	printf("   CEP: %d\n",x[i].end.cep);
	printf(" Telefone: %d\n",x[i].tele);
	printf(" Aniversario: %d/%d/%d\n",x[i].data.d,x[i].data.m,x[i].data.a);
}
void ExibeA(TpPessoa x[tf],int i){
	printf("\n Nome: %s\n",x[i].nome);
	printf(" E-mail: %s\n",x[i].email);
	printf(" Telefone: %d\n",x[i].tele);

}
void DiaMesAni(TpPessoa x[tf],int tl){
	int dia,mes,j=0,i;
	clrscr();
	printf(" ### dia e mes de Aniversario ###\n\n");
	printf(" Digite o dia e o mes[dia mes]: ");
	scanf("%d%d",&dia,&mes);
	for(i=0;i<tl;i++){
		if(x[i].data.d==dia && x[i].data.m==mes){
			ExibePos(x,i);
			j=1;
		}	
	}
	if(j==0)
		printf(" Nenhum aniversariante no dia[%d] e mes[%d] !",dia,mes);
	getch();
}
void MesAni(TpPessoa x[tf],int tl){
	int mes,j=0,i;
	clrscr();
	printf(" ### Mes de Aniversario ###\n\n");
	printf(" Digite o mes: ");
	scanf("%d",&mes);
	for(i=0;i<tl;i++){
		if(x[i].data.m==mes){
			ExibePos(x,i);
			j=1;
		}	
	}
	if(j==0)
		printf(" Nenhum aniversariante no mes %d!",mes);
	getch();
}
void BuscaNome(TpPessoa x[tf],int tl){
	char nome[20],aux[20];
	int i,j,y=0;
	clrscr();
	printf(" ### Busca primeiro Nome ###\n\n");
	printf(" Digite o nome: ");
	gets(nome);
	for(i=0;i<tl;i++){
		j=0;
		while(x[i].nome[j]!=' ' && x[i].nome[j]!='\0'){
			aux[j]=x[i].nome[j];
			j++;
		}
		aux[j]='\0';
		if(stricmp(aux,nome)==0){
			ExibePos(x,i);
			y=1;
		}
	}
	if(y==0)
		printf(" Nome nao Encontrado!");
	getch();
}
void cadastrar(TpPessoa x[tf],int &tl){
	char nome[30];
	int pos,i;
	clrscr();
	printf(" ### Cadastrar Pessoa ###\n\n");
	printf(" Digite o nome: ");
	gets(nome);
	while(tl<tf && stricmp(nome,"\0")!=0){
		pos=buscaOrde(x,tl,nome);
		for(i=tl;i>pos;i--)
			x[i]=x[i-1];
		strcpy(x[pos].nome,nome);
		printf(" E-mail: ");
		gets(x[pos].email);
		printf(" Endereco:\n   Rua: ");
		gets(x[pos].end.rua);
		printf("   num.: ");
		scanf("%d",&x[pos].end.num);
		printf("   Compl.: ");
		fflush(stdin);
		gets(x[pos].end.comp);
		printf("   Bairro: ");
		gets(x[pos].end.bairro);
		printf("   Cidade: ");
		gets(x[pos].end.cid);
		printf("   Estado: ");
		gets(x[pos].end.estado);
		printf("   Pais: ");
		gets(x[pos].end.pais);
		printf("   CEP: ");
		scanf("%d",&x[pos].end.cep);
		printf(" Telefone: ");
		scanf("%d",&x[pos].tele);
		printf(" Aniversario: ");
		scanf("%d%d%d",&x[pos].data.d,&x[pos].data.m,&x[pos].data.a);
		tl++;
		printf(" Digite o nome: ");
		fflush(stdin);
		gets(nome);
	}
}
void Excluir(TpPessoa x[tf],int &tl){
	char nome[30];
	int pos,i;
	clrscr();
	printf(" ### Excluir ###\n\n");
	if(tl==0){
		printf(" Agenda Vazia !\n");
		getch();
	}
	else{
		printf(" Digite o nome: ");
		gets(nome);
		while(tl<tf && stricmp(nome,"\0")!=0){
			pos=busca(x,tl,nome);
			if(pos==tl)
				printf(" Nome nao encontrado!\n");
			else{
				for(i=pos;i<tl-1;i++)
					x[i]=x[i+1];
				tl--;
				printf(" Excluido com sucesso !\n");
			}
			
			if(tl>0){
				printf(" Digite o nome: ");
				gets(nome);
			}
			else
				strcpy(nome,"\0");
		}	
	}
}
void Exibir(TpPessoa x[tf],int &tl){
	char tecla;
	int i;
	do{
		clrscr();
		printf(" ### Exibir Agenda ###\n\n");
		printf(" Opcao de exibicao:\n");
		printf(" [A]Nome,Telefone e e-mail\n");
		printf(" [B]Todos os dados\n");
		printf(" [ESC]Sair");
		tecla=toupper(getch());
		switch(tecla){
			case 'A':
				clrscr();
				printf(" ### Exibir Agenda ###\n\n");
				for(i=0;i<tl;i++)
					ExibeA(x,i);
				getch();
				break;
			case 'B':
				clrscr();
				printf(" ### Exibir Agenda ###\n\n");
				for(i=0;i<tl;i++)
					ExibePos(x,i);
				getch();
				break;
		}
	}while(tecla!=27);
	
}
char menu(){
	clrscr();
	printf(" ### Menu ###\n\n");
	printf(" [A]Busca primeiro Nome\n");
	printf(" [B]Mes de Aniversario\n");
	printf(" [C]Dia e Mes de Aniversario\n");
	printf(" [D]Cadastrar\n");
	printf(" [E]Exluir\n");
	printf(" [F]Exibir\n");
	printf(" [ESC]Sair");
	return toupper(getch());
}
void executar(){
	char tecla;
	int tl=3;
	TpPessoa x[tf]={"Ana Carolina","Coisa@Coisa.com","Esperanca do Nada","Casa","Vila Top","Presidente Prudente","Piaui",
						"Brazil",69,75290043,12,2,1996,18987462340,
					"Ana Souza","Ana@ana.com.br","Washington Luiz","Casa","Jd.Jardim","Londrina","Goiais",
						"Brazil",77,47508932,27,6,1986,18968583987,
					"Carlos Pereira", "carlos@email.com", "Rua D", "Casa 404", "Bairro D", "Cidade D", "Estado D",
						"Brasil", 101, 76543, 4, 2, 1975, 444555666};
	
	do{
		tecla=menu();
		switch(tecla){
			case 'A':
				BuscaNome(x,tl);
				break;
			case 'B':
				MesAni(x,tl);
				break;
			case 'C':
				DiaMesAni(x,tl);
				break;
			case 'D':
				cadastrar(x,tl);
				break;
			case 'E':
				Excluir(x,tl);
				break;
			case 'F':
				Exibir(x,tl);
				break;
		}
	}while(tecla!=27);
}
int main(){
	executar();
	return 0;
}
