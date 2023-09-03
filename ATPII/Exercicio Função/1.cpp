#include<stdio.h>
#include<math.h>
#include<conio2.h>
int binario(int x){
	int bin=0,mult=1;
	while(x>0){
		bin+=(x%2)*mult;
		x/=2;
		mult*=10;
	}
	return bin;
}
void Exibe(int x){
	printf("Numero transformado: %d",x);
	getch();
}
int Le(void){
	int x;
	printf("Digite um numero: ");
	scanf("%d",&x);
	return x;
}
int main(){
	Exibe(binario(Le()));
	return 0;
}
