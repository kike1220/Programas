//Programa acerca de un estacionamiento con Pilas Estaticas
#include <stdio.h>
#define T 10
typedef struct hora{
	int hora1, hora2,horat;
	int min1, min2, mint;
}H;
typedef struct carro{
	int carro;
	H tiempo;
}C;
typedef struct pila{
	int tope;
	C elemento[T];
} P;
int llena(P tipopila){
	int bandera=0;
	if(tipopila.tope==T)
		bandera=1;
	else
		bandera=0;
	return bandera;
}
void push(P *tipopila, C *dato){
	tipopila->elemento[(tipopila->tope)++]=*dato;
}
int vacia(P tipopila){
	int bandera=0;
	if(tipopila.tope==0)
		bandera=1;
	else
		bandera=0;
	return bandera;
}
void imprimiren(P tipopila){
	int i;
	for ( i = 0; i < (tipopila.tope); i++)
	{
		printf("Coche:%3d    Hora de entrada %3d:%d\n", tipopila.elemento[i].carro, tipopila.elemento[i].tiempo.hora1,tipopila.elemento[i].tiempo.min1);
	}
}
void imprimirsa(P tipopila, int i,float total){
	printf("Coche:%3d    Hora de salida %3d:%d\n", tipopila.elemento[i].carro, tipopila.elemento[i].tiempo.hora2,tipopila.elemento[i].tiempo.min2);
	printf("Tiempo total %3d:%d y en total fueron= $%f\n", tipopila.elemento[i].tiempo.horat,tipopila.elemento[i].tiempo.mint,total);
	printf("\n");
}
int pop(P *tipopila){
	P pilatemp={0};
	int j=0,i,band=0;
	C salida;
	float total,mint;
	printf("Coche que saldra y hora de salida\n");
	scanf("%d %d %d", &salida.carro, &salida.tiempo.hora2, &salida.tiempo.min2);
	for ( i = (tipopila->tope) ; i>0 && band==0  ; i--, j++)
	{
		int tmp=i;
		if(tipopila->elemento[i].carro==salida.carro)
		{
			tipopila->elemento[i].tiempo.hora2=salida.tiempo.hora2;
			tipopila->elemento[i].tiempo.min2=salida.tiempo.min2;
			tipopila->elemento[i].tiempo.horat=(tipopila->elemento[i].tiempo.hora2)-(tipopila->elemento[i].tiempo.hora1);
			if((tipopila->elemento[i].tiempo.min1)>(tipopila->elemento[i].tiempo.min2))
			{
				tipopila->elemento[i].tiempo.mint=(tipopila->elemento[i].tiempo.min2)+(60-(tipopila->elemento[i].tiempo.min1));
				if((tipopila->elemento[i].tiempo.mint)==60)
				{
					tipopila->elemento[i].tiempo.horat+=1;
					tipopila->elemento[i].tiempo.mint=0;
				}
			}
			else
			{
				tipopila->elemento[i].tiempo.mint=(tipopila->elemento[i].tiempo.min2)-(tipopila->elemento[i].tiempo.min1);
			}
			mint=tipopila->elemento[i].tiempo.mint;
			total=((tipopila->elemento[i].tiempo.horat)+(mint/60))*10;
			imprimirsa(*tipopila,i,total);
			int k;
			for ( k = (pilatemp.tope)-1; k>0 ; k--)
			{
				tipopila->elemento[tmp]=pilatemp.elemento[k];
				tmp++;
			}
			band=1;
			tipopila->tope--;
		}
		else
		{
			pilatemp.elemento[j]=tipopila->elemento[i];
			pilatemp.tope++;	
		}	
	}
	return 0;	
}
int main(){
	P tipopila={0};
	int opcion, x=1;
	C entrada;
	while( x==1){
		printf("Estacionamiento\n 1.-Coche y hora de entrada\n 2.-Coche que saldra y hora de salida\n 3.-Estacionamiento lleno\n 4.-Estacionamiento vacio\n");
		scanf("%d", &opcion);
		switch (opcion){
			case 1:
				if(!llena(tipopila))
				{
					printf("Carro a entrar y hora de entrada\n");
					scanf("%d %d %d", &entrada.carro, &entrada.tiempo.hora1, &entrada.tiempo.min1);
					push(&tipopila, &entrada);
					printf("Este es el Estacionamiento\n");
					imprimiren(tipopila);
				}
				else{
					printf("El estacionamiento esta lleno\n");
				}
				break;
			case 2:
				if(!vacia(tipopila)){
					pop(&tipopila);
					printf("Este es el Estacionamiento\n");
					imprimiren(tipopila);
				}
				else{
					printf("El estacionamiento esta vacio\n");
				}
				break;
			case 3:
				if(!llena(tipopila)){
					printf("El estacionamiento no esta lleno\n");
				}
				else{
					printf("El estacionamiento esta lleno\n");
				}
				break;
			case 4:
				if(!vacia(tipopila)){
					printf("El estacionamiento no esta vacio\n");
				}
				else{
				printf("El estacionamiento esta vacio\n");
				}
				break;
		}
		printf ("\n Si desea continuar presione 1 y si no oprima cualquier otra tecla\n");
		scanf ("%d", &x);
	}
	return 0;
}
