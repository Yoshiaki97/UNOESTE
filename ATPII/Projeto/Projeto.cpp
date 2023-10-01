#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<time.h>
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
int ValidaData(TpData data)
{
	int anoB = 0, diaV = 0;
	
	if(data.a > 0 && data.m >= 1 && data.m <= 12 && data.d >= 1)
	{
		if(data.a % 4 == 0 && data.a % 100 != 0 || data.a % 400 == 0)
			anoB = 1;
		
		if(data.m == 1 || data.m == 3 || data.m == 5 || data.m == 7 || data.m == 8 || data.m == 10 || data.m == 12)
		{
			if(data.d <= 31)
				diaV = 1;
		}
		else
			if(data.m == 4 || data.m == 6 || data.m == 9 || data.m == 11)
			{
				if(data.d <= 30)
					diaV = 1;
			}
			else{
				if(anoB == 1 && data.d <= 29)
					diaV = 1;
				else
					if(anoB == 0 && data.d <= 28)
						diaV = 1;
			}
	}
	
	if(diaV == 1)
		return 1;
	else
		return -1;
}
void apagar(int x){
	//Menu[1]: apagar(2,5,27,21);
	//Tela[2]: apagar(28,5,79,21);
	//MSG[3]: apagar(2,22,79,24);
	//Titulo[4] : apagar(2,2,79,4);
	/*int i,j;
	for(i=CI+1;i<CF;i++)
		for(j=LI+1;j<LF;j++){
			gotoxy(i,j);
			printf(" ");
		}*/
	int i;
	if(x==1){
		for(i=6;i<21;i++){
			gotoxy(3,i);                    
			printf("                        ");
		}
	}
	else if(x==2){
		for(i=6;i<21;i++){
			gotoxy(29,i);                                             
			printf("                                                  ");
		}
	}
	else if(x==3){
		gotoxy(3,23),printf("                                                                            ");
	}
	else if(x==4){                                                                                      
		gotoxy(3,3),printf("                                                                            ");
	}
}
void Moldura(int CI,int LI, int CF,int LF,int cort,int corf){
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
void VerifInt(int &x,int &i,char n[30]){
	int valido=0;
	while(valido!=1){
		gotoxy(30,i);printf("                                                 ");
		gotoxy(30,i);printf("%s",n);
		if(scanf("%d",&x)==1)
			valido=1;
		else{
			apagar(3);
			gotoxy(3,23),printf("Codigo invalido.");
			getch();
			apagar(3);
			gotoxy(3,23),printf("Digite [0] para sair");
		}
		fflush(stdin);
	}
	i++;
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
int buscaCliente(TpCliente x[tf],int tl,char cpf[15]){
	int pos=0;
	while(pos<tl && strcmp(cpf,x[pos].cpf)!=0)
		pos++;
	return pos;
}
int buscaCodigo(TpProduto x[tf],int tl,int cod){
	int pos=0;
	while(pos<tl && x[pos].forn!=cod)
		pos++;
	return pos;
}
int buscaCPF(TpVendas x[tf],int tl,char cpf[15]){
	int pos=0;
	while(pos<tl && strcmp(cpf,x[pos].cpf)!=0)
		pos++;
	return pos;
}
int buscaVendasP(TpVendasP x[tf],int tl,int cod){
	int pos=0;
	while(pos<tl && x[pos].codP!=cod)
		pos++;
	return pos;
}
int buscaCodVenda(TpVendasP x[tf],int tl,int cod,int num){
	int pos=0;
	while(pos<tl && (x[pos].codV!=num || x[pos].codP!=cod))
			pos++;
	return pos;
}
int buscaVendas(TpVendas x[tf],int tl,int cod){
	int pos=0;
	while(pos<tl && x[pos].cod!=cod)
			pos++;
	return pos;
}
void CadastroFornecedor(TpFornecedor x[tf],int &tl){
	char op,aux[30],cid[30];
	int pos,i=8,cod;
	float preco;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  CADASTRO  ]>");
	gotoxy(35,6),printf("* * Cadastro * *");
	apagar(3);//msg
	if(tl==tf){
		gotoxy(30,i++),printf("Lista Cheia: ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		//gotoxy(30,i++),printf("Codigo do Fornecedor: ");
		VerifInt(cod,i,"Codigo do Fornecedor: ");
		//scanf("%d",&cod);
		apagar(3);//msg
		while(tl<tf && cod>0){
			pos=buscaFornecedor(x,tl,cod);
			if(pos<tl){
				apagar(2);//tela
				gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
				gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
				gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
				gotoxy(3,23),printf("Codigo ja Existente!");
				getch();
			}
			else{
				gotoxy(30,i++),printf("Nome: ");
				fflush(stdin);
				gets(aux);
				gotoxy(30,i++),printf("Cidade: ");
				gets(cid);
				gotoxy(3,23),printf("Confirmar o cadastro [s/n]? ");
				op=toupper(getch());
				if(op == 'S'){
					x[tl].cod=cod;
					strcpy(x[tl].cidade,cid);
					strcpy(x[tl].nome,aux);
					tl++;
				}	
			}
			apagar(2);
			i=8;
			if(tl<tf){
				apagar(3);//msg
				gotoxy(35,6),printf("* * Cadastro * *");
				gotoxy(3,23),printf("Digite [0] para sair");
				//gotoxy(30,i++),printf("Codigo do Fornecedor: ");
				VerifInt(cod,i,"Codigo do Fornecedor: ");
				//scanf("%d",&cod);
				apagar(3);//msg
			}
		}
	}
}
void ConsultaFornecedor(TpFornecedor x[tf],int tl){
	int i=8,pos,cod;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  CONSULTA  ]>");
	apagar(2);
	gotoxy(35,6),printf("* * Consulta * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		//gotoxy(30,i++),printf("Codigo do Fornecedor: ");
		VerifInt(cod,i,"Codigo do Fornecedor: ");
		//scanf("%d",&cod);
		apagar(3);//msg
		while(cod!=0){
			pos=buscaFornecedor(x,tl,cod);
			if(pos<tl){
				apagar(2);//tela
				gotoxy(35,6),printf("* * Consulta * *");
				gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
				gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
				gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				gotoxy(3,23),printf("Codigo nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			apagar(3);//msg
			gotoxy(35,6),printf("* * Consulta * *");
			gotoxy(3,23),printf("Digite [0] para sair");
			//gotoxy(30,i++),printf("Codigo do Fornecedor: ");
			VerifInt(cod,i,"Codigo do Fornecedor: ");
			//scanf("%d",&cod);
			apagar(3);//msg
		}
	}

}
void exclusaoFornecedor(TpFornecedor x[tf],int &tl,TpProduto p[tf],int tlp){
	int i=8,pos,pos1,cod;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  EXCLUSAO  ]>");
	gotoxy(35,6),printf("* * Exclusao * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		//gotoxy(30,i++),printf("Codigo do Fornecedor: ");
		VerifInt(cod,i,"Codigo do Fornecedor: ");
		//scanf("%d",&cod);
		apagar(3);//msg
		while(tl>0 && cod!=0){
			pos=buscaFornecedor(x,tl,cod);
			if(pos<tl){
				pos1=buscaCodigo(p,tlp,cod);
				if(pos1==tlp){
					apagar(2);//tela
					gotoxy(35,6),printf("* * Exclusao * *");
					gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
					gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
					gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
					gotoxy(3,23),printf("Confirmar a exclusao? [S/N]");
					op=toupper(getch());
					if(op=='S'){
						for(;pos<tl-1;pos++)
							x[pos]=x[pos+1];
						tl--;
					}
				}
				else{
					apagar(2);
					gotoxy(35,6),printf("* * Exclusao * *");
					gotoxy(30,i++),printf("Codigo cadastrado no Produto:");
					gotoxy(30,i++),printf("Cod. do Produto: %d",p[pos].cod);
					gotoxy(30,i++),printf("Descrisao: %s",p[pos].descr);
					gotoxy(30,i++),printf("Estoque: %d",p[pos].est);
					gotoxy(30,i++),printf("Preco: R$%.2f",p[pos].preco);
					gotoxy(30,i++),printf("Data: %d/%d/%d",p[pos].data.d,p[pos].data.m,p[pos].data.a);
					gotoxy(30,i++),printf("Cod. Fornecedor: %d",p[pos].forn);
					gotoxy(30,20),printf("Exclusao bloqueada ! ");
					gotoxy(3,23),printf("[ENTER] Continuar...");
					getch();
				}
			}
			else{
				gotoxy(3,23),printf("Codigo nao cadastrado !");
				getch();
			}
			apagar(3);//mensagem
			apagar(2);//tela
			i=8;
			if(tl>0){
				gotoxy(35,6),printf("* * Exclusao * *");
				apagar(3);//msg
				gotoxy(3,23),printf("Digite [0] para sair");
				//gotoxy(30,i++),printf("Codigo do Fornecedor: ");
				VerifInt(cod,i,"Codigo do Fornecedor: ");
				//scanf("%d",&cod);
				apagar(3);//msg
			}
		}
	}
}
void alterarFornecedor(TpFornecedor x[tf],int tl){
	char op,aux[30],aux2[30];
	int pos,i=8,cod;
	apagar(1);//MENU
	apagar(4);//titulo
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  ALTERACAO  ]>");
		apagar(2);//tela
		gotoxy(38,6),printf("* * Alteracao * *");
		gotoxy(3,23),printf("Digite [0] para sair");
		//gotoxy(30,i++),printf("Codigo do Fornecedor: ");
		VerifInt(cod,i,"Codigo do Fornecedor: ");
		//scanf("%d",&cod);
		while(cod>0){
			apagar(3);//msg
			pos=buscaFornecedor(x,tl,cod);
			if(pos==tl){
				apagar(2);//tela
				gotoxy(38,6),printf("* * Alteracao * *");
				gotoxy(30,i++),printf("Codigo nao cadastrado !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				apagar(3);//msg
				gotoxy(30,i++),printf("Nome: %s -> ",x[pos].nome);
				fflush(stdin);
				gets(aux);
				gotoxy(30,i++),printf("Cidade: %s -> ",x[pos].cidade);
				gets(aux2);
				gotoxy(3,23),printf("Confirmar a alteracao [s/n]? ");
				op=toupper(getch());
				apagar(3);//msg
				if(op == 'S'){
					strcpy(x[pos].nome,aux);
					strcpy(x[pos].cidade,aux2);
				}	
			}
			apagar(2);
			i=8;
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(38,6),printf("* * Alteracao * *");
			//gotoxy(30,i++),printf("Codigo do Fornecedor: ");
			VerifInt(cod,i,"Codigo do Fornecedor: ");
			//scanf("%d",&cod);
			apagar(3);//msg
		}
	}
}
void RelatorioFornecedor(TpFornecedor x[tf],int tl){
	int pos=0,i=8;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  RELATORIO  ]>");
		do{
			gotoxy(35,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
			gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
			gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
			if(pos==0 && tl!=1){
				gotoxy(78,13),printf("%c",25);
			}	
			else if(pos<tl-1){
				gotoxy(78,12),printf("%c",24);
				gotoxy(78,13),printf("%c",25);
			}
			else if(tl!=1){
				gotoxy(78,12),printf("%c",24);
			}
			gotoxy(3,23),printf("Digite [ESC] para sair");
			op=getch();
			if(op==-32){
				op=getch();
				if(op==80 && pos<tl-1)
					pos++;
				else if(op==72 && pos>0)
					pos--;
				i=8;
				apagar(2);//tela
			}
		}while(op!=27);
	}
}
void CadastroProduto(TpProduto x[tf],int &tl,TpFornecedor f[tf],int tlf){
	char op,aux[30];
	int pos,i=8,cod,forn,est,val;
	float preco;
	TpData data;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  CADASTRO  ]>");
	gotoxy(35,6),printf("* * Cadastro * *");
	apagar(3);//msg
	if(tl==tf){
		gotoxy(30,i++),printf("Lista Cheia: ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		//gotoxy(30,i++),printf("Codigo do Produto: ");
		VerifInt(cod,i,"Codigo do Produto: ");
		//scanf("%d",&cod);
		apagar(3);//msg
		while(tl<tf && cod>0){
			pos=buscaProduto(x,tl,cod);
			if(pos<tl){
				apagar(2);//tela
				gotoxy(35,6),printf("* * Cadastro * *");i--;
				gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
				gotoxy(30,i++),printf("Descrisao: %s",x[pos].descr);
				gotoxy(30,i++),printf("Estoque: %d",x[pos].est);
				gotoxy(30,i++),printf("Preco: R$%.2f",x[pos].preco);
				gotoxy(30,i++),printf("Data: %d/%d/%d",x[pos].data.d,x[pos].data.m,x[pos].data.a);
				gotoxy(30,i++),printf("Cod. Fornecedor: %d",x[pos].forn);
				apagar(3);//msg
				gotoxy(3,23),printf("Codigo ja Existente!");
				getch();
			}
			else{
				//gotoxy(30,i++),printf("Fornecedor: ");
				VerifInt(forn,i,"Codigo do Fornecedor: ");
				//scanf("%d",&forn);
				pos=buscaFornecedor(f,tlf,forn);
				while(pos==tlf && forn!=0){
					i--;
					gotoxy(3,23),printf("Fornecedor Inexistente! ");
					VerifInt(forn,i,"Codigo do Fornecedor: ");
					//scanf("%d",&forn);
					if(forn!=0)
						pos=buscaFornecedor(f,tlf,forn);
				}
				if(forn!=0){
					gotoxy(30,i++),printf("Descrisao: ");
					fflush(stdin);
					gets(aux);
					gotoxy(30,i++),printf("Estoque: ");
					scanf("%d",&est);
					gotoxy(30,i++),printf("Preco: ");
					scanf("%f",&preco);
					gotoxy(30,i++),printf("Data [dd/mm/aaaa]: ");
					scanf("%d%d%d",&data.d,&data.m,&data.a);
					val=ValidaData(data);
					while(val==-1){
						gotoxy(3,23),printf("Data Invalida !");
						gotoxy(30,i-1),printf("                                        ");
						gotoxy(30,i-1),printf("Data [dd/mm/aaaa]: ");
						scanf("%d%d%d",&data.d,&data.m,&data.a);
						val=ValidaData(data);
					}
					gotoxy(3,23),printf("Confirmar o cadastro [s/n]? ");
					op=toupper(getch());
					if(op == 'S'){
						x[tl].cod=cod;
						x[tl].forn=forn;
						strcpy(x[tl].descr,aux);
						x[tl].est=est;
						x[tl].preco=preco;
						x[tl].data.d=data.d;
						x[tl].data.m=data.m;
						x[tl].data.a=data.a;
						tl++;
					}	
				}
			}
			apagar(2);
			i=8;
			if(tl<tf){
				apagar(3);//msg
				gotoxy(3,23),printf("Digite [0] para sair");
				gotoxy(38,6),printf("* * Cadastro * *");
				//gotoxy(30,i++),printf("Codigo do Produto: ");
				VerifInt(cod,i,"Codigo do Produto: ");
				//scanf("%d",&cod);
				apagar(3);//msg
			}
		}
	}
}
void ConsultaProduto(TpProduto x[tf],int tl){
	int i=8,pos,cod;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  CONSULTA  ]>");
	apagar(2);
	gotoxy(35,6),printf("* * Consulta * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		//gotoxy(30,i++),printf("Codigo do Produto: ");
		VerifInt(cod,i,"Codigo do Produto: ");
		//scanf("%d",&cod);
		apagar(3);//msg
		while(cod!=0){
			pos=buscaProduto(x,tl,cod);
			if(pos<tl){
				apagar(2);//tela
				gotoxy(35,6),printf("* * Consulta * *");
				gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
				gotoxy(30,i++),printf("Descrisao: %s",x[pos].descr);
				gotoxy(30,i++),printf("Estoque: %d",x[pos].est);
				gotoxy(30,i++),printf("Preco: R$%.2f",x[pos].preco);
				gotoxy(30,i++),printf("Data: %d/%d/%d",x[pos].data.d,x[pos].data.m,x[pos].data.a);
				gotoxy(30,i++),printf("Cod. Fornecedor: %d",x[pos].forn);
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				gotoxy(3,23),printf("Codigo nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			apagar(3);//msg
			gotoxy(35,6),printf("* * Consulta * *");
			gotoxy(3,23),printf("Digite [0] para sair");
			//gotoxy(30,i++),printf("Codigo do Produto: ");
			VerifInt(cod,i,"Codigo do Produto: ");
			//scanf("%d",&cod);
			apagar(3);//msg
		}
	}
}
void exclusaoProduto(TpProduto x[tf],int &tl,TpVendasP v[tf],int tlv){
	int i=8,pos,pos1,cod;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  EXCLUSAO  ]>");
	gotoxy(35,6),printf("* * Exclusao * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		//gotoxy(30,i++),printf("Codigo do Produto: ");
		VerifInt(cod,i,"Codigo do Produto: ");
		//scanf("%d",&cod);
		apagar(3);//msg
		while(tl>0 && cod!=0){
			pos=buscaProduto(x,tl,cod);
			if(pos<tl){
				pos1=buscaVendasP(v,tlv,cod);
				if(pos1==tlv){
					apagar(2);//tela
					gotoxy(35,6),printf("* * Exclusao * *");
					gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
					gotoxy(30,i++),printf("Descrisao: %s",x[pos].descr);
					gotoxy(30,i++),printf("Estoque: %d",x[pos].est);
					gotoxy(30,i++),printf("Preco: R$%.2f",x[pos].preco);
					gotoxy(30,i++),printf("Data: %d/%d/%d",x[pos].data.d,x[pos].data.m,x[pos].data.a);
					gotoxy(30,i++),printf("Cod. Fornecedor: %d",x[pos].forn);
					gotoxy(3,23),printf("Confirmar a exclusao? [S/N]");
					op=toupper(getch());
					if(op=='S'){
						for(;pos<tl-1;pos++)
							x[pos]=x[pos+1];
						tl--;
					}
				}
				else{
					apagar(2);
					gotoxy(35,6),printf("* * Exclusao * *");
					gotoxy(30,i++),printf("Codigo cadastrado na Vendas:");
					gotoxy(30,i++),printf("Cod. da Venda: %d",v[pos1].codV);
					gotoxy(30,i++),printf("Cod. do Produto: %d",v[pos1].codP);
					gotoxy(30,i++),printf("Preco: R$%.2f",v[pos1].preco);
					gotoxy(30,i++),printf("Qtde comprada: %d",v[pos1].qtde);
					gotoxy(30,20),printf("Exclusao bloqueada ! ");
					gotoxy(3,23),printf("[ENTER] Continuar...");
					getch();
				}
			}
			else{
				gotoxy(3,23),printf("Codigo nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			if(tl>0){
				gotoxy(35,6),printf("* * Exclusao * *");
				apagar(3);//msg
				gotoxy(3,23),printf("Digite [0] para sair");
				//gotoxy(30,i++),printf("Codigo do Produto: ");
				VerifInt(cod,i,"Codigo do Produto: ");
				//scanf("%d",&cod);
				apagar(3);//msg
			}
		}
	}
}
void alterarProduto(TpProduto x[tf],int tl,TpFornecedor f[tf],int tlf){
	char op,aux[30];
	int pos,i=8,pos1,cod,forn,est,val;
	TpData data;
	float preco;
	apagar(1);//MENU
	apagar(4);//titulo
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  ALTERACAO  ]>");
		apagar(2);//tela
		gotoxy(38,6),printf("* * Alteracao * *");
		gotoxy(3,23),printf("Digite [0] para sair");
		//gotoxy(30,i++),printf("Codigo do Produto: ");
		VerifInt(cod,i,"Codigo do Produto: ");
		//scanf("%d",&cod);
		while(cod>0){
			apagar(3);//msg
			pos=buscaProduto(x,tl,cod);
			if(pos==tl){
				apagar(2);//tela
				gotoxy(38,6),printf("* * Alteracao * *");
				gotoxy(30,i++),printf("Codigo nao cadastrado !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				gotoxy(30,i++),printf("Fornecedor: %d ->  ",x[pos].forn);
				scanf("%d",&forn);
				pos1=buscaFornecedor(f,tlf,forn);
				while(pos1==tlf){
					gotoxy(3,23),printf("Fornecedor Inexistente! ");
					gotoxy(30,i-1),printf("                                                 ");
					gotoxy(30,i-1),printf("Fornecedor: %d -> ",x[pos].forn);
					scanf("%d",&forn);
					pos1=buscaFornecedor(f,tlf,forn);
				}
				apagar(3);//msg
				gotoxy(30,i++),printf("Descrisao: %s -> ",x[pos].descr);
				fflush(stdin);
				gets(aux);
				gotoxy(30,i++),printf("Estoque: %d -> ",x[pos].est);
				scanf("%d",&est);
				gotoxy(30,i++),printf("Preco: R$%.2f -> ",x[pos].preco);
				scanf("%f",&preco);
				gotoxy(30,i++),printf("Data: %d/%d/%d -> : ",x[pos].data.d,x[pos].data.m,x[pos].data.a);
				scanf("%d%d%d",&data.d,&data.m,&data.a);
				val=ValidaData(data);
				while(val==-1){
					gotoxy(30,i-1),printf("                                           ");
					gotoxy(30,i-1),printf("Data: %d/%d/%d -> : ",x[pos].data.d,x[pos].data.m,x[pos].data.a);
					scanf("%d%d%d",&data.d,&data.m,&data.a);
					val=ValidaData(data);
				}
				gotoxy(3,23),printf("Confirmar a alteracao [s/n]? ");
				op=toupper(getch());
				apagar(3);//msg
				if(op == 'S'){
					x[pos].forn=forn;
					strcpy(x[pos].descr,aux);
					x[pos].est=est;
					x[pos].preco=preco;
					x[pos].data.d=data.d;
					x[pos].data.m=data.m;
					x[pos].data.a=data.a;
				}	
			}
			apagar(2);
			i=8;
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(38,6),printf("* * Alteracao * *");
			//gotoxy(30,i++),printf("Codigo do Produto: ");
			VerifInt(cod,i,"Codigo do Produto: ");
			//scanf("%d",&cod);
			apagar(3);//msg
		}
	}
}
void RelatorioProduto(TpProduto x[tf],int tl){
	int pos=0,i=8;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  RELATORIO  ]>");
		do{
			gotoxy(35,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
			gotoxy(30,i++),printf("Descrisao: %s",x[pos].descr);
			gotoxy(30,i++),printf("Estoque: %d",x[pos].est);
			gotoxy(30,i++),printf("Preco: R$%.2f",x[pos].preco);
			gotoxy(30,i++),printf("Data: %d/%d/%d",x[pos].data.d,x[pos].data.m,x[pos].data.a);
			gotoxy(30,i++),printf("Cod. Fornecedor: %d",x[pos].forn);
			if(pos==0 && tl!=1){
				gotoxy(78,13),printf("%c",25);
			}	
			else if(pos<tl-1){
				gotoxy(78,12),printf("%c",24);
				gotoxy(78,13),printf("%c",25);
			}
			else if(tl!=1){
				gotoxy(78,12),printf("%c",24);
			}
			gotoxy(3,23),printf("Digite [ESC] para sair");
			op=getch();
			if(op==-32){
				op=getch();
				if(op==80 && pos<tl-1)
					pos++;
				else if(op==72 && pos>0)
					pos--;
				i=8;
				apagar(2);//tela
			}
		}while(op!=27);
	}
}
void CadastroCliente(TpCliente x[tf],int &tl){
	char cpf[15],aux[30],op;
	int pos,i=8;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  CADASTRO  ]>");
	apagar(2);
	gotoxy(35,6),printf("* * Cadastro * *");
	apagar(3);//msg
	if(tl==tf){
		gotoxy(30,i++),printf("Lista Cheia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(cpf);
		apagar(3);//msg
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
			apagar(2);
			i=8;
			if(tl<tf){
				apagar(3);//msg
				gotoxy(35,6),printf("* * Cadastro * *");
				gotoxy(3,23),printf("Digite [0] para sair");
				gotoxy(30,i++),printf("CPF do cliente: ");
				gets(cpf);
				apagar(3);//msg
			}
		}
	}
}
void ConsultaCliente(TpCliente x[tf],int tl){
	int i=8,pos;
	char cpf[15];
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  CONSULTA  ]>");
	apagar(2);
	gotoxy(35,6),printf("* * Consulta * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(cpf);
		apagar(3);//msg
		while(stricmp(cpf,"0")!=0){
			pos=buscaCliente(x,tl,cpf);
			if(pos<tl){
				apagar(2);//tela
				gotoxy(35,6),printf("* * Consulta * *");
				gotoxy(30,i++),printf("CPF: %s",x[pos].cpf);
				gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
				gotoxy(30,i++),printf("Quantidade: %d",x[pos].qtde);
				gotoxy(30,i++),printf("Total: %.2f",x[pos].total);
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				gotoxy(3,23),printf("CPF nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			apagar(3);//msg
			gotoxy(35,6),printf("* * Consulta * *");
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(30,i++),printf("CPF do cliente: ");
			gets(cpf);
			apagar(3);//msg
		}
	}
}
void exclusaoCliente(TpCliente x[tf],int &tl,TpVendas v[tf],int tlv){
	int i=8,pos,pos1;
	char cpf[15],op;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  EXCLUSAO  ]>");
	gotoxy(35,6),printf("* * Exclusao * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(cpf);
		apagar(3);//msg
		while(tl>0 && stricmp(cpf,"0")!=0){
			if(pos)
			pos=buscaCliente(x,tl,cpf);
			if(pos<tl){
				pos1=buscaCPF(v,tlv,cpf);
				if(pos1==tlv){
					apagar(2);//tela
					gotoxy(35,6),printf("* * Exclusao * *");
					gotoxy(30,i++),printf("CPF: %s",x[pos].cpf);
					gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
					gotoxy(30,i++),printf("Quantidade: %d",x[pos].qtde);
					gotoxy(30,i++),printf("Total: %.2f",x[pos].total);
					gotoxy(3,23),printf("Confirmar a exclusao? [S/N]");
					op=toupper(getch());
					if(op=='S'){
						for(;pos<tl-1;pos++)
							x[pos]=x[pos+1];
						tl--;
					}
				}
				else{
					apagar(2);//tela
					gotoxy(35,6),printf("* * Exclusao * *");
					gotoxy(30,i++),printf("CPF cadastrado na Venda:");i++;
					gotoxy(30,i++),printf("Cod. da Venda: %d",v[pos1].cod);
					gotoxy(30,i++),printf("CPF: %s",v[pos1].cpf);
					gotoxy(30,i++),printf("Data: %d/%d/%d",v[pos1].data.d,v[pos1].data.m,v[pos1].data.a);
					gotoxy(30,i++),printf("Total Comprado: R$%.2f",v[pos1].total);
					
					gotoxy(30,20),printf("Exclusao bloqueada ! ");
					gotoxy(3,23),printf("[ENTER] Continuar...");
					getch();
				}
			}
			else{
				gotoxy(3,23),printf("CPF nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			if(tl>0){
				gotoxy(35,6),printf("* * Exclusao * *");
				apagar(3);//msg
				gotoxy(3,23),printf("Digite [0] para sair");
				gotoxy(30,i++),printf("CPF do cliente: ");
				gets(cpf);
				apagar(3);//msg
			}	
		}
	}
}
void alterarCliente(TpCliente x[tf],int tl){
	char op,cpf[15],aux[30];
	int pos,i=8;
	apagar(1);//MENU
	apagar(4);//titulo
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  ALTERACAO  ]>");
		apagar(2);//tela
		gotoxy(38,6),printf("* * Alteracao * *");
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(cpf);
		while(stricmp(cpf,"0")!=0){
			apagar(3);//msg
			pos=buscaCliente(x,tl,cpf);
			if(pos==tl){
				apagar(2);//tela
				gotoxy(38,6),printf("* * Alteracao * *");
				gotoxy(30,i++),printf("CPF nao cadastrado !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				apagar(3);//msg
				gotoxy(30,i++),printf("Nome: %s -> ",x[pos].nome);
				fflush(stdin);
				gets(aux);
				gotoxy(3,23),printf("Confirmar a alteracao [s/n]? ");
				op=toupper(getch());
				apagar(3);//msg
				if(op == 'S'){
					strcpy(x[pos].nome,aux);
				}	
			}
			apagar(2);
			i=8;
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(38,6),printf("* * Alteracao * *");
			gotoxy(30,i++),printf("CPF do cliente: ");
			fflush(stdin);
			gets(cpf);
			apagar(3);//msg
		}
	}
}
void RelatorioCliente(TpCliente x[tf],int tl){
	int pos=0,i=8;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	if(tl==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  RELATORIO  ]>");
		do{
			gotoxy(35,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("CPF: %s",x[pos].cpf);
			gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
			gotoxy(30,i++),printf("Quantidade: %d",x[pos].qtde);
			gotoxy(30,i++),printf("Total: %.2f",x[pos].total);
			if(pos==0 && tl!=1){
				gotoxy(78,13),printf("%c",25);
			}	
			else if(pos<tl-1){
				gotoxy(78,12),printf("%c",24);
				gotoxy(78,13),printf("%c",25);
			}
			else if(tl!=1){
				gotoxy(78,12),printf("%c",24);
			}
			gotoxy(3,23),printf("Digite [ESC] para sair");
			op=getch();
			if(op==-32){
				op=getch();
				if(op==80 && pos<tl-1)
					pos++;
				else if(op==72 && pos>0)
					pos--;
				i=8;
				apagar(2);//tela
			}
		}while(op!=27);
	}
}
void CadastroVendas(TpVendas v[tf],TpVendasP vp[tf],TpCliente c[tf],int &tlv,int &tlvP,int tlc,TpProduto x[tf],int tlp){
	char cpf[14],aux[30],op;
	int pos,pos2,i=8,cod,pos1,qtde,num;
	float total;
	tm tempo;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  VENDAS  >>  CADASTRO  ]>");
	apagar(2);
	gotoxy(35,6),printf("* * Cadastro * *");
	apagar(3);//msg
	if(tlv==tf || tlvP==tf){
		gotoxy(30,i++),printf("Lista Cheia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(cpf);
		
		total=0;
		while((tlv<tf || tlvP<tf) && stricmp(cpf,"0")!=0){
			pos=buscaCliente(c,tlc,cpf);
			if(pos==tlc){
				gotoxy(3,23),printf("CPF nao cadastrado !");
				getch();
			}
			else{
				v[tlv].cod=v[tlv-1].cod+1;
				num=v[tlv].cod;
				strcpy(v[tlv].cpf,cpf);
				gotoxy(30,i++),printf("Codigo do Produto: ");
				scanf("%d",&cod);
				apagar(3);//msg
				while((tlv<tf || tlvP<tf) && cod!=0){
					pos1=buscaProduto(x,tlp,cod);
					if(pos1<tlp){
						pos2=buscaCodVenda(vp,tlvP,cod,num);
						if(pos2<tlvP){
							gotoxy(3,23),printf("Produto ja cadastrado nesta venda !");
							getch();
							apagar(3);//msg
						}
						else{
							gotoxy(30,i++),printf("Descr.: %s",x[pos1].descr);
							gotoxy(30,i++),printf("Preco: R$%.2f",x[pos1].preco);
							gotoxy(30,i++),printf("Estoque: %d",x[pos1].est);
							gotoxy(30,i++),printf("Quantidade da venda: ");
							scanf("%d",&qtde);
							while(qtde>x[pos1].est){
								gotoxy(3,23),printf("Quantidade Insuficiente no Estoque! ");
								gotoxy(30,i-1),printf("                                            ");
								gotoxy(30,i-1),printf("Quantidade: ");
								scanf("%d",&qtde);
							}
							apagar(3);//msg
							gotoxy(3,23),printf("Confirmar venda do Produto [s/n]? ");
							op=toupper(getch());
							if(op == 'S'){
								vp[tlvP].codV=num;
								vp[tlvP].codP=cod;
								vp[tlvP].qtde=qtde;
								vp[tlvP].preco=x[pos1].preco;
								x[pos1].est-=qtde;
								total+=vp[tlvP].preco*qtde;
								tlvP++;
							}
						}
					}
					else{
						gotoxy(3,23),printf("Produto nao cadastrado !");
						getch();
					}
					apagar(2);
					i=8;
					if(tlv<tf || tlvP<tf){
						apagar(3);//msg
						gotoxy(3,23),printf("Digite [0] para sair");
						gotoxy(38,6),printf("* * Vendas * *");
						gotoxy(30,i++),printf("CPF do cliente: %s",cpf);
						gotoxy(30,i),printf("                                          ");
						gotoxy(30,i++),printf("Codigo do Produto: ");
						scanf("%d",&cod);
						apagar(3);//msg
					}
				}
				v[tlv].total=total;
				v[tlv].data.d=tempo.tm_mday;
				v[tlv].data.m=tempo.tm_mon;
				v[tlv].data.a=tempo.tm_year;
				c[pos].total+=total;
				c[pos].qtde++;
				tlv++;
			}
			apagar(2);
			i=8;
			if(tlv<tf || tlvP<tf){
				apagar(3);//msg
				gotoxy(3,23),printf("Digite [0] para sair");
				gotoxy(38,6),printf("* * Vendas * *");
				gotoxy(30,i++),printf("CPF do cliente: ");
				fflush(stdin);
				gets(cpf);
				apagar(3);//msg
			}
		}
	}
}
void exclusaoVendas(TpVendas v[tf],TpVendasP vp[tf],TpCliente c[tf],int &tlv,int &tlvP,int tlc,TpProduto x[tf],int tlp){
	int pos,pos1,cod,i=8;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  VENDAS  >>  EXCLUSAO  ]>");
	apagar(2);
	gotoxy(35,6),printf("* * EXCLUSAO * *");
	apagar(3);//msg
	if(tlv==0){
		gotoxy(30,i++),printf("Lista Vazia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		apagar(3);//msg
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i++),printf("Codigo da Venda: ");
		scanf("%d",&cod);
		apagar(3);//msg
		while(tlv>0 && cod!=0){
			pos=buscaVendas(v,tlv,cod);
			if(pos==tlv){
				gotoxy(3,23),printf("Venda nao cadastrada !");
				getch();
			}
			else{
				gotoxy(30,i++),printf("CPF: %s",v[pos].cpf);
				gotoxy(30,i++),printf("Data da compra: %d/%d/%d",v[pos].data.d,v[pos].data.m,v[pos].data.a);
				gotoxy(30,i++),printf("Total da venda: R$%.2f",v[pos].total);
				gotoxy(3,23),printf("Confirmar Exclusao do Produto [s/n]? ");
				op=toupper(getch());
				if(op == 'S'){
					pos1=buscaCliente(c,tlc,v[pos].cpf);
					c[pos1].qtde--;
					c[pos1].total-=v[pos].total;
					for(;pos<tlv-1;pos++){
						v[pos]=v[pos+1];
						v[pos].cod--;
					}
					tlv--;
					pos=buscaVendasP(vp,tlvP,cod);
					while(pos<tlvP){
						pos1=buscaProduto(x,tlp,vp[pos].codV);
						x[pos1].est+=vp[pos].qtde;
						for(i=pos;i<tlvP-1;i++){
							vp[i]=vp[i+1];
							vp[i].codV--;
						}
						tlvP--;
						pos=buscaVendasP(vp,tlvP,cod);
					}
				}
			}
			i=8;
			apagar(2);
			apagar(3);//msg
			gotoxy(35,6),printf("* * EXCLUSAO * *");
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(30,i++),printf("Codigo da Venda: ");
			scanf("%d",&cod);
			apagar(3);//msg
		}
	}
}
int submenu(){
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
int VendasMenu(){
	textcolor(15);
	gotoxy(3,9);
	printf("[A] Cadastro");
	gotoxy(3,10);
	printf("[B] Exclusao");
	gotoxy(3,20);
	printf("[ESC] Sair");
	gotoxy(3,23);
	printf("Escolha uma opcao: ");
	return toupper(getch());
}
void MenuPrincipal(void){
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
char Formulario(void){
	apagar(1);
	apagar(2);
	apagar(3);//msg
	apagar(4);//titulo
	Moldura(1,1,80,25,5,0);
	gotoxy(3,3);
	textcolor(15);
	printf("<[  MENU  ]>");
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
/*void InsercaoDados(TpCliente x[tf],int &tl){
	x[0]={"159.357.654-52","Armelinda",11,1982.54};
	tl++;
}*/
void executar(){
	TpCliente cliente[tf]={"132.456.987-44","Windislaisson",5,2841.63,
						   "651.325.984-77","Astolfo",2,1450.25,
						   "159.357.654-52","Armelinda",11,1982.54};
	TpProduto produto[tf]={7000,"Lasanha",52,9.98,10,9,2024,200,
						   1000,"Suco",188,1.62,15,05,2025,500,
						   4000,"Biscoito",63,4.56,22,11,2024,300};
	TpFornecedor fornecedor[tf]={200,"Fabricia Matao","Matao",
								 500,"Sapore S.A.","Campinas",
								 300,"Basteck","Guarapuava"};
	TpVendas vendas[tf]={1,"651.325.984-77",10,8,2023,451.90,
						 2,"132.456.987-44",15,7,2023,450.60,
						 3,"159.357.654-52",06,04,2023,182.40};
	TpVendasP vendasP[tf]={1,1000,10,1.62,
						   1,7000,20,9.98,
						   1,4000,53,4.56,
						   2,4000,10,4.56,
						   3,7000,1,9.98};
	int tl_cliente=3,tl_produto=3,tl_fornecedor=3,tl_vendas=3,tl_vendasP=5;
	
	char tecla,op;
	do{
		tecla=Formulario();
		switch(tecla){
			case 'A':
				apagar(1);//menu
				gotoxy(5,7),printf("* * Produtos * *");
				apagar(4);//titulo
				gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  ]>");
				op=submenu();
				switch(op){
					case 'A':
						CadastroProduto(produto,tl_produto,fornecedor,tl_fornecedor);
						break;
					case 'B':
						ConsultaProduto(produto,tl_produto);
						break;
					case 'C':
						exclusaoProduto(produto,tl_produto,vendasP,tl_vendasP);
						break;
					case 'D':
						alterarProduto(produto,tl_produto,fornecedor,tl_fornecedor);
						break;
					case 'E':
						RelatorioProduto(produto,tl_produto);
						break;
				}
				break;
			case 'B':
				apagar(1);
				gotoxy(5,7),printf("* * Fornecedor * *");
				apagar(4);//titulo
				gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  ]>");
				op=submenu();
				switch(op){
					case 'A':
						CadastroFornecedor(fornecedor,tl_fornecedor);
						break;
					case 'B':
						ConsultaFornecedor(fornecedor,tl_fornecedor);
						break;
					case 'C':
						exclusaoFornecedor(fornecedor,tl_fornecedor,produto,tl_produto);
						break;
					case 'D':
						alterarFornecedor(fornecedor,tl_fornecedor);
						break;
					case 'E':
						RelatorioFornecedor(fornecedor,tl_fornecedor);
						break;
				}
				break;
			case 'C':
				apagar(1);
				gotoxy(5,7),printf("* * Cliente * *");
				apagar(4);//titulo
				gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  ]>");
				op=submenu();
				switch(op){
					case 'A':
						CadastroCliente(cliente,tl_cliente);
						break;
					case 'B':
						ConsultaCliente(cliente,tl_cliente);
						break;
					case 'C':
						exclusaoCliente(cliente,tl_cliente,vendas,tl_vendas);
						break;
					case 'D':
						alterarCliente(cliente,tl_cliente);
						break;
					case 'E':
						RelatorioCliente(cliente,tl_cliente);
						break;
				}
				break;
			case 'D':
				apagar(1);
				gotoxy(5,7),printf("* * VENDAS * *");
				apagar(4);//titulo
				gotoxy(3,3),printf("<[  MENU  >>  VENDAS  ]>");
				op=VendasMenu();
				switch(op){
					case 'A':
						CadastroVendas(vendas,vendasP,cliente,tl_vendas,tl_vendasP,tl_cliente,produto,tl_produto);
						break;
					case 'B':
						exclusaoVendas(vendas,vendasP,cliente,tl_vendas,tl_vendasP,tl_cliente,produto,tl_produto);
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
