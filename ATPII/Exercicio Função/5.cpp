#include<stdio.h>
#include<conio2.h>
#include<windows.h>
void moldura(int CI, int LI, int CF, int LF){
	system("cls");
	gotoxy(CI,LI),printf("%c",201);
	gotoxy(CF,LI),printf("%c",187);
	gotoxy(CI,LF),printf("%c",200);
	gotoxy(CF,LF),printf("%c",188);
	for(int i=LI+1;i<LF;i++){
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}
	for(int i=CI+1;i<CF;i++){
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
}
void LeMoldura(){
	int CI,LI,CF,LF;
	printf("Coluna Inicial: ");
	scanf("%d",&CI);
	printf("Linha Inicial: ");
	scanf("%d",&LI);
	printf("Coluna Final: ");
	scanf("%d",&CF);
	printf("Linha Inicial: ");
	scanf("%d",&LF);
	moldura(CI,LI,CF,LF);
}
int main(){
	
	LeMoldura();
}
