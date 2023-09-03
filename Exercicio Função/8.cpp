#include<stdio.h>
#include<conio2.h>
#include<windows.h>
#include<locale.h>
int idade(int ano,int mes,int dia){
	return ano*256+mes*30+dia;
}
int primo(int x){
	int num=0,i;
	for(i=2;i<x && num==0;i++)
		if(x%i==0)
			num++;
	if(num==0)
		return 1;
	else
		return 0;
}
int tempo(int h,int m,int s){
	
	return h*3600+m*60+s;
}
int div(int x){
	int i,cont=0;
	for(i=1;i<=x;i++)
		if(x%i==0)
			cont++;
	return cont;
}
float polegadas(int x){
	return x*2.54;
}
int potencia(int x,int y){
	int mult=x;
	for(int i=1;i<y;i++)
		x*=mult;
	return x;
}
int LeTempo(){
	int h,m,s;
	system("cls");
	printf("Tempo: [HH MM SS]: ");
	scanf("%d%d%d",&h,&m,&s);
	return tempo(h,m,s);
}
void hino(void){
	setlocale(LC_ALL,"Portuguese");
	int i,j,tl=9;
	char tecla,palmeiras[9][40]={"Quando surge o alviverde imponente","No gramado em que a luta o aguarda","Sabe bem o que vem pela frente","Que a dureza do prélio não tarda!","","E o Palmeiras no ardor da partida","Transformando a lealdade em padrão","Sabe sempre levar de vencida","E mostrar que, de fato, é campeão!"};
	char hino[9][30]={"Salve o Corinthians","O campeão dos campeões","Eternamente","Dentro dos nossos corações","","Salve o Corinthians","De tradições e glórias mil","Tu és orgulho","Dos desportistas do Brasil"};
	printf("[1]Timão\n[2]Parmeiras ");
	tecla=getch();
	system("cls");
	if(tecla=='1'){
		for(i=0;i<tl;i++){
			for(j=0;hino[i][j]!='\0';j++){
				printf("%c",hino[i][j]);
			}
			printf("\n");
		}
		Beep(349,500);Beep(329,500);Beep(261,500);Beep(220,1000);Beep(220,1400);
		Sleep(100);
		Beep(220,240);Beep(220,240);Beep(246,240);Beep(261,240);Beep(329,240);Beep(293,240);Beep(261,240);Beep(246,2400);
		Sleep(100);
		Beep(293,500);Beep(246,500);Beep(220,500);Beep(207,1000);Beep(207,1400);
		Sleep(100);
		Beep(207,240);Beep(207,240);Beep(220,240);Beep(246,240);Beep(293,240);Beep(261,240);Beep(246,240);Beep(329,2400);
		Sleep(100);
		
		Beep(329,500);Beep(293,500);Beep(277,500);Beep(293,1000);Beep(293,1400);
		Sleep(100);
		Beep(293,240);Beep(293,240);Beep(329,240);Beep(349,240);Beep(440,240);Beep(349,240);Beep(293,240);Beep(261,2400);
		Sleep(100);
		Beep(392,500);Beep(329,500);Beep(261,500);Beep(246,1000);Beep(246,1400);
		Sleep(100);
		Beep(246,240);Beep(261,240);Beep(293,240);Beep(329,240);Beep(293,240);Beep(261,240);Beep(246,240);Beep(220,2400);
	}
	else if(tecla=='2')
		for(i=0;i<tl;i++){
			for(j=0;palmeiras[i][j]!='\0';j++){
				printf("%c",palmeiras[i][j]);
				Sleep(100);
			}
			printf("\n");
		}
}
int LeNumero(){
	int num;
	system("cls");
	printf("Numero: ");
	scanf("%d",&num);
	return num;
}
int LeIdade(){
	int a,m,d;
	system("cls");
	printf("Idade [AA MM DD]: ");
	scanf("%d%d%d",&a,&m,&d);
	return idade(a,m,d);
}
int LePotencia(){
	int x,y;
	printf("Numeros [x y]: ");
	scanf("%d%d",&x,&y);
	return potencia(x,y);
}
char menu(){
	system("cls");
	printf("~~~~~ MENU ~~~~~\n\n[1]Polegadas\n[2]Segundos\n[3]Primo\n[4]Idade\n[5]Divisores\n[6]Potencia\n[7]Hino\n[ESC]Sair");
	return getch();
}
int main(){
	char tecla;
	do{
		tecla=menu();
		switch(tecla){
			case '1':
				printf("%.2f cm",polegadas(LeNumero()));
				getch();
				break;
			case '2':
				printf("Tempo: %d segundos",LeTempo());
				getch();
				break;
			case '3':
				if(primo(LeNumero()))
					printf("e primo");
				else
					printf("nao e primo");
				getch();
				break;
			case '4':
				printf("%d dias",LeIdade());
				getch();
				break;
			case '5':
				printf("Divisores: %d",div(LeNumero()));
				getch();
				break;
			case '6':
				printf("Potencia: %d",LePotencia());
				getch();
				break;
			case '7':
				system("cls");
				hino();
				getch();
		}
	}while(tecla!=27);
	return 0;
}
