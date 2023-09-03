#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#include<conio2.h>
void piano(char x){
	int time=100;
	switch(x){
		case 'A':
			Beep(261,time);
			break;
		case 'S':
			Beep(293,time);
			break;
		case 'D':
			Beep(329,time);
			break;
		case 'F':
			Beep(349,time);
			break;
		case 'G':
			Beep(392,time);
			break;
		case 'H':
			Beep(440,time);
			break;
		case 'J':
			Beep(493,time);
	}
}
int main(){
	char tecla;
	do{
		tecla=getche();
		piano(toupper(tecla));
	}while(tecla!=27);
	return 0;
}
