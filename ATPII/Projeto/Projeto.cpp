#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define tf 50
struct TpData{
	int d,m,a;
};
struct TpProduto{
	int cod;
	char descr[24];
	int est;
	float preco;
	TpData data;
	int forn;
};
struct TpFornecedor{
	int cod;
	char nome[30];
	char cidade[34];
};
struct TpCliente{
	char cpf[15];
	char nome[25];
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
int ValidaCPF(char cpf[15]){
    #define TF 11
	char cpfNum[TF], vetCPF[TF];
    int i, j, soma, dgt1, dgt2;

    if(strlen(cpf)==14){
    	for(i = j = 0; i < 14; i++)
	    {
	        if(i != 3 && i != 7 && i != 11)
	        {
				cpfNum[j] = cpf[i];
	            j++;
	        }
	    }
	    cpfNum[11] = '\0';
	    
	     if(strcmp(cpfNum, "00000000000") != 0 && strcmp(cpfNum, "11111111111") != 0 && strcmp(cpfNum, "22222222222") != 0 && strcmp(cpfNum, "33333333333") != 0 && strcmp(cpfNum, "44444444444") != 0 && strcmp(cpfNum, "55555555555") != 0 && strcmp(cpfNum, "66666666666") != 0 && strcmp(cpfNum, "77777777777") != 0 && strcmp(cpfNum, "88888888888") != 0 && strcmp(cpfNum, "99999999999") != 0){
	    	for(i = 0; i < TF; i++)
			vetCPF[i] = cpfNum[i] - '0';
		
			for(i = soma = 0; i < TF - 2; i++)
				soma += vetCPF[i] * (10 - i);
			dgt1 = (soma * 10) % 11;
			
			if(dgt1 == 10)
                dgt1 = 0;

            if(dgt1 == vetCPF[9])
            {
                for(i = soma = 0; i < TF - 1; i++)
                    soma += vetCPF[i] * (11 - i);
                dgt2 = (soma * 10) % 11;

                if(dgt2 == 10)
                    dgt2 = 0;

                if(dgt2 == vetCPF[10])
                    return 1;
                else
                	return -1;
            }
            else
                return -1;
	    }
	    else
			return -1;
    }
	else
		if(strlen(cpf)==0)
			return 1;
		else
			return -1;
}
int ValidaData(TpData data){
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
void limiteString( int c, int l, int tl, char nome[40]){
	char t;
	int i;
	gotoxy(c,l);
	do{
		for(i = 0; i < tl - 1 && t != 13; )
		{
			t = getche();
			if(t == -32 || t == 0){
				getch();
				gotoxy(c,l);
				printf(" ");
				gotoxy(c,l);
			}	
			else{
				if(t != 32 && t != 46 && t < 65 || t > 122  ){
					gotoxy(c,l);
					printf(" ");
					gotoxy(c,l);
				}
				if(t > 64 && t < 123 || t == 32 || t == 46){
					nome[i] = t;
					i++,c++;
				}
				else{
					if(t==8 && i > 0){
						i--;
						c--;
						gotoxy(c,l);
						printf(" ");
						gotoxy(c,l);
					}
				}
			}
			if(i == tl - 1){
				apagar(3);//msg
				gotoxy(3,23),printf("Limite de caracteres!");
				do{
					gotoxy(c,l);
					t=getch();
					if(t==8 && i > 0){
						apagar(3);
						i--;
						c--;
						gotoxy(c,l);
						printf(" ");
						gotoxy(c,l);
					}
				}while(t != 13 && i == tl-1);
			}
		}
		apagar(3);
		nome[i] = '\0';
		if(strlen(nome) == 0){
			gotoxy(3,23);
			printf("Digito invalido.");
			t++;
			getch();
			apagar(3);//msg
			gotoxy(c,l);
		}
	}while(strlen(nome) == 0);
}
int LeInt(int x,int &y,int xf){
	int tl=0,xi=x;
	char letra,nome[TF];
	xf+=x-1;
	do{
		gotoxy(x,y);
		letra=getch();
		if(letra>='0' && letra<='9'){
			if(x<=xf){
				gotoxy(x++,y),printf("%c",letra);
				nome[tl++]=letra;
			}
		}
		else if(letra==8 && x>xi){
			x--;
			gotoxy(x,y),printf(" ");
			tl--;
		}
		nome[tl]='\0';
	}while(letra!=13 || strlen(nome)==0);
	y++;
	return atoi(nome);
}
float LeFloat(int x,int &y,int xf){
	int tl=0,xi=x;
	char letra,nome[TF];
	xf+=x-1;
	do{
		gotoxy(x,y);
		letra=getch();
		if(letra>='0' && letra<='9' || letra=='.'){
			if(x<=xf){
				gotoxy(x++,y),printf("%c",letra);
				nome[tl++]=letra;
			}
		}
		else if(letra==8 && x>xi){
			x--;
			gotoxy(x,y),printf(" ");
			tl--;
		}
		nome[tl]='\0';
	}while(letra!=13 || strlen(nome)==0);
	y++;
	return atof(nome);
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
int buscaVendasP2(TpVendasP x[tf],int tl,int cod){
	int pos=0;
	while(pos<tl && x[pos].codV!=cod)
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
void CadastroFornecedor(TpFornecedor x[tf],int &tl,int &dados){
	char op,aux[30],cid[34];
	int pos,i=8,cod;
	float preco;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  CADASTRO  ]>");
	gotoxy(46,6),printf("* * Cadastro * *");
	apagar(3);//msg
	if(tl==tf){
		gotoxy(30,i++),printf("Lista Cheia ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Fornecedor: ");
		cod=LeInt(52,i,6);
		apagar(3);//msg
		while(tl<tf && cod>0){
			pos=buscaFornecedor(x,tl,cod);
			if(pos<tl){
				apagar(2);//tela
				i--;
				gotoxy(46,6),printf("* * Cadastro * *");
				gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
				gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
				gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
				gotoxy(3,23),printf("Codigo ja Existente!");
				getch();
			}
			else{
				gotoxy(30,i),printf("Nome do Fornecedor: ");
				limiteString(50,i,30,aux),i++;
				gotoxy(30,i),printf("Cidade: ");
				limiteString(38,i,34,cid),i++;
				gotoxy(3,23),printf("Confirmar o cadastro [S/N]? ");
				
				op=toupper(getch());
				if(op == 'S'){
					dados=1;
					x[tl].cod=cod;
					strcpy(x[tl].cidade,cid);
					strcpy(x[tl].nome,aux);
					tl++;
					apagar(3);//msg
					gotoxy(3,23),printf("Cadastro do Fornecedor Realizada com sucesso !");
				}
				else{
					apagar(3);//msg
					gotoxy(3,23),printf("Cadastro do Fornecedor Cancelado !");
				}
				getch();	
			}
			apagar(2);
			i=8;
			if(tl<tf){
				apagar(3);//msg
				gotoxy(46,6),printf("* * Cadastro * *");
				gotoxy(3,23),printf("Digite [0] para sair");
				gotoxy(30,i),printf("Codigo do Fornecedor: ");
				cod=LeInt(52,i,6);
				apagar(3);//msg
			}
			else{
				gotoxy(46,6),printf("* * Cadastro * *");
				apagar(3);//msg
				gotoxy(30,i++),printf("Limite de cadastros atingido ");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
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
	gotoxy(46,6),printf("* * Consulta * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Fornecedor Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Fornecedor: ");
		cod=LeInt(52,i,6);
		apagar(3);//msg
		while(cod > 0){
			pos=buscaFornecedor(x,tl,cod);
			if(pos<tl){
				apagar(2);//tela
				gotoxy(46,6),printf("* * Consulta * *");
				i--;
				gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
				gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
				gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
				apagar(3);//msg
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				apagar(3);//msg
				gotoxy(3,23),printf("Codigo nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			apagar(3);//msg
			gotoxy(46,6),printf("* * Consulta * *");
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(30,i),printf("Codigo do Fornecedor: ");
			cod=LeInt(52,i,6);
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
	gotoxy(46,6),printf("* * Exclusao * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Fornecedor Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Fornecedor: ");
		cod=LeInt(52,i,6);
		apagar(3);//msg
		while(tl>0 && cod>0){
			pos=buscaFornecedor(x,tl,cod);
			if(pos<tl){
				pos1=buscaCodigo(p,tlp,cod);
				if(pos1==tlp){
					apagar(2);//tela
					gotoxy(46,6),printf("* * Exclusao * *");
					i--;
					gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
					gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
					gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
					gotoxy(3,23),printf("Confirmar a exclusao? [S/N]");
					op=toupper(getch());
					if(op=='S'){
						for(;pos<tl-1;pos++)
							x[pos]=x[pos+1];
						tl--;
						apagar(3);//msg
						gotoxy(3,23),printf("Exclusao do Fornecedor Realizada com sucesso !");
					}
					else{
						apagar(3);//msg
						gotoxy(3,23),printf("Exclusao do Fornecedor Cancelado !");
					}
					getch();
				}
				else{
					apagar(2);
					i--;
					gotoxy(46,6),printf("* * Exclusao * *");
					gotoxy(30,i++),printf("Codigo cadastrado no Produto:");
					gotoxy(30,i++),printf("Cod. do Produto: %d",p[pos].cod);
					gotoxy(30,i++),printf("Descrisao: %s",p[pos].descr);
					gotoxy(30,i++),printf("Estoque: %d",p[pos].est);
					gotoxy(30,i++),printf("Preco: R$%.2f",p[pos].preco);
					gotoxy(30,i++),printf("Data: %d/%d/%d",p[pos].data.d,p[pos].data.m,p[pos].data.a);
					gotoxy(30,i++),printf("Cod. Fornecedor: %d",p[pos].forn);
					
					gotoxy(30,20),printf("Excluir Primeiramente o Produto %d ! ",p[pos].cod);
					gotoxy(3,23),printf("[ENTER] Continuar...");
					getch();
				}
			}
			else{
				apagar(3);//msg
				gotoxy(3,23),printf("Codigo nao cadastrado !");
				getch();
			}
			apagar(3);//mensagem
			apagar(2);//tela
			i=8;
			if(tl>0){
				gotoxy(46,6),printf("* * Exclusao * *");
				apagar(3);//msg
				gotoxy(3,23),printf("Digite [0] para sair");
				gotoxy(30,i),printf("Codigo do Fornecedor: ");
				cod=LeInt(52,i,6);
				apagar(3);//msg
			}
			else{
				apagar(3);//msg
				gotoxy(46,6),printf("* * Exclusao * *");
				gotoxy(30,i++),printf("Fornecedores excluidos !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
		}
	}
}
void alterarFornecedor(TpFornecedor x[tf],int tl){
	char op,aux[40],aux2[40];
	int pos,i=8,cod;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  ALTERACAO  ]>");
	apagar(2);//tela
	gotoxy(46,6),printf("* * Alteracao * *");
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Fornecedor Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Fornecedor: ");
		cod=LeInt(52,i,6);
		apagar(3);//msg
		while(cod>0){ 
			apagar(3);//msg
			pos=buscaFornecedor(x,tl,cod);
			if(pos==tl){
				apagar(2);//tela
				gotoxy(46,6),printf("* * Alteracao * *");
				gotoxy(30,i++),printf("Codigo nao cadastrado !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				apagar(3);//msg
				gotoxy(30,i++),printf("Nome do Fornecedor: %s",x[pos].nome);
				gotoxy(30,i),printf("Novo nome: ");
				limiteString(41,i,30,aux),i++;
				gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
				gotoxy(30,i),printf("Nova Cidade: ",x[pos].cidade);
				limiteString(43,i,34,aux2),i++;
				gotoxy(3,23),printf("Confirmar a alteracao [S/N]? ");
				op=toupper(getch());
				apagar(3);//msg
				if(op == 'S'){
					strcpy(x[pos].nome,aux);
					strcpy(x[pos].cidade,aux2);
					apagar(3);//msg
					gotoxy(3,23),printf("Alteracao do Fornecedor Realizada com sucesso !");
				}
				else{
					apagar(3);//msg
					gotoxy(3,23),printf("Alteracao do Fornecedor Cancelado !");
				}
				getch();	
			}
			apagar(2);
			i=8;
			apagar(3);//msg
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(46,6),printf("* * Alteracao * *");
			gotoxy(30,i),printf("Codigo do Fornecedor: ");
			cod=LeInt(52,i,6);
			apagar(3);//msg
		}
	}
}
void RelatorioFornecedor(TpFornecedor x[tf],int tl){
	int pos=0,i=8;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(3);//msg
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  RELATORIO  ]>");
	gotoxy(46,6),printf("* * Relatorio * *");
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Fornecedor Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		do{
			gotoxy(46,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
			gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
			gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
			gotoxy(70,20),printf("Pagina %d",pos+1);
			if(pos==0 && tl!=1){
				gotoxy(76,13),printf("[%c]",25);
			}	
			else if(pos<tl-1){
				gotoxy(76,12),printf("[%c]",24);
				gotoxy(76,13),printf("[%c]",25);
			}
			else if(tl!=1){
				gotoxy(76,12),printf("[%c]",24);
			}
			gotoxy(3,23),printf("[ESC] para sair");
			op=getch();
			if(op==-32){
				op=getch();
				if(op==80 && pos<tl-1)
					pos++;
				else if(op==72 && pos>0)
					pos--;
			}
			i=8;
			apagar(2);//tela
		}while(op!=27);
	}
}
void CadastroProduto(TpProduto x[tf],int &tl,TpFornecedor f[tf],int tlf,int &dados){
	char op,aux[24];
	int pos,i=8,cod,forn,est,val;
	float preco;
	TpData data;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  CADASTRO  ]>");
	gotoxy(46,6),printf("* * Cadastro * *");
	apagar(3);//msg
	if(tl==tf){
		gotoxy(30,i++),printf("Lista Cheia ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		if(tlf==0){
			gotoxy(30,i++),printf("Nenhum Fornecedor Cadastrado !");
			apagar(3);//msg
			gotoxy(3,23),printf("[ENTER] Continuar...");
			getch();
		}
		else{
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(30,i),printf("Codigo do Produto: ");
			cod=LeInt(49,i,5);
			apagar(3);//msg
			while(tl<tf && cod>0){
				pos=buscaProduto(x,tl,cod);
				if(pos<tl){
					apagar(2);//tela
					gotoxy(46,6),printf("* * Cadastro * *");i--;
					gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
					gotoxy(30,i++),printf("Descricao: %s",x[pos].descr);
					gotoxy(30,i++),printf("Estoque: %d",x[pos].est);
					gotoxy(30,i++),printf("Preco: R$%.2f",x[pos].preco);
					gotoxy(30,i++),printf("Data de validade: %d/%d/%d",x[pos].data.d,x[pos].data.m,x[pos].data.a);
					gotoxy(30,i++),printf("Cod. Fornecedor: %d",x[pos].forn);
					apagar(3);//msg
					gotoxy(3,23),printf("Codigo ja Existente!");
					getch();
				}
				else{
					gotoxy(30,i),printf("Codigo do Fornecedor: ");
					forn=LeInt(52,i,6);
					pos=buscaFornecedor(f,tlf,forn);
					while(pos==tlf && forn!=0){
						i--;
						gotoxy(3,23),printf("Fornecedor Inexistente! ");
						gotoxy(30,i),printf("Codigo do Fornecedor: ");
						gotoxy(52,i),printf("          ");
						forn=LeInt(52,i,6);
						if(forn!=0)
							pos=buscaFornecedor(f,tlf,forn);
					}
					apagar(3);//msg
					if(forn!=0){
						gotoxy(30,i),printf("Descricao: ");
						limiteString(41,i,24,aux),i++;
						
						//gotoxy(30,i++),printf("Estoque: ");
						do{
							gotoxy(30,i),printf("Estoque: ");
							gotoxy(39,i),printf("     ");
							est=LeInt(39,i,5);
							if(est < 0){
								gotoxy(3,23),printf("Quantidade invalida !");
								i--;
							}
						}while(est < 0);
						apagar(3);//msg
						
						do{
							gotoxy(30,i),printf("Preco: ");
							gotoxy(38,i),printf("            ");
							preco=LeFloat(38,i,8);
							if(preco <= 0){
								gotoxy(3,23),printf("Preco Invalido !");
								i--;
							}
						}while(preco <= 0);
						apagar(3);//msg
						gotoxy(30,i++),printf("Data de validade [dd mm aaaa]: ");
						scanf("%d%d%d",&data.d,&data.m,&data.a);
						val=ValidaData(data);
						while(val==-1){
							apagar(3);//msg
							gotoxy(3,23),printf("Data Invalida !");
							gotoxy(30,i-1),printf("                                        ");
							gotoxy(30,i-1),printf("Data de validade [dd mm aa]: ");
							scanf("%d%d%d",&data.d,&data.m,&data.a);
							val=ValidaData(data);
						}
						gotoxy(3,23),printf("Confirmar o cadastro [S/N]? ");
						op=toupper(getch());
						if(op == 'S'){
							dados=1;
							x[tl].cod=cod;
							x[tl].forn=forn;
							strcpy(x[tl].descr,aux);
							x[tl].est=est;
							x[tl].preco=preco;
							x[tl].data.d=data.d;
							x[tl].data.m=data.m;
							x[tl].data.a=data.a;
							tl++;
							apagar(3);//msg
							gotoxy(3,23),printf("Cadastro do Produto Realizado com sucesso !");
						}
						else{
							apagar(3);//msg
							gotoxy(3,23),printf("Cadastro do Produto Cancelado !");
						}
						getch();
					}
				}
				apagar(2);
				i=8;
				if(tl<tf){
					apagar(3);//msg
					gotoxy(3,23),printf("Digite [0] para sair");
					gotoxy(46,6),printf("* * Cadastro * *");
					gotoxy(30,i),printf("Codigo do Produto: ");
					cod=LeInt(49,i,53);
					apagar(3);//msg
				}
				else{
					gotoxy(46,6),printf("* * Cadastro * *");
					apagar(3);//msg
					gotoxy(30,i++),printf("Limite de cadastros atingido ");
					gotoxy(3,23),printf("[ENTER] Continuar...");
					getch();
				}
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
	gotoxy(46,6),printf("* * Consulta * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Produto Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Produto: ");
		cod=LeInt(49,i,53);
		apagar(3);//msg
		while(cod>0){
			pos=buscaProduto(x,tl,cod);
			if(pos<tl){
				apagar(2);//tela
				i--;
				gotoxy(46,6),printf("* * Consulta * *");
				gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
				gotoxy(30,i++),printf("Descricao: %s",x[pos].descr);
				gotoxy(30,i++),printf("Estoque: %d",x[pos].est);
				gotoxy(30,i++),printf("Preco: R$%.2f",x[pos].preco);
				gotoxy(30,i++),printf("Data: %d/%d/%d",x[pos].data.d,x[pos].data.m,x[pos].data.a);
				gotoxy(30,i++),printf("Cod. Fornecedor: %d",x[pos].forn);
				apagar(3);//msg
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				apagar(3);//msg
				gotoxy(3,23),printf("Codigo nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			apagar(3);//msg
			gotoxy(46,6),printf("* * Consulta * *");
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(30,i),printf("Codigo do Produto: ");
			cod=LeInt(49,i,53);
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
	gotoxy(46,6),printf("* * Exclusao * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Produto Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Produto: ");
		cod=LeInt(49,i,53);
		apagar(3);//msg
		while(tl>0 && cod>0){
			pos=buscaProduto(x,tl,cod);
			if(pos<tl){
				pos1=buscaVendasP(v,tlv,cod);
				if(pos1==tlv){
					apagar(2);//tela
					gotoxy(46,6),printf("* * Exclusao * *");
					i--;
					gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
					gotoxy(30,i++),printf("Descricao: %s",x[pos].descr);
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
						apagar(3);//msg
						gotoxy(3,23),printf("Exclusao do Produto Realizada com sucesso !");
					}
					else{
						apagar(3);//msg
						gotoxy(3,23),printf("Exclusao do Produto Cancelada !");
					}
					getch();
				}
				else{
					apagar(2);
					i--;
					gotoxy(46,6),printf("* * Exclusao * *");
					gotoxy(30,i++),printf("Codigo cadastrado na Vendas:");
					gotoxy(30,i++),printf("Cod. da Venda: %d",v[pos1].codV);
					gotoxy(30,i++),printf("Cod. do Produto: %d",v[pos1].codP);
					gotoxy(30,i++),printf("Preco: R$%.2f",v[pos1].preco);
					gotoxy(30,i++),printf("Qtde comprada: %d",v[pos1].qtde);
					
					gotoxy(30,20),printf("Excluir Primeiramente a Venda %d ! ",v[pos1].codV);
					gotoxy(3,23),printf("[ENTER] Continuar...");
					getch();
				}
			}
			else{
				apagar(3);//msg
				gotoxy(3,23),printf("Codigo nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			if(tl>0){
				gotoxy(46,6),printf("* * Exclusao * *");
				apagar(3);//msg
				gotoxy(3,23),printf("Digite [0] para sair");
				gotoxy(30,i),printf("Codigo do Produto: ");
				cod=LeInt(49,i,53);
				apagar(3);//msg
			}
			else{
				apagar(3);//msg
				gotoxy(46,6),printf("* * Exclusao * *");
				gotoxy(30,i++),printf("Produtos excluidos !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
		}
	}
}
void alterarProduto(TpProduto x[tf],int tl,TpFornecedor f[tf],int tlf){
	char op,aux[24];
	int pos,i=8,pos1,cod,forn,est,val;
	TpData data;
	float preco;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(2);//tela
	gotoxy(46,6),printf("* * Alteracao * *");
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  ALTERACAO  ]>");
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Produto Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{	
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Produto: ");
		cod=LeInt(49,i,5);
		while(cod>0){
			apagar(3);//msg
			pos=buscaProduto(x,tl,cod);
			if(pos==tl){
				apagar(2);//tela
				gotoxy(46,6),printf("* * Alteracao * *");
				i--;
				gotoxy(30,i++),printf("Codigo nao cadastrado !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				gotoxy(30,i),printf("Fornecedor: %d",x[pos].forn);
				gotoxy(49,i),printf("->");
				forn=LeInt(52,i,6);
				pos1=buscaFornecedor(f,tlf,forn);
				while(pos1==tlf){
					gotoxy(3,23),printf("Fornecedor Inexistente! ");
					i--;
					gotoxy(30,i),printf("                                                 ");
					gotoxy(30,i),printf("Fornecedor: %d",x[pos].forn);
					gotoxy(49,i),printf("->");
					forn=LeInt(52,i,6);
					pos1=buscaFornecedor(f,tlf,forn);
				}
				apagar(3);//msg
				gotoxy(30,i++),printf("Descricao: %s",x[pos].descr);
				gotoxy(30,i),printf("Nova descricao: ");
				limiteString(46,i,24,aux),i++;
				//gotoxy(30,i++),printf("Estoque: %d -> ",x[pos].est);
				gotoxy(30,i),printf("Estoque: %d",x[pos].est);
				gotoxy(44,i),printf("->");
				est=LeInt(47,i,5);
				//gotoxy(30,i++),printf("Preco: R$%.2f -> ",x[pos].preco);
				gotoxy(30,i),printf("Preco: R$%.2f",x[pos].preco);
				gotoxy(47,i),printf("->");
				preco=LeFloat(50,i,8);
				gotoxy(30,i++),printf("Data de validade: %d/%d/%d -> ",x[pos].data.d,x[pos].data.m,x[pos].data.a);
				scanf("%d%d%d",&data.d,&data.m,&data.a);
				val=ValidaData(data);
				while(val==-1){
					gotoxy(30,i-1),printf("                                           ");
					gotoxy(30,i-1),printf("Data de validade: %d/%d/%d -> ",x[pos].data.d,x[pos].data.m,x[pos].data.a);
					scanf("%d%d%d",&data.d,&data.m,&data.a);
					val=ValidaData(data);
				}
				gotoxy(3,23),printf("Confirmar a alteracao [S/N]? ");
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
					apagar(3);//msg
					gotoxy(3,23),printf("Alteracao do produto Realizada com sucesso !");
				}
				else{
					apagar(3);//msg
					gotoxy(3,23),printf("Alteracao do produto Cancelada !");
				}
				getch();
			}
			apagar(2);
			i=8;
			apagar(3);//msg
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(46,6),printf("* * Alteracao * *");
			gotoxy(30,i),printf("Codigo do Produto: ");
			cod=LeInt(49,i,5);
			apagar(3);//msg
		}
	}
}
void RelatorioProduto(TpProduto x[tf],int tl){
	int pos=0,i=8;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(3);//msg
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  RELATORIO  ]>");
	gotoxy(46,6),printf("* * Relatorio * *");
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Produto Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		do{
			gotoxy(46,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
			gotoxy(30,i++),printf("Descricao: %s",x[pos].descr);
			gotoxy(30,i++),printf("Estoque: %d",x[pos].est);
			gotoxy(30,i++),printf("Preco: R$%.2f",x[pos].preco);
			gotoxy(30,i++),printf("Data de validade: %d/%d/%d",x[pos].data.d,x[pos].data.m,x[pos].data.a);
			gotoxy(30,i++),printf("Cod. Fornecedor: %d",x[pos].forn);
			gotoxy(70,20),printf("Pagina %d",pos+1);
			if(pos==0 && tl!=1){
				gotoxy(76,13),printf("[%c]",25);
			}	
			else if(pos<tl-1){
				gotoxy(76,12),printf("[%c]",24);
				gotoxy(76,13),printf("[%c]",25);
			}
			else if(tl!=1){
				gotoxy(76,12),printf("[%c]",24);
			}
			gotoxy(3,23),printf("[ESC] para sair");
			op=getch();
			if(op==-32){
				op=getch();
				if(op==80 && pos<tl-1)
					pos++;
				else if(op==72 && pos>0)
					pos--;
			}
			i=8;
			apagar(2);//tela
		}while(op!=27);
	}
}
void CadastroCliente(TpCliente x[tf],int &tl,int &dados){
	char cpf[15],aux[25],op;
	int pos,i=8;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  CADASTRO  ]>");
	apagar(2);
	gotoxy(46,6),printf("* * Cadastro * *");
	apagar(3);//msg
	if(tl==tf){
		gotoxy(30,i++),printf("Lista Cheia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Aperte [ENTER] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(cpf);
		while(ValidaCPF(cpf)==-1){
			apagar(3);//msg
			gotoxy(3,23),printf("CPF Invalido !");
			getch();
			apagar(3);//msg
			gotoxy(3,23),printf("Digite [ENTER] para sair");
			gotoxy(30,i-1),printf("                                        ");
			gotoxy(30,i-1),printf("CPF do cliente: ");
			gets(cpf);
		}
		apagar(3);//msg
		while(tl<tf && strlen(cpf)>0){
			pos=buscaCliente(x,tl,cpf);
			if(pos<tl){
				gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
				gotoxy(30,i++),printf("Quantidade: %d",x[pos].qtde);
				gotoxy(30,i++),printf("Total: %.2f",x[pos].total);
				gotoxy(3,23),printf("Codigo ja Existente!");
				getch();
			}
			else{
				gotoxy(30,i),printf("Nome do Cliente: ");
				limiteString(47,i,25,aux),i++;
				gotoxy(3,23),printf("Confirmar o cadastro [S/N]? ");
				op=toupper(getch());
				if(op == 'S'){
					dados=1;
					strcpy(x[tl].cpf,cpf);
					strcpy(x[tl].nome,aux);
					x[tl].qtde=0;
					x[tl].total=0;
					tl++;
					apagar(3);//msg
					gotoxy(3,23),printf("Cadastro do cliente Realizado com sucesso !");
				}
				else{
					apagar(3);//msg
					gotoxy(3,23),printf("Cadastro do cliente Cancelado !");
				}
				getch();
			}
			apagar(2);
			i=8;
			if(tl<tf){
				apagar(3);//msg
				gotoxy(46,6),printf("* * Cadastro * *");
				gotoxy(3,23),printf("Digite [ENTER] para sair");
				gotoxy(30,i++),printf("CPF do cliente: ");
				gets(cpf);
				while(ValidaCPF(cpf)==-1){
					apagar(3);//msg
					gotoxy(3,23),printf("CPF Invalido !");
					getch();
					apagar(3);//msg
					gotoxy(3,23),printf("Aperte [ENTER] para sair");
					gotoxy(30,i-1),printf("                                        ");
					gotoxy(30,i-1),printf("CPF do cliente: ");
					gets(cpf);
				}
				apagar(3);//msg
			}
			else{
				gotoxy(46,6),printf("* * Cadastro * *");
				apagar(3);//msg
				gotoxy(30,i++),printf("Limite de cadastros atingido ");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
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
	gotoxy(46,6),printf("* * Consulta * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Cliente Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Aperte [ENTER] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(cpf);
		apagar(3);//msg
		while(strlen(cpf)>0){
			pos=buscaCliente(x,tl,cpf);
			if(pos<tl){
				apagar(2);//tela
				i--;
				gotoxy(45,6),printf("* * Consulta * *");
				gotoxy(30,i++),printf("CPF: %s",x[pos].cpf);
				gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
				gotoxy(30,i++),printf("Quantidade: %d",x[pos].qtde);
				gotoxy(30,i++),printf("Total: %.2f",x[pos].total);
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				apagar(3);//msg
				gotoxy(3,23),printf("CPF nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			apagar(3);//msg
			gotoxy(46,6),printf("* * Consulta * *");
			gotoxy(3,23),printf("Aperte [ENTER] para sair");
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
	gotoxy(46,6),printf("* * Exclusao * *");
	apagar(3);//msg
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Cliente Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Aperte [ENTER] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(cpf);
		apagar(3);//msg
		while(tl>0 && strlen(cpf)>0){
			if(pos)
			pos=buscaCliente(x,tl,cpf);
			if(pos<tl){
				pos1=buscaCPF(v,tlv,cpf);
				if(pos1==tlv){
					apagar(2);//tela
					i--;
					gotoxy(46,6),printf("* * Exclusao * *");
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
						apagar(3);//msg
						gotoxy(3,23),printf("Exclusao do cliente Realizado com sucesso !");
					}
					else{
						apagar(3);//msg
						gotoxy(3,23),printf("Exclusao do cliente Cancelado !");
					}
					getch();
				}
				else{
					apagar(2);//tela
					gotoxy(46,6),printf("* * Exclusao * *");
					gotoxy(30,i++),printf("CPF cadastrado na Venda:");i++;
					gotoxy(30,i++),printf("Cod. da Venda: %d",v[pos1].cod);
					gotoxy(30,i++),printf("CPF: %s",v[pos1].cpf);
					gotoxy(30,i++),printf("Data: %d/%d/%d",v[pos1].data.d,v[pos1].data.m,v[pos1].data.a);
					gotoxy(30,i++),printf("Total Comprado: R$%.2f",v[pos1].total);
					
					gotoxy(30,20),printf("Excluir Primeiramente a Venda %d ! ",v[pos1].cod);
					gotoxy(3,23),printf("[ENTER] Continuar...");
					getch();
				}
			}
			else{
				apagar(3);//msg
				gotoxy(3,23),printf("CPF nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			if(tl>0){
				gotoxy(46,6),printf("* * Exclusao * *");
				apagar(3);//msg
				gotoxy(3,23),printf("Aperte [ENTER] para sair");
				gotoxy(30,i++),printf("CPF do cliente: ");
				gets(cpf);
				apagar(3);//msg
			}
			else{
				apagar(3);//msg
				gotoxy(46,6),printf("* * Exclusao * *");
				gotoxy(30,i++),printf("Clientes excluidos !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}	
		}
	}
}
void alterarCliente(TpCliente x[tf],int tl){
	char op,cpf[15],aux[25];
	int pos,i=8;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(2);
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  ALTERACAO  ]>");
	gotoxy(46,6),printf("* * Alteracao * *");
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Cliente Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		apagar(2);//tela
		gotoxy(46,6),printf("* * Alteracao * *");
		gotoxy(3,23),printf("Digite [ENTER] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(cpf);
		while(strlen(cpf)>0){
			apagar(3);//msg
			pos=buscaCliente(x,tl,cpf);
			if(pos==tl){
				apagar(2);//tela
				gotoxy(46,6),printf("* * Alteracao * *");
				gotoxy(30,i++),printf("CPF nao cadastrado !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				apagar(3);//msg
				gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
				gotoxy(30,i),printf("Novo nome: ");
				limiteString(41,i,25,aux),i++;
				gotoxy(3,23),printf("Confirmar a alteracao [S/N]? ");
				op=toupper(getch());
				apagar(3);//msg
				if(op == 'S'){
					strcpy(x[pos].nome,aux);
					apagar(3);//msg
					gotoxy(3,23),printf("Alteracao do cliente Realizado com sucesso !");
				}
				else{
					apagar(3);//msg
					gotoxy(3,23),printf("Alteracao do cliente Cancelado !");
				}	
				getch();
			}
			apagar(2);
			i=8;
			apagar(3);//msg
			gotoxy(3,23),printf("Digite [ENTER] para sair");
			gotoxy(46,6),printf("* * Alteracao * *");
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
	apagar(2);
	apagar(3);//msg
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  RELATORIO  ]>");
	gotoxy(46,6),printf("* * Relatorio * *");
	if(tl==0){
		gotoxy(30,i++),printf("Nenhum Cliente Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		do{
			gotoxy(46,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("CPF: %s",x[pos].cpf);
			gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
			gotoxy(30,i++),printf("Quantidade de venda: %d",x[pos].qtde);
			gotoxy(30,i++),printf("Total de compra: R$%.2f",x[pos].total);
			gotoxy(70,20),printf("Pagina %d",pos+1);
			if(pos==0 && tl!=1){
				gotoxy(76,13),printf("[%c]",25);
			}	
			else if(pos<tl-1){
				gotoxy(76,12),printf("[%c]",24);
				gotoxy(76,13),printf("[%c]",25);
			}
			else if(tl!=1){
				gotoxy(76,12),printf("[%c]",24);
			}
			gotoxy(3,23),printf("[ESC] para sair");
			op=getch();
			if(op==-32){
				op=getch();
				if(op==80 && pos<tl-1)
					pos++;
				else if(op==72 && pos>0)
					pos--;	
			}
			i=8;
			apagar(2);//tela
		}while(op!=27);
	}
}
void PrintCupom(TpVendas v[tf], TpCliente c[tf], TpVendasP vp[tf], TpProduto p[tf], int TLV, int TLC, int TLVP, int TLP,int cod,int ext);
void CadastroVendas(TpVendas v[tf],TpVendasP vp[tf],TpCliente c[tf],int &tlv,int &tlvP,int tlc,TpProduto x[tf],int tlp,int &dados){
	char cpf[15],aux[30],op;
	int pos,pos2,i=8,cod,pos1,qtde,num,ext,venda;
	float total;
	
	time_t t;
	t = time(NULL);
	tm tempo;
	tempo= *localtime(&t);
	
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  VENDAS  >>  CADASTRO  ]>");
	apagar(2);
	gotoxy(46,6),printf("* * Cadastro * *");
	apagar(3);//msg
	if(tlv==tf && tlvP==tf){
		gotoxy(30,i++),printf("Lista Cheia ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		if(tlc==0){
			gotoxy(30,i++),printf("Nenhum Cliente Cadastrado !");
		}
		if(tlp==0){
			gotoxy(30,i++),printf("Nenhum Produto Cadastrado !");
		}
		gotoxy(3,23),printf("Aperte [ENTER] para sair");
		if(tlp>0 && tlc>0){
			gotoxy(30,i++),printf("CPF do cliente: ");
			fflush(stdin);
			gets(cpf);
			apagar(3);//msg
			
			total=0;
			while(tlv<tf && tlvP<tf && strlen(cpf)>0){
				pos=buscaCliente(c,tlc,cpf);
				if(pos==tlc){
					gotoxy(3,23),printf("CPF nao cadastrado !");
					getch();
				}
				else{
					if(tlv==0)
						v[tlv].cod=1;
					else
						v[tlv].cod=v[tlv-1].cod+1;
						
					num=v[tlv].cod;
					gotoxy(30,i),printf("Codigo do Produto: ");
					cod=LeInt(49,i,5);
					apagar(3);//msg
					while(tlv<tf && tlvP<tf && cod>0){
						venda=0;
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
								gotoxy(30,i),printf("Quantidade da venda: ");
								qtde=LeInt(51,i,5);
								while(qtde<=0 || qtde>x[pos1].est){
									gotoxy(3,23),printf("Quantidade Invalida! ");
									i--;
									gotoxy(30,i),printf("                                            ");
									gotoxy(30,i),printf("Quantidade da venda: ");
									qtde=LeInt(51,i,5);
								}
								apagar(3);//msg
								gotoxy(3,23),printf("Confirmar venda do Produto [S/N]? ");
								op=toupper(getch());
								if(op == 'S'){
									dados=1;
									vp[tlvP].codV=num;
									vp[tlvP].codP=cod;
									vp[tlvP].qtde=qtde;
									vp[tlvP].preco=x[pos1].preco;
									x[pos1].est-=qtde;
									total+=vp[tlvP].preco*qtde;
									tlvP++;
									apagar(3);//msg
									gotoxy(3,23),printf("Produto adicionado !");
									venda=1;
								}
								else{
									apagar(3);//msg
									gotoxy(3,23),printf("Venda Cancelada !");
								}
								getch();
							}
						}
						else{
							apagar(3);//msg
							gotoxy(3,23),printf("Produto nao cadastrado !");
							getch();
						}
						apagar(2);
						i=8;
						if(tlv<tf && tlvP<tf){
							apagar(3);//msg
							gotoxy(3,23),printf("Digite [0] para sair");
							gotoxy(46,6),printf("* * Vendas * *");
							gotoxy(30,i++),printf("CPF do cliente: %s",cpf);
							gotoxy(30,i),printf("                                          ");
							gotoxy(30,i),printf("Codigo do Produto: ");
							cod=LeInt(49,i,5);
							apagar(3);//msg
						}
					}
					
					if(venda==1){
						strcpy(v[tlv].cpf,cpf);
						v[tlv].total=total;
						v[tlv].data.d=tempo.tm_mday;
						v[tlv].data.m=tempo.tm_mon+1;
						v[tlv].data.a=tempo.tm_year+1900;
						c[pos].total+=total;
						c[pos].qtde++;
						tlv++;
						ext = buscaVendas(v, tlv, tlv);
						PrintCupom(v, c, vp, x, tlv, tlc, tlvP, tlp,tlv,ext);
					}	
				}
				apagar(2);
				i=8;
				if(tlv<tf || tlvP<tf){
					apagar(3);//msg
					gotoxy(3,23),printf("Aperte [ENTER] para sair");
					gotoxy(46,6),printf("* * Vendas * *");
					gotoxy(30,i++),printf("CPF do cliente: ");
					fflush(stdin);
					gets(cpf);
					apagar(3);//msg
				}
				else
					if(tlv==tf){
						gotoxy(46,6),printf("* * Cadastro * *");
						apagar(3);//msg
						gotoxy(30,i++),printf("Limite de cadastros de vendas atingido ");
						gotoxy(3,23),printf("[ENTER] Continuar...");
						getch();
					}
					else{
						gotoxy(46,6),printf("* * Cadastro * *");
						apagar(3);//msg
						gotoxy(30,i++),printf("Limite de cadastros venda de produtos atingido ");
						gotoxy(3,23),printf("[ENTER] Continuar...");
						getch();
					}
			}
		}
		else
			getch();
	}
}
void exclusaoVendas(TpVendas v[tf],TpVendasP vp[tf],TpCliente c[tf],int &tlv,int &tlvP,int tlc,TpProduto x[tf],int tlp){
	int pos,pos1,cod,i=8;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  VENDAS  >>  EXCLUSAO  ]>");
	apagar(2);
	gotoxy(46,6),printf("* * Exclusao * *");
	apagar(3);//msg
	if(tlv==0){
		gotoxy(30,i++),printf("Vendas nao realizadas !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		apagar(3);//msg
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo da venda: ");
		cod=LeInt(48,i,4);
		apagar(3);//msg
		while(tlv>0 && cod>0){
			pos=buscaVendas(v,tlv,cod);
			if(pos==tlv){
				gotoxy(3,23),printf("Venda nao cadastrada !");
				getch();
			}
			else{
				gotoxy(30,i++),printf("CPF: %s",v[pos].cpf);
				gotoxy(30,i++),printf("Data da compra: %d/%d/%d",v[pos].data.d,v[pos].data.m,v[pos].data.a);
				gotoxy(30,i++),printf("Total da venda: R$%.2f",v[pos].total);
				gotoxy(3,23),printf("Confirmar Exclusao do Produto [S/N]? ");
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
					pos=buscaVendasP2(vp,tlvP,cod);
					while(pos<tlvP){
						pos1=buscaProduto(x,tlp,vp[pos].codV);
						x[pos1].est+=vp[pos].qtde;
						for(i=pos;i<tlvP-1;i++){
							vp[i]=vp[i+1];
						}
						tlvP--;
						pos=buscaVendasP2(vp,tlvP,cod);
					}
					pos=buscaVendasP2(vp,tlvP,cod+1);
					for(i=pos;i<tlvP;i++)
						vp[i].codV--;
					apagar(3);//msg
					gotoxy(3,23),printf("Exclusao realizada com sucesso !");
				}
				else{
					apagar(3);//msg
					gotoxy(3,23),printf("Exclusao cancelada !");	
				}
				getch();
			}
			i=8;
			apagar(2);
			if(tlv > 0){
				apagar(3);//msg
				gotoxy(46,6),printf("* * Exclusao * *");
				gotoxy(3,23),printf("Digite [0] para sair");
				gotoxy(30,i),printf("Codigo da venda: ");
				cod=LeInt(48,i,4);
			}
			else{
				apagar(3);//msg
				gotoxy(46,6),printf("* * Exclusao * *");
				gotoxy(30,i++),printf("Vendas excluidas !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			
		}
	}
}
int contaVenda(TpVendasP x[tf],int tl,int cod){
	int i,cont;
	for(i=cont=0;i<tl;i++)
		if(cod == x[i].codV)
			cont++;
	return cont;
}
void PaginaCupom(int &i){
	apagar(3);//msg
	gotoxy(3,23),printf("[ENTER] Continuar...");
	getch();
	apagar(3);//msg
	apagar(2);//tela
	gotoxy(44,6),printf("* * Cupom Fiscal * *");
	i=8;
}
void PrintCupom(TpVendas v[tf], TpCliente c[tf], TpVendasP vp[tf], TpProduto p[tf], int TLV, int TLC, int TLVP, int TLP,int cod,int ext){
	int i = 8, pos, pos1, it;
	float tot;
	pos = buscaCliente(c, TLC,v[ext].cpf);
	apagar(2);//tela
	gotoxy(44,6),printf("* * Cupom Fiscal * *");
	pos1=buscaVendas(v,TLV,cod);
	gotoxy(30,i),printf("Nome: %s",c[pos].nome);
	gotoxy(61,i++),printf("Data: %d/%d/%d",v[pos1].data.d,v[pos1].data.m,v[pos1].data.a);
	gotoxy(30,i++),printf("CPF: %s",c[pos].cpf),i++;
	gotoxy(30,i++),printf("CUPOM FISCAL");
	gotoxy(30,i++),printf("-----------------------------------------------");
	gotoxy(30,i++),printf("ITEM  QTDE  PRODUTO                 VALOR");
	
	for(pos = buscaVendasP2(vp,TLVP,cod), it = 1, tot = 0.0; cod == vp[pos].codV; pos++, it++,i++)
	{
		gotoxy(30,i),printf("%d",it);
		gotoxy(36,i),printf("%d",vp[pos].qtde);
		gotoxy(42,i),printf("%s",p[buscaProduto(p,TLP,vp[pos].codP)].descr);
		tot += vp[pos].qtde * vp[pos].preco;
		gotoxy(66,i),printf("R$ %.2f",vp[pos].qtde*vp[pos].preco);
		if(i==19){
			PaginaCupom(i);
			gotoxy(30,i),printf("ITEM  QTDE  PRODUTO                 VALOR");
		}
	}

	if(i>17)
		PaginaCupom(i);
	gotoxy(30,i++),printf("-----------------------------------------------");
	gotoxy(66,i++),printf("TOTAL");
	gotoxy(66,i++),printf("R$ %.2f",tot);
	gotoxy(30,i),printf("-----------------------------------------------");
	
	gotoxy(3,23),printf("[ENTER] Finalizar o Cupom Fiscal");
	getch();
}
void CupomFiscal(TpVendas v[tf], TpCliente c[tf], TpVendasP vp[tf], TpProduto p[tf], int TLV, int TLC, int TLVP, int TLP){
	int i = 8, pos, cod, ext, it;
	float tot;
	
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  VENDAS >>  CUPOM FISCAL  ]>");
	apagar(3);//msg
	gotoxy(44,6),printf("* * Cupom Fiscal * *");
	
	if(TLV > 0)
	{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i++),printf("Codigo da venda: ");
		scanf("%d", &cod);
		
		while(cod > 0)
		{
			ext = buscaVendas(v, TLV, cod);
			if(ext < TLV)
			{
				PrintCupom(v, c, vp, p, TLV, TLC, TLVP, TLP,cod,ext);
			}
			else
			{
				gotoxy(3,23),printf("Codigo de venda inexistente !");
				getch();
			}
			apagar(2);//tela
			i=8;
			apagar(3);//msg
			gotoxy(44,6),printf("* * Cupom Fiscal * *");
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(30,i++),printf("Codigo da venda: ");
			scanf("%d", &cod);
		}
	}
	else
	{
		gotoxy(30,i++),printf("Vendas nao realizadas !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
}
void PaginaVendas(int &i){
	apagar(3);//msg
	gotoxy(3,23),printf("[ENTER] Proxima Pagina");
	getch();
	apagar(3);//msg
	apagar(2);//tela
	gotoxy(46,6),printf("* * Relatorio * *");
	i=8;
}
void RelatorioVendas(TpVendas v[tf], TpCliente c[tf], TpVendasP vp[tf], TpProduto p[tf],TpFornecedor f[tf],int TLF, int TLV, int TLC, int TLVP, int TLP){
	int i = 8, pos, cod, ext, it=1;
	float tot;
	char aux[30];
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  VENDAS >>  RELATORIO  ]>");
	apagar(3);//msg
	gotoxy(46,6),printf("* * Relatorio * *");
	
	if(TLV > 0)
	{
		while(it<TLV+1)
		{
			//pos = buscaCliente(c, TLC,v[ext].cpf);
			gotoxy(46,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("Codigo de Venda: %d",it);
			gotoxy(30,i++),printf("Produtos:");
			
			for(pos = buscaVendasP2(vp,TLVP,it), tot = 0.0; it == vp[pos].codV; pos++,i++)
			{
				gotoxy(30,i),printf("%d",vp[pos].codP);
				strcpy(aux,p[buscaProduto(p,TLP,vp[pos].codP)].descr);
				if(strlen(aux)>10)
					aux[11]='\0';
				gotoxy(36,i),printf("%s",aux);
				gotoxy(48,i),printf("%d",vp[pos].qtde);
				tot += vp[pos].qtde * vp[pos].preco;
				gotoxy(52,i),printf("R$%.2f",vp[pos].qtde*vp[pos].preco);
				strcpy(aux,f[buscaFornecedor(f,TLF,p[buscaProduto(p,TLP,vp[pos].codP)].forn)].nome);
				if(strlen(aux)>16)
					aux[17]='\0';
				gotoxy(62,i),printf("%s",aux);
				if(i>19)
					PaginaVendas(i);
			}
			
			gotoxy(30,i++),printf("TOTAL R$ %.2f",tot);
			gotoxy(30,i++),printf("-----------------------------------------------");
			if(i>18)
				PaginaVendas(i);
			it++;
		}
		if(i!=8){
			apagar(3);//msg
			gotoxy(3,23),printf("[ENTER] Sair...");
			getch();
		}
	}
	else
	{
		gotoxy(30,i++),printf("Vendas nao realizadas !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
}
int buscaProdForn(TpProduto x[tf],int tl,int cod){
	int pos = 0; 
	while(pos < tl && cod != x[pos].forn)
		pos++;
	return pos;
}
void AumentoFornecedor(TpFornecedor x[tf], TpProduto p[tf], int tl, int tlp){
	int i = 8, pos, cod;
	float aum;
	char op;
	
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  AUMENTAR PRECO  ]>");
	apagar(2);
	gotoxy(43,6),printf("* * Aumentar Preco * *");
	apagar(3);//msg
	if(tl > 0)
	{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Fornecedor: ");
		cod=LeInt(52,i,6);
		while(cod > 0)
		{
			pos = buscaFornecedor(x, tl, cod);
			if(pos < tl)
			{
				if(buscaProdForn(p,tlp,cod) < tlp){
					
					gotoxy(43,6),printf("* * Aumentar Preco * *");
					gotoxy(30,i++),printf("Porcentagem de Aumento: %% ");
					scanf("%f", &aum);
					if(aum > 0)
					{
						apagar(2);//tela
						gotoxy(43,6),printf("* * Aumentar Preco * *");
						i = 8;
						gotoxy(30,i++),printf("Codigo: %d",x[pos].cod);
						gotoxy(30,i++),printf("Nome: %s",x[pos].nome);
						gotoxy(30,i++),printf("Cidade: %s",x[pos].cidade);
						gotoxy(30,i++),printf("Porcentagem de Aumento: %% %.1f", aum);
						
						gotoxy(3,23),printf("Confirmar o aumento do preco? [S/N]");
						op=toupper(getch());
						
						if(op == 'S')
						{
							for(int j = 0; j < tlp; j++)
								if(p[j].forn == cod)
									p[j].preco += p[j].preco*aum/100.00;
							
							apagar(3);//msg
							gotoxy(3,23),printf("Aumento realizado com sucesso !");
						}
						else{
							apagar(3);//msg
							gotoxy(3,23),printf("Aumento cancelado !");
						}	
					}
					else
						gotoxy(3,23),printf("Porcentagem invalida !");
				}
				else
					gotoxy(3,23),printf("Fornecedor sem produtos cadastrados !");
			}
			else
				gotoxy(3,23),printf("Codigo nao cadastrado !");
			
			getch();
			apagar(2);//tela
			i=8;
			apagar(3);//msg
			gotoxy(43,6),printf("* * Aumentar Preco * *");
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(30,i),printf("Codigo do Fornecedor: ");
			cod=LeInt(52,i,6);
		}	
	}
	else{
		gotoxy(30,i++),printf("Nenhum Produto Cadastrado ! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
}
int contaCodigo(TpProduto x[tf],int tl,int cod){
	int i,cont;
	for(i=cont=0;i<tl;i++)
	{
		if(x[i].forn==cod)
			cont++;
	}
	return cont;
}
void ProdFornecedor(TpProduto p[tf],TpFornecedor f[tf],int tlp,int tlf){
	int i=8,pos,cod, tlc;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  PRODUTOS DO FORNECEDOR  ]>");
	apagar(2);
	gotoxy(39,6),printf("* * Produtos do Fornecedor * *");
	apagar(3);//msg
	if(tlp==0){
		gotoxy(30,i++),printf("Lista de Produtos Vazia! ");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else
	{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Fornecedor: ");
		cod=LeInt(52,i,6);
		apagar(3);
		while(cod > 0)
		{
			pos=buscaFornecedor(f,tlf,cod);
			if(pos<tlf){
				apagar(2);//tela
				gotoxy(39,6),printf("* * Produtos do Fornecedor * *");
				if(pos<tlp)
				{
					apagar(2);
					gotoxy(39,6),printf("* * Produtos do Fornecedor * *");
					//tlc=contaCodigo(p,tlp,cod);
					for(int j = 0; j < tlp;j++)
						if(cod == p[j].forn)
						{
							i--;
							gotoxy(39,6),printf("* * Produtos do Fornecedor * *");
							gotoxy(30,i++),printf("Codigo: %d",p[j].cod);
							gotoxy(30,i++),printf("descricao: %s",p[j].descr);
							gotoxy(30,i++),printf("Estoque: %d",p[j].est);
							gotoxy(30,i++),printf("Preco: R$%.2f",p[j].preco);
							gotoxy(30,i++),printf("Data: %d/%d/%d",p[j].data.d,p[j].data.m,p[j].data.a);
							gotoxy(3,23),printf("[Enter] Continuar...");
							getch();
							apagar(2);//tela
							i=9;
						}	
				}
				else
				{
					gotoxy(3,23),printf("Fornecedor sem produtos cadastrado !");
					getch();
				}
				
			}
			else{
				gotoxy(3,23),printf("Codigo nao cadastrado !");
				getch();
			}
			apagar(2);//tela
			i=8;
			apagar(3);//msg
			gotoxy(39,6),printf("* * Produtos do Fornecedor * *");
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(30,i),printf("Codigo do Fornecedor: ");
			cod=LeInt(52,i,6);
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
	printf("[ESC] Retornar");
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
	gotoxy(3,11);
	printf("[C] Cupom Fiscal");
	gotoxy(3,12);
	printf("[D] Relatorio");
	gotoxy(3,20);
	printf("[ESC] Retornar");
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
	gotoxy(3,13);
	printf("[E] Inserir Dados ");
	gotoxy(3,20);
	printf("[ESC] Sair");
	apagar(3);//msg
	gotoxy(3,23);
	printf("Escolha uma opcao: ");
}
char Formulario(void){
	apagar(1);
	apagar(2);
	apagar(3);//msg
	apagar(4);//titulo
	Moldura(1,1,80,25,10,0);
	gotoxy(3,3);
	textcolor(15);
	printf("<[  MENU  ]>");
	Moldura(2,2,79,4,10,0);
	Moldura(2,5,27,21,10,0);
	MenuPrincipal();
	Moldura(2,22,79,24,10,0);
	gotoxy(4,23);
	textcolor(15);
	Moldura(28,5,79,21,10,0);
	gotoxy(22,23);
	return toupper(getch());
}
void InserirCliente(TpCliente x[tf],int &tl,char cpf[15],char nome[30],int qtde,float total){
	strcpy(x[tl].cpf,cpf);
	strcpy(x[tl].nome,nome);
	x[tl].qtde=qtde;
	x[tl].total=total;
	tl++;
}
void InserirProduto(TpProduto x[tf],int &tl,int cod,char descr[20],int est,float preco,int d,int m,int a,int forn){
	x[tl].cod=cod;
	strcpy(x[tl].descr,descr);
	x[tl].est=est;
	x[tl].preco=preco;
	x[tl].data.d=d;
	x[tl].data.m=m;
	x[tl].data.a=a;
	x[tl].forn=forn;
	tl++;
}
void InserirFornecedor(TpFornecedor x[tf],int &tl,int cod,char nome[30],char cidade[30]){
	x[tl].cod=cod;
	strcpy(x[tl].nome,nome);
	strcpy(x[tl].cidade,cidade);
	tl++;
}
void InserirVendas(TpVendas x[tf],int &tl,int cod,char cpf[15],int d,int m,int a,float total){
	x[tl].cod=cod;
	strcpy(x[tl].cpf,cpf);
	x[tl].data.d=d;
	x[tl].data.m=m;
	x[tl].data.a=a;
	x[tl].total=total;
	tl++;
}
void InserirVendasP(TpVendasP x[tf],int &tl,int codV,int codP,int qtde,float preco){
	x[tl].codV=codV;
	x[tl].codP=codP;
	x[tl].preco=preco;
	x[tl].qtde=qtde;
	tl++;
}
void InsercaoDados(TpVendas v[tf], TpCliente c[tf], TpVendasP vp[tf], TpProduto p[tf],TpFornecedor f[tf],int &TLF, int &TLV, int &TLC, int &TLVP, int &TLP,int &dados){
	InserirCliente(c,TLC,"132.456.987-44","Windislaisson",1,64.60);
	InserirCliente(c,TLC,"651.325.984-77","Astolfo",1,457.48);
	InserirCliente(c,TLC,"159.357.654-52","Armelinda",1,392.64);
	InserirCliente(c,TLC,"544.544.999-00","Katarina",0,0);
	
	InserirProduto(p,TLP,7000,"Lasanha",52,9.98,10,9,2024,200);
	InserirProduto(p,TLP,1000,"Suco",188,1.62,15,05,2025,500);
	InserirProduto(p,TLP,4000,"Biscoito Delicia",63,4.56,22,11,2024,300);
	InserirProduto(p,TLP,3000,"Farofa",30,3.80,31,12,2023,300);
	
	InserirFornecedor(f,TLF,200,"Fabricia Matao danilo","Matao");
	InserirFornecedor(f,TLF,500,"Sapore S.A.","Campinas");
	InserirFornecedor(f,TLF,300,"Basteck","Guarapuava");
	
	InserirVendas(v,TLV,1,"651.325.984-77",10,8,2023,457.48);
	InserirVendas(v,TLV,2,"132.456.987-44",15,7,2023,45.60);
	InserirVendas(v,TLV,3,"159.357.654-52",06,4,2023,251.66);
	InserirVendas(v,TLV,4,"132.456.987-44",30,11,2023,19.00);
	
	InserirVendasP(vp,TLVP,1,1000,10,1.62);
	InserirVendasP(vp,TLVP,1,7000,20,9.98);
	InserirVendasP(vp,TLVP,1,4000,53,4.56);
	InserirVendasP(vp,TLVP,2,4000,10,4.56);
	InserirVendasP(vp,TLVP,3,7000,1,9.98);
	InserirVendasP(vp,TLVP,3,4000,53,4.56);
	InserirVendasP(vp,TLVP,4,3000,5,3.80);
	/*InserirVendasP(vp,TLVP,4,4000,1,4.56);
	InserirVendasP(vp,TLVP,4,4000,1,4.56);
	InserirVendasP(vp,TLVP,4,4000,1,4.56);
	InserirVendasP(vp,TLVP,4,4000,1,4.56);
	InserirVendasP(vp,TLVP,4,4000,1,4.56);
	InserirVendasP(vp,TLVP,4,4000,1,4.56);
	InserirVendasP(vp,TLVP,4,4000,1,4.56);*/
	apagar(3);//msg
	gotoxy(3,23),printf("Dados Inseridos !");
	dados=1;
	getch();
	apagar(3);//msg
}
void executar(){
	TpCliente cliente[tf];
	TpProduto produto[tf];
	TpFornecedor fornecedor[tf];
	TpVendas vendas[tf];
	TpVendasP vendasP[tf];
	int tl_cliente=0,tl_produto=0,tl_fornecedor=0,tl_vendas=0,tl_vendasP=0,dados=0;
	
	char tecla,op;
	do{
		tecla=Formulario();
		switch(tecla){
			case 'A':
				apagar(1);//menu
				gotoxy(7,7),printf("* * PRODUTOS * *");
				apagar(4);//titulo
				gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  ]>");
				gotoxy(3,14),printf("[F] Prod. do Fornecedor");
				op=submenu();
				switch(op){
					case 'A':
						CadastroProduto(produto,tl_produto,fornecedor,tl_fornecedor,dados);
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
					case 'F':
						ProdFornecedor(produto,fornecedor,tl_produto,tl_fornecedor);
						break;
				}
				break;
			case 'B':
				apagar(1);
				gotoxy(6,7),printf("* * FORNECEDOR * *");
				apagar(4);//titulo
				gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  ]>");
				gotoxy(3,14);
				printf("[F] Aumento Geral");
				op=submenu();
				switch(op){
					case 'A':
						CadastroFornecedor(fornecedor,tl_fornecedor,dados);
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
					case 'F':
						AumentoFornecedor(fornecedor, produto, tl_fornecedor, tl_produto);
				}
				break;
			case 'C':
				apagar(1);
				gotoxy(7,7),printf("* * CLIENTE * *");
				apagar(4);//titulo
				gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  ]>");
				op=submenu();
				switch(op){
					case 'A':
						CadastroCliente(cliente,tl_cliente,dados);
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
				}
				break;
			case 'D':
				apagar(1);
				gotoxy(8,7),printf("* * VENDAS * *");
				apagar(4);//titulo
				gotoxy(3,3),printf("<[  MENU  >>  VENDAS  ]>");
				op=VendasMenu();
				switch(op){
					case 'A':
						CadastroVendas(vendas,vendasP,cliente,tl_vendas,tl_vendasP,tl_cliente,produto,tl_produto,dados);
						break;
					case 'B':
						exclusaoVendas(vendas,vendasP,cliente,tl_vendas,tl_vendasP,tl_cliente,produto,tl_produto);
						break;
					case 'C': 
						CupomFiscal(vendas, cliente, vendasP, produto, tl_vendas,tl_cliente, tl_vendasP, tl_produto);
						break;
					case 'D':
						RelatorioVendas(vendas, cliente, vendasP, produto,fornecedor,tl_fornecedor, tl_vendas,tl_cliente, tl_vendasP, tl_produto);
				}
				break;
			case 'E':
				if(dados==0)
					InsercaoDados(vendas, cliente, vendasP, produto,fornecedor,tl_fornecedor, tl_vendas,tl_cliente, tl_vendasP, tl_produto,dados);
				else{
					apagar(3);//msg
					gotoxy(3,23),printf("Os Dados Ja Foram Inseridos !");
					getch();
					apagar(3);//msg
				}
		}
	}while(tecla!=27);
}
int main(){
	system("mode 80,25");
	executar();
	return 0;
}
