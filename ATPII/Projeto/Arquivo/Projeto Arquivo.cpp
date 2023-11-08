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
int buscaProduto(FILE *x,int cod){
	TpProduto p;
	rewind(x);
	fread(&p,sizeof(TpProduto),1,x);
	while(!feof(x) && p.cod!=cod)
		fread(&p,sizeof(TpProduto),1,x);
	if(!feof(x))
		return ftell(x)-sizeof(TpProduto);
	else
		return -1;
}
int buscaFornecedor(FILE *x,int cod){
	TpFornecedor f;
	rewind(x);
	fread(&f,sizeof(TpFornecedor),1,x);
	while(!feof(x) && f.cod!=cod)
		fread(&f,sizeof(TpFornecedor),1,x);
	if(!feof(x))
		return ftell(x)-sizeof(TpFornecedor);
	else
		return -1;
}
int buscaCliente(FILE *x,char cpf[15]){
	TpCliente c;
	rewind(x);
	fread(&c,sizeof(TpCliente),1,x);
	while(!feof(x) && strcmp(cpf,c.cpf)!=0)
		fread(&c,sizeof(TpCliente),1,x);
	if(!feof(x))
		return ftell(x)-sizeof(TpCliente);
	else
		return -1;
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
int buscaVendasP2(FILE *arq,int cod){
	TpVendasP x;
	rewind(arq);
	fread(&x,sizeof(TpVendasP),1,arq);
	while(!feof(arq) && x.codV!=cod)
		fread(&x,sizeof(TpVendasP),1,arq);
	if(!feof(arq))
		return ftell(arq)-sizeof(TpVendasP);
	else
		return -1;
}
int buscaCodVenda(FILE *arq,int cod,int num){
	int pos=0;
	TpVendasP vp;
	rewind(arq);
	fread(&vp,sizeof(TpVendasP),1,arq);
	while(!feof(arq) && (vp.codV!=num || vp.codP!=cod))
			fread(&vp,sizeof(TpVendasP),1,arq);
	if(!feof(arq))
		return ftell(arq)-sizeof(TpVendasP);
	else
		return -1;
}
int buscaVendas(FILE *arq,int cod){
	TpVendas x;
	rewind(arq);
	fread(&x,sizeof(TpVendas),1,arq);
	while(!feof(arq) && x.cod!=cod)
		fread(&x,sizeof(TpVendas),1,arq);
	if(!feof(arq))
		return ftell(arq)-sizeof(TpVendas);
	else
		return -1;
}
void CadastroFornecedor(int &dados){
	FILE *arq=fopen("Fornecedor.dat","ab+");
	TpFornecedor f;
	char op;
	int pos,i=8;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  CADASTRO  ]>");
	gotoxy(46,6),printf("* * Cadastro * *");
	apagar(3);//msg
	
	gotoxy(3,23),printf("Digite [0] para sair");
	gotoxy(30,i),printf("Codigo do Fornecedor: ");
	f.cod=LeInt(52,i,6);
	apagar(3);//msg
	while(f.cod>0){
		pos=buscaFornecedor(arq,f.cod);
		if(pos!=-1){
			apagar(2);//tela
			i--;
			fseek(arq,pos,0);
			fread(&f,sizeof(TpFornecedor),1,arq);
			gotoxy(46,6),printf("* * Cadastro * *");
			gotoxy(30,i++),printf("Codigo: %d",f.cod);
			gotoxy(30,i++),printf("Nome: %s",f.nome);
			gotoxy(30,i++),printf("Cidade: %s",f.cidade);
			gotoxy(3,23),printf("Codigo ja Existente!");
			getch();
		}
		else{
			gotoxy(30,i),printf("Nome do Fornecedor: ");
			limiteString(50,i,30,f.nome),i++;
			gotoxy(30,i),printf("Cidade: ");
			limiteString(38,i,34,f.cidade),i++;
			gotoxy(3,23),printf("Confirmar o cadastro [S/N]? ");
			
			op=toupper(getch());
			if(op == 'S'){
				dados=1;
				fwrite(&f,sizeof(TpFornecedor),1,arq);
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
		
		apagar(3);//msg
		gotoxy(46,6),printf("* * Cadastro * *");
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Fornecedor: ");
		f.cod=LeInt(52,i,6);
		apagar(3);//msg
		
	}
	fclose(arq);
}
void ConsultaFornecedor(){
	FILE *arq=fopen("Fornecedor.dat","rb");
	TpFornecedor x;
	int i=8,pos;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  CONSULTA  ]>");
	apagar(2);
	gotoxy(46,6),printf("* * Consulta * *");
	apagar(3);//msg
	fseek(arq,0,2);
	if(ftell(arq)==0){
		gotoxy(30,i++),printf("Nenhum Fornecedor Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Fornecedor: ");
		x.cod=LeInt(52,i,6);
		apagar(3);//msg
		while(x.cod > 0){
			pos=buscaFornecedor(arq,x.cod);
			if(pos!=-1){
				apagar(2);//tela
				gotoxy(46,6),printf("* * Consulta * *");
				i--;
				fseek(arq,pos,0);
				fread(&x,sizeof(TpFornecedor),1,arq);
				gotoxy(30,i++),printf("Codigo: %d",x.cod);
				gotoxy(30,i++),printf("Nome: %s",x.nome);
				gotoxy(30,i++),printf("Cidade: %s",x.cidade);
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
			x.cod=LeInt(52,i,6);
			apagar(3);//msg
		}
	}
	fclose(arq);
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
			//pos=buscaFornecedor(x,tl,cod);
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
void alterarFornecedor(){
	FILE *arq=fopen("Fornecedor.dat","rb+");
	TpFornecedor x;
	char op;
	int pos,i=8;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  ALTERACAO  ]>");
	apagar(2);//tela
	gotoxy(46,6),printf("* * Alteracao * *");
	fseek(arq,0,2);
	if(ftell(arq)==0){
		gotoxy(30,i++),printf("Nenhum Fornecedor Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Fornecedor: ");
		x.cod=LeInt(52,i,6);
		apagar(3);//msg
		while(x.cod>0){ 
			apagar(3);//msg
			pos=buscaFornecedor(arq,x.cod);
			if(pos==-1){
				apagar(2);//tela
				gotoxy(46,6),printf("* * Alteracao * *");
				gotoxy(30,i++),printf("Codigo nao cadastrado !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				apagar(3);//msg
				fseek(arq,pos,0);
				fread(&x,sizeof(TpFornecedor),1,arq);
				gotoxy(30,i++),printf("Nome do Fornecedor: %s",x.nome);
				gotoxy(30,i),printf("Novo nome: ");
				limiteString(41,i,30,x.nome),i++;
				gotoxy(30,i++),printf("Cidade: %s",x.cidade);
				gotoxy(30,i),printf("Nova Cidade: ");
				limiteString(43,i,34,x.cidade),i++;
				gotoxy(3,23),printf("Confirmar a alteracao [S/N]? ");
				op=toupper(getch());
				apagar(3);//msg
				if(op == 'S'){
					fseek(arq,pos,0);
					fwrite(&x,sizeof(TpFornecedor),1,arq);
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
			x.cod=LeInt(52,i,6);
			apagar(3);//msg
		}
	}
	fclose(arq);
}
void RelatorioFornecedor(){
	FILE *arq=fopen("Fornecedor.dat","rb");
	TpFornecedor x;
	int pos=1,i=8,pon,prox;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(3);//msg
	gotoxy(3,3),printf("<[  MENU  >>  FORNECEDOR  >>  RELATORIO  ]>");
	gotoxy(46,6),printf("* * Relatorio * *");
	fseek(arq,0,2);
	if(ftell(arq)==0){
		gotoxy(30,i++),printf("Nenhum Fornecedor Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		rewind(arq);
		fread(&x,sizeof(TpFornecedor),1,arq);
		do{
			gotoxy(46,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("Codigo: %d",x.cod);
			gotoxy(30,i++),printf("Nome: %s",x.nome);
			gotoxy(30,i++),printf("Cidade: %s",x.cidade);
			gotoxy(70,20),printf("Pagina %d",pos);
			pon=ftell(arq);
			prox=fgetc(arq);
			fseek(arq,pon,0);
			if(ftell(arq)==sizeof(TpFornecedor)){
				gotoxy(76,13),printf("[%c]",25);
			}	
			else if(prox!=EOF){
				gotoxy(76,12),printf("[%c]",24);
				gotoxy(76,13),printf("[%c]",25);
			}
			else{
				gotoxy(76,12),printf("[%c]",24);
			}
			gotoxy(3,23),printf("[ESC] para sair");
			op=getch();
			if(op==-32){
				op=getch();
				if(op==72 && ftell(arq)!=sizeof(TpFornecedor)){
					fseek(arq,-2*sizeof(TpFornecedor),1);
					fread(&x,sizeof(TpFornecedor),1,arq);
					pos--;
				}
				else if(op==80 && prox!=EOF){
					fread(&x,sizeof(TpFornecedor),1,arq);
					pos++;
				}
			}		
			i=8;
			apagar(2);//tela
		}while(op!=27);
	}
	fclose(arq);
}
void CadastroProduto(int &dados){
	FILE *arqProd=fopen("Produto.dat","ab+");
	FILE *arqForn=fopen("Fornecedor.dat","rb");
	TpProduto p;
	char op;
	int pos,i=8,val;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  CADASTRO  ]>");
	gotoxy(46,6),printf("* * Cadastro * *");
	apagar(3);//msg
	fseek(arqForn,0,2);
	if(ftell(arqForn)==0){
		gotoxy(30,i++),printf("Nenhum Fornecedor Cadastrado !");
		apagar(3);//msg
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Produto: ");
		p.cod=LeInt(49,i,5);
		apagar(3);//msg
		while(p.cod>0){
			pos=buscaProduto(arqProd,p.cod);
			if(pos!=-1){
				apagar(2);//tela
				fseek(arqProd,pos,0);
				fread(&p,sizeof(TpProduto),1,arqProd);
				gotoxy(46,6),printf("* * Cadastro * *");i--;
				gotoxy(30,i++),printf("Codigo: %d",p.cod);
				gotoxy(30,i++),printf("Descricao: %s",p.descr);
				gotoxy(30,i++),printf("Estoque: %d",p.est);
				gotoxy(30,i++),printf("Preco: R$%.2f",p.preco);
				gotoxy(30,i++),printf("Data de validade: %d/%d/%d",p.data.d,p.data.m,p.data.a);
				gotoxy(30,i++),printf("Cod. Fornecedor: %d",p.forn);
				apagar(3);//msg
				gotoxy(3,23),printf("Codigo ja Existente!");
				getch();
			}
			else{
				gotoxy(30,i),printf("Codigo do Fornecedor: ");
				p.forn=LeInt(52,i,6);
				pos=buscaFornecedor(arqForn,p.forn);
				while(pos==-1 && p.forn!=0){
						i--;
						gotoxy(3,23),printf("Fornecedor Inexistente! ");
						gotoxy(30,i),printf("Codigo do Fornecedor: ");
						gotoxy(52,i),printf("          ");
						p.forn=LeInt(52,i,6);
						if(p.forn!=0)
							pos=buscaFornecedor(arqForn,p.forn);
				}
				apagar(3);//msg
				if(p.forn!=0){
					gotoxy(30,i),printf("Descricao: ");
					limiteString(41,i,24,p.descr),i++;
					
					//gotoxy(30,i++),printf("Estoque: ");
					do{
						gotoxy(30,i),printf("Estoque: ");
						gotoxy(39,i),printf("     ");
						p.est=LeInt(39,i,5);
						if(p.est < 0){
							gotoxy(3,23),printf("Quantidade invalida !");
							i--;
						}
					}while(p.est < 0);
					apagar(3);//msg
					
					do{
						gotoxy(30,i),printf("Preco: ");
						gotoxy(38,i),printf("            ");
						p.preco=LeFloat(38,i,8);
						if(p.preco <= 0){
							gotoxy(3,23),printf("Preco Invalido !");
							i--;
						}
					}while(p.preco <= 0);
					apagar(3);//msg
					gotoxy(30,i++),printf("Data de validade [dd mm aaaa]: ");
					scanf("%d%d%d",&p.data.d,&p.data.m,&p.data.a);
					val=ValidaData(p.data);
					while(val==-1){
						apagar(3);//msg
						gotoxy(3,23),printf("Data Invalida !");
						gotoxy(30,i-1),printf("                                        ");
						gotoxy(30,i-1),printf("Data de validade [dd mm aa]: ");
						scanf("%d%d%d",&p.data.d,&p.data.m,&p.data.a);
						val=ValidaData(p.data);
					}
					gotoxy(3,23),printf("Confirmar o cadastro [S/N]? ");
					op=toupper(getch());
					if(op == 'S'){
						dados=1;
						fwrite(&p,sizeof(TpProduto),1,arqProd);
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
			apagar(3);//msg
			gotoxy(3,23),printf("Digite [0] para sair");
			gotoxy(46,6),printf("* * Cadastro * *");
			gotoxy(30,i),printf("Codigo do Produto: ");
			p.cod=LeInt(49,i,53);
			apagar(3);//msg
			
		}
	}
	fclose(arqProd);
	fclose(arqForn);
}
void ConsultaProduto(){
	FILE *arq=fopen("Produto.dat","rb");
	TpProduto x;
	int i=8,pos;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  CONSULTA  ]>");
	apagar(2);
	gotoxy(46,6),printf("* * Consulta * *");
	apagar(3);//msg
	fseek(arq,0,2);
	if(ftell(arq)==0){
		gotoxy(30,i++),printf("Nenhum Produto Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Produto: ");
		x.cod=LeInt(49,i,53);
		apagar(3);//msg
		while(x.cod>0){
			pos=buscaProduto(arq,x.cod);
			if(pos!=-1){
				apagar(2);//tela
				i--;
				fseek(arq,pos,0);
				fread(&x,sizeof(TpProduto),1,arq);
				gotoxy(46,6),printf("* * Consulta * *");
				gotoxy(30,i++),printf("Codigo: %d",x.cod);
				gotoxy(30,i++),printf("Descricao: %s",x.descr);
				gotoxy(30,i++),printf("Estoque: %d",x.est);
				gotoxy(30,i++),printf("Preco: R$%.2f",x.preco);
				gotoxy(30,i++),printf("Data: %d/%d/%d",x.data.d,x.data.m,x.data.a);
				gotoxy(30,i++),printf("Cod. Fornecedor: %d",x.forn);
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
			x.cod=LeInt(49,i,53);
			apagar(3);//msg
		}
	}
	fclose(arq);
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
			//pos=buscaProduto(x,tl,cod);
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
void alterarProduto(){
	FILE *arqP=fopen("Produto.dat","rb+");
	FILE *arqF=fopen("Fornecedor.dat","rb");
	TpProduto x;
	TpData data;
	char op;
	int pos,pos1,i=8,val;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(2);//tela
	gotoxy(46,6),printf("* * Alteracao * *");
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  ALTERACAO  ]>");
	fseek(arqP,0,2);
	if(ftell(arqP)==0){
		gotoxy(30,i++),printf("Nenhum Produto Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{	
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i),printf("Codigo do Produto: ");
		x.cod=LeInt(49,i,5);
		while(x.cod>0){
			apagar(3);//msg
			pos=buscaProduto(arqP,x.cod);
			if(pos==-1){
				apagar(2);//tela
				gotoxy(46,6),printf("* * Alteracao * *");
				i--;
				gotoxy(30,i++),printf("Codigo nao cadastrado !");
				gotoxy(3,23),printf("[ENTER] Continuar...");
				getch();
			}
			else{
				fseek(arqP,pos,0);
				fread(&x,sizeof(TpProduto),1,arqP);
				gotoxy(30,i),printf("Fornecedor: %d",x.forn);
				gotoxy(49,i),printf("->");
				x.forn=LeInt(52,i,6);
				pos1=buscaFornecedor(arqF,x.forn);
				while(pos1==-1){
					gotoxy(3,23),printf("Fornecedor Inexistente! ");
					i--;
					fseek(arqP,pos,0);
					fread(&x,sizeof(TpProduto),1,arqP);
					gotoxy(30,i),printf("                                                 ");
					gotoxy(30,i),printf("Fornecedor: %d",x.forn);
					gotoxy(49,i),printf("->");
					x.forn=LeInt(52,i,6);
					pos1=buscaFornecedor(arqF,x.forn);
				}
				apagar(3);//msg
				gotoxy(30,i++),printf("Descricao: %s",x.descr);
				gotoxy(30,i),printf("Nova descricao: ");
				limiteString(46,i,24,x.descr),i++;
				//gotoxy(30,i++),printf("Estoque: %d -> ",x[pos].est);
				gotoxy(30,i),printf("Estoque: %d",x.est);
				gotoxy(44,i),printf("->");
				x.est=LeInt(47,i,5);
				//gotoxy(30,i++),printf("Preco: R$%.2f -> ",x[pos].preco);
				gotoxy(30,i),printf("Preco: R$%.2f",x.preco);
				gotoxy(47,i),printf("->");
				x.preco=LeFloat(50,i,8);
				gotoxy(30,i++),printf("Data de validade: %d/%d/%d -> ",x.data.d,x.data.m,x.data.a);
				scanf("%d%d%d",&data.d,&data.m,&data.a);
				val=ValidaData(x.data);
				while(val==-1){
					gotoxy(30,i-1),printf("                                           ");
					gotoxy(30,i-1),printf("Data de validade: %d/%d/%d -> ",x.data.d,x.data.m,x.data.a);
					scanf("%d%d%d",&data.d,&data.m,&data.a);
					val=ValidaData(data);
				}
				gotoxy(3,23),printf("Confirmar a alteracao [S/N]? ");
				op=toupper(getch());
				apagar(3);//msg
				if(op == 'S'){
					x.data.d=data.d;
					x.data.m=data.m;
					x.data.a=data.a;
					fseek(arqP,pos,0);
					fwrite(&x,sizeof(TpProduto),1,arqP);
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
			x.cod=LeInt(49,i,5);
			apagar(3);//msg
		}
	}
	fclose(arqP);
	fclose(arqF);
}
void RelatorioProduto(){
	FILE *arq=fopen("Produto.dat","rb");
	TpProduto x;
	int pos=1,i=8,pon,prox;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(3);//msg
	gotoxy(3,3),printf("<[  MENU  >>  PRODUTOS  >>  RELATORIO  ]>");
	gotoxy(46,6),printf("* * Relatorio * *");
	fseek(arq,0,2);
	if(ftell(arq)==0){
		gotoxy(30,i++),printf("Nenhum Produto Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		rewind(arq);
		fread(&x,sizeof(x),1,arq);
		do{
			gotoxy(46,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("Codigo: %d",x.cod);
			gotoxy(30,i++),printf("Descricao: %s",x.descr);
			gotoxy(30,i++),printf("Estoque: %d",x.est);
			gotoxy(30,i++),printf("Preco: R$%.2f",x.preco);
			gotoxy(30,i++),printf("Data de validade: %d/%d/%d",x.data.d,x.data.m,x.data.a);
			gotoxy(30,i++),printf("Cod. Fornecedor: %d",x.forn);
			gotoxy(70,20),printf("Pagina %d",pos);
			pon=ftell(arq);
			prox=fgetc(arq);
			fseek(arq,pon,0);
			if(ftell(arq)==sizeof(TpProduto)){
				gotoxy(76,13),printf("[%c]",25);
			}	
			else if(prox!=EOF){
				gotoxy(76,12),printf("[%c]",24);
				gotoxy(76,13),printf("[%c]",25);
			}
			else{
				gotoxy(76,12),printf("[%c]",24);
			}
			gotoxy(3,23),printf("[ESC] para sair");
			op=getch();
			if(op==-32){
				op=getch();
				if(op==72 && ftell(arq)!=sizeof(TpProduto)){
					fseek(arq,-2*sizeof(TpProduto),1);
					fread(&x,sizeof(TpProduto),1,arq);
					pos--;
				}
				else if(op==80 && prox!=EOF){
					fread(&x,sizeof(TpProduto),1,arq);
					pos++;
				}		
			}		
			i=8;
			apagar(2);//tela
		}while(op!=27);
	}
	fclose(arq);
}
void CadastroCliente(int &dados){
	FILE *arq=fopen("Cliente.dat","ab+");
	TpCliente c;
	char cpf[15],op;
	int pos,i=8;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(3);//msg
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  CADASTRO  ]>");
	apagar(2);
	gotoxy(46,6),printf("* * Cadastro * *");
	
	gotoxy(3,23),printf("Aperte [ENTER] para sair");
	gotoxy(30,i++),printf("CPF do cliente: ");
	fflush(stdin);
	gets(c.cpf);
	while(ValidaCPF(c.cpf)==-1){
		apagar(3);//msg
		gotoxy(3,23),printf("CPF Invalido !");
		getch();
		apagar(3);//msg
		gotoxy(3,23),printf("Digite [ENTER] para sair");
		gotoxy(30,i-1),printf("                                        ");
		gotoxy(30,i-1),printf("CPF do cliente: ");
		gets(c.cpf);
	}
	apagar(3);//msg
	while(strlen(c.cpf)>0){
		pos=buscaCliente(arq,c.cpf);
		if(pos!=-1){
			fseek(arq,pos,0);
			fread(&c,sizeof(TpCliente),1,arq);
			gotoxy(30,i++),printf("Nome: %s",c.nome);
			gotoxy(30,i++),printf("Quantidade: %d",c.qtde);
			gotoxy(30,i++),printf("Total: %.2f",c.total);
			gotoxy(3,23),printf("Codigo ja Existente!");
			getch();
		}
		else{
			gotoxy(30,i),printf("Nome do Cliente: ");
			limiteString(47,i,25,c.nome),i++;
			gotoxy(3,23),printf("Confirmar o cadastro [S/N]? ");
			op=toupper(getch());
			if(op == 'S'){
				dados=1;
				c.qtde=0;
				c.total=0;
				fseek(arq,0,2);
				fwrite(&c,sizeof(TpCliente),1,arq);
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
		
		apagar(3);//msg
		gotoxy(46,6),printf("* * Cadastro * *");
		gotoxy(3,23),printf("Digite [ENTER] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		gets(c.cpf);
		while(ValidaCPF(c.cpf)==-1){
			apagar(3);//msg
			gotoxy(3,23),printf("CPF Invalido !");
			getch();
			apagar(3);//msg
			gotoxy(3,23),printf("Aperte [ENTER] para sair");
			gotoxy(30,i-1),printf("                                        ");
			gotoxy(30,i-1),printf("CPF do cliente: ");
			gets(c.cpf);
		}
		apagar(3);//msg
	}
	fclose(arq);
}
void ConsultaCliente(){
	FILE *arq=fopen("Cliente.dat","rb");
	TpCliente x;
	int i=8,pos;
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  CONSULTA  ]>");
	apagar(2);
	gotoxy(46,6),printf("* * Consulta * *");
	apagar(3);//msg
	fseek(arq,0,2);
	if(ftell(arq)==0){
		gotoxy(30,i++),printf("Nenhum Cliente Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		gotoxy(3,23),printf("Aperte [ENTER] para sair");
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(x.cpf);
		apagar(3);//msg
		while(strlen(x.cpf)>0){
			pos=buscaCliente(arq,x.cpf);
			if(pos!=-1){
				apagar(2);//tela
				fseek(arq,pos,0);
				fread(&x,sizeof(TpCliente),1,arq);
				i--;
				gotoxy(45,6),printf("* * Consulta * *");
				gotoxy(30,i++),printf("CPF: %s",x.cpf);
				gotoxy(30,i++),printf("Nome: %s",x.nome);
				gotoxy(30,i++),printf("Quantidade: %d",x.qtde);
				gotoxy(30,i++),printf("Total: %.2f",x.total);
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
			gets(x.cpf);
			apagar(3);//msg
		}
	}
	fclose(arq);
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
			//pos=buscaCliente(x,tl,cpf);
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
void alterarCliente(){
	FILE *arq=fopen("Cliente.dat","rb+");
	TpCliente x;
	char op;
	int pos,i=8;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(2);
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  ALTERACAO  ]>");
	gotoxy(46,6),printf("* * Alteracao * *");
	if(arq==NULL){
		gotoxy(30,i++),printf("Erro na abertura do arquivo !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		fseek(arq,0,2);
		if(ftell(arq)==0){
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
			gets(x.cpf);
			while(strlen(x.cpf)>0){
				apagar(3);//msg
				pos=buscaCliente(arq,x.cpf);
				if(pos==-1){
					apagar(2);//tela
					gotoxy(46,6),printf("* * Alteracao * *");
					gotoxy(30,i++),printf("CPF nao cadastrado !");
					gotoxy(3,23),printf("[ENTER] Continuar...");
					getch();
				}
				else{
					fseek(arq,pos,0);
					fread(&x,sizeof(TpCliente),1,arq);
					apagar(3);//msg
					gotoxy(30,i++),printf("Nome: %s",x.nome);
					gotoxy(30,i),printf("Novo nome: ");
					limiteString(41,i,25,x.nome),i++;
					gotoxy(3,23),printf("Confirmar a alteracao [S/N]? ");
					op=toupper(getch());
					apagar(3);//msg
					if(op == 'S'){
						fseek(arq,-sizeof(TpCliente),1);
						fwrite(&x,sizeof(TpCliente),1,arq);
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
				gets(x.cpf);
				apagar(3);//msg
			}
		}
		fclose(arq);
	}
}
void RelatorioCliente(){
	FILE *arq=fopen("Cliente.dat","rb");
	TpCliente x;
	int pos=1,i=8,pon,prox;
	char op;
	apagar(1);//MENU
	apagar(4);//titulo
	apagar(2);
	apagar(3);//msg
	gotoxy(3,3),printf("<[  MENU  >>  CLIENTE  >>  RELATORIO  ]>");
	gotoxy(46,6),printf("* * Relatorio * *");
	fseek(arq,0,2);
	if(ftell(arq)==0){
		gotoxy(30,i++),printf("Nenhum Cliente Cadastrado !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	else{
		rewind(arq);
		fread(&x,sizeof(TpCliente),1,arq);
		do{
			gotoxy(46,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("CPF: %s",x.cpf);
			gotoxy(30,i++),printf("Nome: %s",x.nome);
			gotoxy(30,i++),printf("Quantidade de venda: %d",x.qtde);
			gotoxy(30,i++),printf("Total de compra: R$%.2f",x.total);
			gotoxy(70,20),printf("Pagina %d",pos);
			pon=ftell(arq);
			prox=fgetc(arq);
			fseek(arq,pon,0);
			if(ftell(arq)==sizeof(TpCliente)){
				gotoxy(76,13),printf("[%c]",25);
			}	
			else if(prox!=EOF){
				gotoxy(76,12),printf("[%c]",24);
				gotoxy(76,13),printf("[%c]",25);
			}
			else{
				gotoxy(76,12),printf("[%c]",24);
			}
			gotoxy(3,23),printf("[ESC] para sair");
			op=getch();
			if(op==-32){
				op=getch();
				if(op==72 && ftell(arq)!=sizeof(TpCliente)){
					fseek(arq,-2*sizeof(TpCliente),1);
					fread(&x,sizeof(TpCliente),1,arq);
					pos--;
				}
				else if(op==80 && prox!=EOF){
					fread(&x,sizeof(TpCliente),1,arq);
					pos++;
				}
			}		
			i=8;
			apagar(2);//tela
		}while(op!=27);
	}
	fclose(arq);
}
void PrintCupom(FILE *arqP,FILE *arqC,FILE *arqV,FILE *arqVP,int cod,int ext);
void CadastroVendas(int &dados){
	FILE *arqP=fopen("Produto.dat","rb+");
	FILE *arqC=fopen("Cliente.dat","rb+");
	FILE *arqV=fopen("Vendas.dat","ab+");
	FILE *arqVP=fopen("VendasP.dat","ab+");
	TpProduto p;
	TpCliente c;
	TpVendas v;
	TpVendasP vp;
	char op;
	int pos,pos2,i=8,pos1,venda,ext;
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
	gotoxy(3,23),printf("Aperte [ENTER] para sair");
	fseek(arqC,0,2);
	fseek(arqP,0,2);
	if(ftell(arqC)==0){
		gotoxy(30,i++),printf("Nenhum Cliente Cadastrado !");
	}
	if(ftell(arqP)==0){
		gotoxy(30,i++),printf("Nenhum Produto Cadastrado !");
	}
	if(ftell(arqP)!=0 && ftell(arqC)!=0){
		gotoxy(30,i++),printf("CPF do cliente: ");
		fflush(stdin);
		gets(v.cpf);
		apagar(3);//msg
		
		total=0;
		while(strlen(v.cpf)>0){
			pos=buscaCliente(arqC,v.cpf);
			if(pos==-1){
				gotoxy(3,23),printf("CPF nao cadastrado !");
				getch();
			}
			else{
				fseek(arqV,0,2);
				if(ftell(arqV)==0){
					v.cod=1;
				}	
				else{
					fseek(arqV,-sizeof(TpVendas),2);
					fread(&v,sizeof(TpVendas),1,arqV);
					v.cod+=1;
					
				}		
				vp.codV=v.cod;
				gotoxy(30,i),printf("Codigo do Produto: ");
				vp.codP=LeInt(49,i,5);
				apagar(3);//msg
				while(vp.codP>0){
					venda=0;
					pos1=buscaProduto(arqP,vp.codP);
					if(pos1!=-1){
						pos2=buscaCodVenda(arqVP,vp.codP,vp.codV);
						if(pos2!=-1){
							gotoxy(3,23),printf("Produto ja cadastrado nesta venda !");
							getch();
							apagar(3);//msg
						}
						else{
							fseek(arqP,pos1,0);
							fread(&p,sizeof(TpProduto),1,arqP);
							gotoxy(30,i++),printf("Descr.: %s",p.descr);
							gotoxy(30,i++),printf("Preco: R$%.2f",p.preco);
							gotoxy(30,i++),printf("Estoque: %d",p.est);
							gotoxy(30,i),printf("Quantidade da venda: ");
							vp.qtde=LeInt(51,i,5);
							while(vp.qtde<=0 || vp.qtde>p.est){
								gotoxy(3,23),printf("Quantidade Invalida! ");
								i--;
								gotoxy(30,i),printf("                                            ");
								gotoxy(30,i),printf("Quantidade da venda: ");
								vp.qtde=LeInt(51,i,5);
							}
							apagar(3);//msg
							gotoxy(3,23),printf("Confirmar venda do Produto [S/N]? ");
							op=toupper(getch());
							if(op == 'S'){
								dados=1;
								//vp[tlvP].codV=num;
//								vp[tlvP].codP=cod;
//								vp[tlvP].qtde=qtde;
								vp.preco=p.preco;
								fwrite(&vp,sizeof(vp),1,arqVP);
								
								fseek(arqP,pos1,0);
								fread(&p,sizeof(TpProduto),1,arqP);
								p.est-=vp.qtde;
								fseek(arqP,pos1,0);
								fwrite(&p,sizeof(TpProduto),1,arqP);
								
								total+=vp.preco*vp.qtde;
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
					
					apagar(3);//msg
					gotoxy(3,23),printf("Digite [0] para sair");
					gotoxy(46,6),printf("* * Vendas * *");
					gotoxy(30,i++),printf("CPF do cliente: %s",v.cpf);
					gotoxy(30,i),printf("                                          ");
					gotoxy(30,i),printf("Codigo do Produto: ");
					vp.codP=LeInt(49,i,5);
					apagar(3);//msg
				
				}
				
				if(venda==1){
					//strcpy(v[tlv].cpf,cpf);
					v.total=total;
					v.data.d=tempo.tm_mday;
					v.data.m=tempo.tm_mon+1;
					v.data.a=tempo.tm_year+1900;
					fseek(arqV,0,2);
					fwrite(&v,sizeof(TpVendas),1,arqV);
					
					fseek(arqC,pos,0);
					fread(&c,sizeof(TpCliente),1,arqC);
					c.total+=total;
					c.qtde++;
					fseek(arqC,pos,0);
					fwrite(&c,sizeof(TpCliente),1,arqC);
					ext = buscaVendas(arqV,v.cod);
					PrintCupom(arqP,arqC,arqV,arqVP,v.cod,ext);
				}	
			}
			apagar(2);
			i=8;
			
			apagar(3);//msg
			gotoxy(3,23),printf("Aperte [ENTER] para sair");
			gotoxy(46,6),printf("* * Vendas * *");
			gotoxy(30,i++),printf("CPF do cliente: ");
			fflush(stdin);
			gets(v.cpf);
			apagar(3);//msg
		}
	}
	else
		getch();
	fclose(arqP);
	fclose(arqC);
	fclose(arqV);
	fclose(arqVP);
	
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
			//pos=buscaVendas(v,tlv,cod);
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
					//pos1=buscaCliente(c,tlc,v[pos].cpf);
					c[pos1].qtde--;
					c[pos1].total-=v[pos].total;
					for(;pos<tlv-1;pos++){
						v[pos]=v[pos+1];
						v[pos].cod--;
					}
					tlv--;
					//pos=buscaVendasP2(vp,tlvP,cod);
					while(pos<tlvP){
						//pos1=buscaProduto(x,tlp,vp[pos].codV);
						x[pos1].est+=vp[pos].qtde;
						for(i=pos;i<tlvP-1;i++){
							vp[i]=vp[i+1];
						}
						tlvP--;
						//pos=buscaVendasP2(vp,tlvP,cod);
					}
					//pos=buscaVendasP2(vp,tlvP,cod+1);
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
void PrintCupom(FILE *arqP,FILE *arqC,FILE *arqV,FILE *arqVP,int cod,int ext){
	int i = 8, pos, pos1, it;
	TpVendas v;
	TpVendasP vp;
	TpCliente c;
	TpProduto p;
	float tot;
	
	fseek(arqV,ext,0);
	fread(&v,sizeof(TpVendas),1,arqV);
	pos = buscaCliente(arqC,v.cpf);
	
	fseek(arqC,pos,0);
	fread(&c,sizeof(TpCliente),1,arqC);
	
	pos1=buscaVendas(arqV,cod);
	fseek(arqV,pos1,0);
	fread(&v,sizeof(TpVendas),1,arqV);
	
	apagar(2);//tela
	gotoxy(44,6),printf("* * Cupom Fiscal * *");
	gotoxy(30,i),printf("Nome: %s",c.nome);
	gotoxy(61,i++),printf("Data: %d/%d/%d",v.data.d,v.data.m,v.data.a);
	gotoxy(30,i++),printf("CPF: %s",c.cpf),i++;
	gotoxy(30,i++),printf("CUPOM FISCAL");
	gotoxy(30,i++),printf("-----------------------------------------------");
	gotoxy(30,i++),printf("ITEM  QTDE  PRODUTO                 VALOR");
	pos=buscaVendasP2(arqVP,cod);
	fseek(arqVP,pos,0);
	fread(&vp,sizeof(TpVendasP),1,arqVP);
	for(it = 1, tot = 0.0; cod == vp.codV && !feof(arqVP); it++,i++)
	{
		gotoxy(30,i),printf("%d",it);
		gotoxy(36,i),printf("%d",vp.qtde);
		pos=buscaProduto(arqP,vp.codP);
		fseek(arqP,pos,0);
		fread(&p,sizeof(TpProduto),1,arqP);
		gotoxy(42,i),printf("%s",p.descr);
		tot += vp.qtde * vp.preco;
		gotoxy(66,i),printf("R$ %.2f",vp.qtde*vp.preco);
		if(i==19){
			PaginaCupom(i);
			gotoxy(30,i),printf("ITEM  QTDE  PRODUTO                 VALOR");
		}
		fread(&vp,sizeof(TpVendasP),1,arqVP);
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
void CupomFiscal(){
	FILE *arqP=fopen("Produto.dat","rb");
	FILE *arqC=fopen("Cliente.dat","rb");
	FILE *arqV=fopen("Vendas.dat","rb");
	FILE *arqVP=fopen("VendasP.dat","rb");
	
	TpVendas v;
	int i = 8,ext;
	float tot;
	
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  VENDAS >>  CUPOM FISCAL  ]>");
	apagar(3);//msg
	gotoxy(44,6),printf("* * Cupom Fiscal * *");
	fseek(arqV,0,2);
	if(ftell(arqV)!=0)
	{
		gotoxy(3,23),printf("Digite [0] para sair");
		gotoxy(30,i++),printf("Codigo da venda: ");
		scanf("%d", &v.cod);
		
		while(v.cod > 0)
		{
			ext = buscaVendas(arqV,v.cod);
			if(ext !=-1)
			{
				PrintCupom(arqP,arqC,arqV,arqVP,v.cod,ext);
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
			scanf("%d", &v.cod);
		}
	}
	else
	{
		gotoxy(30,i++),printf("Vendas nao realizadas !");
		gotoxy(3,23),printf("[ENTER] Continuar...");
		getch();
	}
	fclose(arqP);
	fclose(arqC);
	fclose(arqV);
	fclose(arqVP);
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
void RelatorioVendas(){
	FILE *arqP=fopen("Produto.dat","rb");
	FILE *arqF=fopen("Fornecedor.dat","rb");
	FILE *arqV=fopen("Vendas.dat","rb");
	FILE *arqVP=fopen("VendasP.dat","rb");
	TpVendas v;
	TpVendasP vp;
	TpProduto p;
	TpFornecedor f;
	int i = 8, pos,pos1, cod, ext, it=1;
	float tot;
	char aux[30];
	apagar(1);//MENU
	apagar(4);//titulo
	gotoxy(3,3),printf("<[  MENU  >>  VENDAS >>  RELATORIO  ]>");
	apagar(3);//msg
	gotoxy(46,6),printf("* * Relatorio * *");
	fseek(arqV,0,2);
	if(ftell(arqV)>0)
	{
		fseek(arqV,-sizeof(TpVendas),2);
		fread(&v,sizeof(TpVendas),1,arqV);
		while(it<v.cod+1)
		{
			
			gotoxy(46,6),printf("* * Relatorio * *");
			gotoxy(30,i++),printf("Codigo de Venda: %d",it);
			gotoxy(30,i++),printf("Produtos:");
			pos = buscaVendasP2(arqVP,it);
			fseek(arqVP,pos,0);
			fread(&vp,sizeof(TpVendasP),1,arqVP);
			for(tot = 0.0; it == vp.codV && !feof(arqVP);i++)
			{
				
				gotoxy(30,i),printf("%d",vp.codP);
				
				pos1=buscaProduto(arqP,vp.codP);
				fseek(arqP,pos1,0);
				fread(&p,sizeof(TpProduto),1,arqP);
				
				strcpy(aux,p.descr);
				if(strlen(aux)>10)
					aux[11]='\0';
				gotoxy(36,i),printf("%s",aux);
				gotoxy(48,i),printf("%d",vp.qtde);
				tot += vp.qtde * vp.preco;
				gotoxy(52,i),printf("R$%.2f",vp.qtde*vp.preco);
				
				pos=buscaFornecedor(arqF,p.forn);
				fseek(arqF,pos,0);
				fread(&f,sizeof(TpFornecedor),1,arqF);
				strcpy(aux,f.nome);
				if(strlen(aux)>16)
					aux[17]='\0';
				gotoxy(62,i),printf("%s",aux);
				if(i>19)
					PaginaVendas(i);
				fread(&vp,sizeof(TpVendasP),1,arqVP);
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
	fclose(arqF);
	fclose(arqP);
	fclose(arqVP);
	fclose(arqV);
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
			//pos = buscaFornecedor(x, tl, cod);
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
			//pos=buscaFornecedor(f,tlf,cod);
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
void InserirCliente(FILE *x,char cpf[15],char nome[30],int qtde,float total){
	TpCliente c;
	strcpy(c.cpf,cpf);
	strcpy(c.nome,nome);
	c.qtde=qtde;
	c.total=total;
	fwrite(&c,sizeof(TpCliente),1,x);
}
void InserirProduto(FILE *x,int cod,char descr[20],int est,float preco,int d,int m,int a,int forn){
	TpProduto p;
	p.cod=cod;
	strcpy(p.descr,descr);
	p.est=est;
	p.preco=preco;
	p.data.d=d;
	p.data.m=m;
	p.data.a=a;
	p.forn=forn;
	fwrite(&p,sizeof(TpProduto),1,x);
}
void InserirFornecedor(FILE *x,int cod,char nome[30],char cidade[30]){
	TpFornecedor f;
	f.cod=cod;
	strcpy(f.nome,nome);
	strcpy(f.cidade,cidade);
	fwrite(&f,sizeof(TpFornecedor),1,x);
}
void InserirVendas(FILE *x,int cod,char cpf[15],int d,int m,int a,float total){
	TpVendas v;
	v.cod=cod;
	strcpy(v.cpf,cpf);
	v.data.d=d;
	v.data.m=m;
	v.data.a=a;
	v.total=total;
	fwrite(&v,sizeof(TpVendas),1,x);
}
void InserirVendasP(FILE *x,int codV,int codP,int qtde,float preco){
	TpVendasP v;
	v.codV=codV;
	v.codP=codP;
	v.preco=preco;
	v.qtde=qtde;
	fwrite(&v,sizeof(TpVendasP),1,x);
}
void InsercaoDados(int &dados){
	FILE *Cliente=fopen("Cliente.dat","wb");
	FILE *Produto=fopen("Produto.dat","wb");
	FILE *Fornecedor=fopen("Fornecedor.dat","wb");
	FILE *Vendas=fopen("Vendas.dat","wb");
	FILE *VendasP=fopen("VendasP.dat","wb");
	
	InserirCliente(Cliente,"132.456.987-44","Windislaisson",1,64.60);
	InserirCliente(Cliente,"651.325.984-77","Astolfo",1,457.48);
	InserirCliente(Cliente,"159.357.654-52","Armelinda",1,392.64);
	InserirCliente(Cliente,"544.544.999-00","Katarina",0,0);
	
	InserirProduto(Produto,7000,"Lasanha",52,9.98,10,9,2024,200);
	InserirProduto(Produto,1000,"Suco",188,1.62,15,05,2025,500);
	InserirProduto(Produto,4000,"Biscoito Delicia",63,4.56,22,11,2024,300);
	InserirProduto(Produto,3000,"Farofa",30,3.80,31,12,2023,300);
	
	InserirFornecedor(Fornecedor,200,"Fabricia Matao danilo","Matao");
	InserirFornecedor(Fornecedor,500,"Sapore S.A.","Campinas");
	InserirFornecedor(Fornecedor,300,"Basteck","Guarapuava");
	
	InserirVendas(Vendas,1,"651.325.984-77",10,8,2023,457.48);
	InserirVendas(Vendas,2,"132.456.987-44",15,7,2023,45.60);
	InserirVendas(Vendas,3,"159.357.654-52",06,4,2023,251.66);
	InserirVendas(Vendas,4,"132.456.987-44",30,10,2023,19.00);
	
	InserirVendasP(VendasP,1,1000,10,1.62);
	InserirVendasP(VendasP,1,7000,20,9.98);
	InserirVendasP(VendasP,1,4000,53,4.56);
	InserirVendasP(VendasP,2,4000,10,4.56);
	InserirVendasP(VendasP,3,7000,1,9.98);
	InserirVendasP(VendasP,3,4000,53,4.56);
	InserirVendasP(VendasP,4,3000,5,3.80);
	
	fclose(Cliente);
	fclose(Produto);
	fclose(Fornecedor);
	fclose(Vendas);
	fclose(VendasP);

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
						CadastroProduto(dados);
						break;
					case 'B':
						ConsultaProduto();
						break;
					case 'C':
						exclusaoProduto(produto,tl_produto,vendasP,tl_vendasP);
						break;
					case 'D':
						alterarProduto();
						break;
					case 'E':
						RelatorioProduto();
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
						CadastroFornecedor(dados);
						break;
					case 'B':
						ConsultaFornecedor();
						break;
					case 'C':
						exclusaoFornecedor(fornecedor,tl_fornecedor,produto,tl_produto);
						break;
					case 'D':
						alterarFornecedor();
						break;
					case 'E':
						RelatorioFornecedor();
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
						CadastroCliente(dados);
						break;
					case 'B':
						ConsultaCliente();
						break;
					case 'C':
						exclusaoCliente(cliente,tl_cliente,vendas,tl_vendas);
						break;
					case 'D':
						alterarCliente();
						break;
					case 'E':
						RelatorioCliente();
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
						CadastroVendas(dados);
						break;
					case 'B':
						exclusaoVendas(vendas,vendasP,cliente,tl_vendas,tl_vendasP,tl_cliente,produto,tl_produto);
						break;
					case 'C': 
						CupomFiscal();
						break;
					case 'D':
						RelatorioVendas();
				}
				break;
			case 'E':
				if(dados==0)
					InsercaoDados(dados);
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
