//Programa recursivo de busqueda binaria de un Arreglo ordenado//
//Curso:Estructura de Datos//
//Autor:Luis Enrique Reyes Martinez//
//Fecha: 24 de Abril del 2017// 
#include <stdio.h>
#include <stdlib.h>
#define T 100
void leer(int v[],int);
void imprimir(int v[],int);
int bbinaria(int v[],int,int,int);
int main (){
	int x=1,v[T],n,bus,dato;
	while(x==1)
	{
		int ini=0;
		printf("Introduce el numero de elementos que deseas en tu vector\n");
		scanf("%d", &n);
		printf("\nIntroduce los elementos de tu vector\n");
		leer(v,n);
		printf("\nEste es tu vector\n");
		imprimir(v,n);
		printf("\nIntroduzca el dato que desea buscar\n");
		scanf("%d", &dato);
		bus=bbinaria(v,ini,n,dato);
		if(bus!=-1)
		{
			printf("\nEl dato %d si se encuentra en el vector, en la posicion %d .\n", dato, bus );
		}
		else
		{
			printf("\nEl dato %d no se encuentra\n", dato);
		}
		printf("\nSi desea volver a utilizar el programa presione 1 sino presione otra tecla\n");
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
	for(i=0;i<n;i++)
	{
		printf("%4d", v[i]);
	}
	printf("\n");
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
