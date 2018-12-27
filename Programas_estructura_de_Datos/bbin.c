#include <stdio.h>
#define T 100
void leer(int v[],int);
int bbinaria(int v[],int,int,int);
int main (){
	int v[T],n,bus,dato,i=0;
	scanf("%d", &n);
	leer(v,n);
	printf("Introduzca el dato que desea buscar.b\n");
	scanf("%d", &dato);
	bus=bbinaria(v,i,n,dato);
	if(bus!=-1)
	{
		printf("El dato %d si se encuentra en el vector, en la posicion %d .\n", dato, bus );
	}
	else
	{
		printf("El dato no se encuentra\n");
	}
	return 0;
}
void leer(int v[], int n)
{
	int i;
	for( i=0;i<n;i++)
	{
		scanf("%d", &v[i]);
	}
}
int bbinaria(int v[],int izq,int der,int dato){
	int mitad=(izq+der)/2;
	if(izq==der && v[izq]!= dato){
		return -1;
	}
	if(v[mitad]==dato)
	{
		return mitad;
	}
	else {
		if (v[mitad] < dato){
			bbinaria(v,mitad+1,der,dato);
		}
		else{
			if(v[mitad] > dato){
			bbinaria(v,izq,mitad-1,dato);
			}
		}
	}
}
