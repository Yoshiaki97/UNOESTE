#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#define tf 100
struct TpData{
	int d,m,a;
};
struct TpProduto{
	int cod;
	char descr[20];
	int est;
	float preco;
	TpData data;
	int forn;
};
struct TpFornecedor{
	int cod;
	char nome[30];
	char cidade[20];
};
struct TpCliente{
	char cpf[15];
	char nome[30];
	int qtde;
	float total;
};
struct TpVendas{
	int cod;
	char cpf[15];
	TpData data;
	float total;
};
struct TpVendasP{
	int codV;
	int codP;
	int qtde;
	float preco;
};
void apagar(int CI,int LI, int CF,int LF){
	//Menu: apagar(2,5,27,21);
	//Tela: apagar(28,5,79,21);
	//baixo: apagar(2,22,79,24);
	
	int i,j;
	for(i=CI+1;i<CF;i++)
		for(j=LI+1;j<LF;j++){
			gotoxy(i,j);
			printf(" ");
		}
}
void Moldura(int CI,int LI, int CF,int LF,int cort,int corf)
{
	int i;
	
	textcolor(cort);
	textbackground(corf);
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CF,LF);
	printf("%c",188);
	
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}	
	textcolor(15);
	textbackground(0);
}
int buscaProduto(TpProduto x[tf],int tl,int cod){
	int pos=0;
	while(pos<tl && x[pos].cod!=cod)
		pos++;
	return pos;
}
int buscaFornecedor(TpFornecedor x[tf],int tl,int cod){
	int pos=0;
	while(pos<tl && x[pos].cod!=cod)
		pos++;
	return pos;
}
void CadastroProduto(TpProduto x[tf],int &tl,TpFornecedor f[tf],int tlf){
	char op,aux[30];
	int pos,i=8,cod,forn,est,d,m,a;
	float preco;
	apagar(2,22,79,24);
	gotoxy(35,6),printf("* * Cadastro * *");
	gotoxy(30,i++),printf("Codigo do Produto: ");
	scanf("%d",&cod);
	while(tl<tf && cod>0){
		pos=buscaProduto(x,tl,cod);
		if(pos<tl){
			apagar(28,7,79,21);//tela
			gotoxy(30,i++),printf("Codigo: %s",x[pos].cod);
			gotoxy(30,i++),printf("Descrisao: %s",x[pos].descr);
			gotoxy(30,i++),printf("Estoque: %d",x[pos].est);
			gotoxy(30,i++),printf("Preco: R$%.2f",x[pos].preco);
			gotoxy(30,i++),printf("Data: %d/%d/%d",x[pos].data.d,x[pos].data.m,x[pos].data.a);
			gotoxy(30,i++),printf("Cod. Fornecedor: %d",x[pos].forn);
			gotoxy(3,23),printf("Codigo ja Existente!");
			getch();
		}
		else{
			gotoxy(30,i++),printf("Fornecedor: ");
			scanf("%d",&forn);
			pos=buscaFornecedor(f,tlf,forn);
			while(pos==tl && forn!=0){
				gotoxy(3,23),printf("Fornecedor Inexistente! ");
				apagar(29,8,79,10);
				gotoxy(30,i-1),printf("Fornecedor: ");
				scanf("%d",&forn);
				if(forn!=0)
					pos=buscaFornecedor(f,tlf,forn);
			}
			if(forn!=0){
				gotoxy(30,i++),printf("Descrisao: ");
				gets(aux);
				gotoxy(30,i++),printf("Estoque: ");
				scanf("%d",&est);
				gotoxy(30,i++),printf("Preco: ");
				scanf("%f",&preco);
				gotoxy(30,i++),printf("Data [dd/mm/aaaa]: ");
				scanf("%d%d%d",&d,&m,&a);
			}
			
			gotoxy(3,23),printf("Confirmar o cadastro [s/n]? ");
			op=toupper(getch());
			if(op == 'S'){
				x[tl].cod=cod;
				x[tl].forn=forn;
				strcpy(x[tl].descr,aux);
				x[tl].est=est;
				x[tl].preco=preco;
				x[tl].data.d=d;
				x[tl].data.m=m;
				x[tl].data.a=a;
				tl++;
			}	
		}
		apagar(2,22,79,24);
		apagar(28,6,79,21);
		i=8;
		gotoxy(35,6),printf("* * Cadastro * *");
		gotoxy(30,i++),printf("Codigo do Produto: ");
		scanf("%d",&cod);
	}
}
int buscaCliente(TpCliente x[tf],int tl,char cpf[15]){
	int pos=0;
	while(pos<tl && strcmp(cpf,x[pos].cpf)!=0)
		pos++;
	return pos;
}
void CadastroCliente(TpCliente x[tf],int &tl){
	char cpf[15],aux[30],op;
	int pos,i=8;
	apagar(2,22,79,24);
	gotoxy(35,6),printf("* * Cadastro * *");
	gotoxy(30,i++),printf("CPF do cliente: ");
	gets(cpf);
	while(tl<tf && stricmp(cpf,"0")!=0){
		pos=buscaCliente(x,tl,cpf);
		if(pos<tl){
			gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
			gotoxy(30,i++),printf("Quantidade: %d",x[pos].qtde);
			gotoxy(30,i++),printf("Total: %.2f",x[pos].total);
			gotoxy(3,23),printf("Codigo ja Existente!");
			getch();
		}
		else{
			gotoxy(30,i++),printf("Nome do Cliente: ");
			gets(aux);
			gotoxy(3,23),printf("Confirmar o cadastro [s/n]? ");
			op=toupper(getch());
			if(op == 'S'){
				strcpy(x[tl].cpf,cpf);
				strcpy(x[tl].nome,aux);
				x[tl].qtde=0;
				x[tl].total=0;
				tl++;
			}	
		}
		apagar(2,22,79,24);
		apagar(28,6,79,21);
		i=8;
		gotoxy(35,6),printf("* * Cadastro * *");
		gotoxy(30,i++),printf("CPF do cliente: ");
		gets(cpf);
	}
}
void ConsultaCliente(TpCliente x[tf],int tl){
	int i=8,pos;
	char cpf[15];
	apagar(2,22,79,24);
	gotoxy(35,6),printf("* * Consulta * *");
	gotoxy(30,i++),printf("CPF do cliente: ");
	gets(cpf);
	while(tl<tf && stricmp(cpf,"0")!=0){
		pos=buscaCliente(x,tl,cpf);
		if(pos<tl){
			apagar(28,7,79,21);//tela
			gotoxy(30,i++),printf("CPF: %s",x[pos].cpf);
			gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
			gotoxy(30,i++),printf("Quantidade: %d",x[pos].qtde);
			gotoxy(30,i++),printf("Total: %.2f",x[pos].total);
			gotoxy(30,20),printf("[ENTER] Continuar...");
			getch();
		}
		else{
			gotoxy(3,23),printf("CPF nao cadastrado !");
			getch();
		}
		apagar(2,22,79,24);//mensagem
		apagar(28,7,79,21);//tela
		i=8;
		gotoxy(30,i++),printf("CPF do cliente: ");
		gets(cpf);
	}
}
int submenu(){
	apagar(2,22,79,24);
	textcolor(15);
	gotoxy(3,9);
	printf("[A] Cadastro");
	gotoxy(3,10);
	printf("[B] Consulta");
	gotoxy(3,11);
	printf("[C] Exclusao ");
	gotoxy(3,12);
	printf("[D] Alteracao ");
	gotoxy(3,13);
	printf("[E] Relatorio ");
	gotoxy(3,20);
	printf("[ESC] Sair");
	gotoxy(3,23);
	printf("Escolha uma opcao: ");
	return toupper(getch());
}
void MenuPrincipal(void)
{
	textcolor(15);
	gotoxy(7,7);
	printf("* * M E N U * *");
	gotoxy(3,9);
	printf("[A] Produtos");
	gotoxy(3,10);
	printf("[B] Fornecedores");
	gotoxy(3,11);
	printf("[C] Clientes ");
	gotoxy(3,12);
	printf("[D] Vendas ");
	gotoxy(3,20);
	printf("[ESC] Sair");
	gotoxy(3,23);
	printf("Escolha uma opcao: ");
}
char Formulario(void)
{
	system("cls");
	Moldura(1,1,80,25,5,0);
	gotoxy(29,3);
	textcolor(15);
	printf("* * * T I T U L O * * *");
	Moldura(2,2,79,4,5,0);
	Moldura(2,5,27,21,5,0);
	MenuPrincipal();
	Moldura(2,22,79,24,5,0);
	gotoxy(4,23);
	textcolor(15);
	Moldura(28,5,79,21,5,0);
	gotoxy(22,23);
	return toupper(getche());
}

void executar(){
	TpCliente cliente[tf];
	TpProduto produto[tf];
	TpFornecedor fornecedor[tf];
	int tl_cliente=0,tl_produto=0,tl_fornecedor=0;
	
	char tecla,op;
	do{
		tecla=Formulario();
		switch(tecla){
			case 'A':
				apagar(2,5,27,21);
				gotoxy(5,7),printf("* * Produtos * *");
				op=submenu();
				switch(op){
					case 'A':
						CadastroProduto(produto,tl_produto,fornecedor,tl_fornecedor);
						break;
					case 'B':
						//ConsultaProduto(produto,tl_produto);
						break;
				}
				break;
			case 'C':
				apagar(2,5,27,21);
				gotoxy(5,7),printf("* * Cliente * *");
				op=submenu();
				switch(op){
					case 'A':
						CadastroCliente(cliente,tl_cliente);
						break;
					case 'B':
						ConsultaCliente(cliente,tl_cliente);
						break;
				}
				break;
		}
	}while(tecla!=27);
}
int main(){
	executar();
	return 0;
}
