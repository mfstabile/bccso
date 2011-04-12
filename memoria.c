#include<stdio.h>
#include<stdlib.h>

#define tammem 100
void* aloca(int tamanho);

typedef unsigned char byte;

void libera(void* endereco);

byte memoria[tammem];

int main(){
	int * a,*b,*c; 
	a=(int*)aloca(10);
	*a=10;
	
	b=(int*)aloca(11);
//	printf("\n%d\n",b);
	*b=45;
	
	libera(a);
//	printf("\nb %d\n",*b);
	c=(int*)aloca(6);
	*c=12;	

	libera(b);
	libera(c);
	int i=0;
/*	for(i=0;i<tammem;i++){
		printf("%d",memoria[i]);
	}*/
	return 0;
}

void* aloca(int tamanho){
	int percorre=0,ver=0;
	int *point;
	while((percorre+tamanho)<tammem){
		if(memoria[percorre]==0){
			ver=verificaespaco(percorre,tamanho);
			if(ver==1){
				point=(int*)&memoria[percorre];
		//		printf("\np1 %d\n",point);
				*point=tamanho;
				point+=1;
			//	printf("\np2 %d\n",point);
				return (void*)point;
			}
		}
		else{
			point=(int*)&memoria[percorre];
			percorre+=*point;
		}	
	}
	return NULL;
}

int verificaespaco(int percorre,int tamanho){
	int i=0;
	for(i=0;i<tamanho;i++){
		if(memoria[percorre+i]!=0){
			return 0;
		}
	}
	return 1;
}

void libera(void *endereco){
	endereco = (byte*)endereco;
	int *I = (int*)endereco;
//	printf("\npont00 %d",I); 
	I -= 1; 
	
//	printf("\npont-1 %d\n",*I);

	int i;
	byte* aux;
	for(i=0;i<*I;i++){
		aux=endereco;
		*aux=0;
		aux++;
	}
	for(i=0;i<=4;i++){
		*I=0;
	}
}
