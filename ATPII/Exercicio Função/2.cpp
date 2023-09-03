#include<stdio.h>
#include<math.h>
#include<conio2.h>
int binario(int x){
	int mult=1,num=0;
	while(x>0){
		num+=(x%10)*mult;
		x/=10;
		mult*=2;
	}
	return num;
}
int Le(){
	int num;
	scanf("%d",&num);
	return num;
}
void Exibe(int x){
	printf("Numero transformado: %d",x);
	getch();
}
int main(){
	Exibe(binario(Le()));
	return 0;
}
