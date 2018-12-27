//Programa de recursividad del elemento maximo de un arreglo//
//Curso:Estructura de Datos//
//Autor:Luis Enrique Reyes Martinez//
//Fecha: 24 de Abril del 2017//
#include <stdio.h>
#include <stdlib.h>
#define T 10
void leer(int v[],int);
void imprimir(int v[],int);
int maximo(int v[],int,int,int);
int main(){
	int v[T],max,i=0,n,max1,x=1;
	while(x==1)
	{
		printf("Introduzca el numero de elementos que deesea en su vector\n");
		scanf("%d", &n);
		printf("\nIntroduzca los elementos de su vector\n");
		leer(v,n);
		printf("\nEste es su vector\n");
		imprimir(v,n);
		max1=v[0];
		max=maximo(v,n,i,max1);
		printf("\nEl dato mayor de tu vector es: %d\n", max);	
		printf("\nSi deseas volver a usar el programa presiona 1 sino presiona cualquier tecla\n");
		scanf("%d", &x);
		system("cls");
	}
	return 0;
}
void leer(int v[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d", &v[i]);
	}
}
void imprimir(int v[], int n)
{
	int i;
	for( i=0;i<n;i++)
	{
		printf("%4d", v[i]);
	}
	printf("\n");
}
int maximo(int v[], int n,int i,int max)
{	
	if(i==n)
	{
		return max;
	}
	else
	{
		if(max<v[i])
		{
			max=v[i];
		}
	}
	maximo(v,n,i+1,max);
}
