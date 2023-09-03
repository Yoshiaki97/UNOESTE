#include<stdio.h>
int dif(int hi,int mi,int si,int hf,int mf,int sf){
	int h,m=0,s=0;
	if(hi==hf && mi==mf && si==sf)
		h=24;
	else{
		if(si>sf){
			sf+=60;
			mf--;
		}
		s=sf-si;
		if(mi>mf){
			mf+=60;
			hf--;
		}
		m=mf-mi;
		if(hi>hf){
			h=24-(hi-hf);
		}
		else
			h=hf-hi;
	}
	printf("%d:%d:%d\n",h,m,s);
	return h*3600+m*60+s;
}
int Le(){
	int hi,mi,si,hf,mf,sf;
	printf("Horario inicial [HH MM SS]: ");
	scanf("%d%d%d",&hi,&mi,&si);
	printf("Horario final   [HH MM SS]: ");
	scanf("%d%d%d",&hf,&mf,&sf);
	
	return dif(hi,mi,si,hf,mf,sf);
}
int main(){
	
	printf("diferenca: %d segundos",Le());
	return 0;
}
