#include<stdio.h>
int perfeito(int num){
	int i=1,soma=0;
	while(i<num){
		if(num%i==0)
			soma+=i;
		i++;
	}
	if(num!=soma)
		return 0;
	else
		return 1;
}
int Le(){
	int num;
	printf("Numero: ");
	scanf("%d",&num);
	return num;
}
int main(){
	if(perfeito(Le()))
		printf("e Perfeito");
	else
		printf("nao e perfeito");
	return 0;
}
