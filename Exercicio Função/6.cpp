#include<stdio.h>
long long int fatorial(int x){
	long long int result=1;
	for(int i=2;i<=x;i++)
		result*=i;
	return  result;
}
int LeNum(){
	int num;
	printf("Numero: ");
	scanf("%d",&num);
	return num;
}
int main(){
	printf("Fatorial: %lld",fatorial(LeNum()));
	return 0;
}
