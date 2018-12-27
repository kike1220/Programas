//Programa Operaciones Básicas con Listas Doblemente Enlazadas//
//Curso:Estructura de Datos//
//Autor:Luis Enrique Reyes Martinez//
//Fecha: 5 de Mayo del 2017//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct lista{
	char producto[20];
	struct lista *ant;
	struct lista *sig;
}tipolista;
typedef tipolista *listaPtr;
void insertar(listaPtr *ini,listaPtr *fin,char pro[]);
void imprimir(listaPtr lista);
int main(){
	listaPtr ini=NULL,fin=NULL;
	char producto[20];
	int c=1,opc;
	while(c==1)
	{
		printf("Que es lo que deseas hacer\n 1.-Insertar un dato a la lista\n 2.-Eliminar un dato de la lista\n 3.-Imprimir la lista\n 4.-Salir\n");
		scanf("%d", &opc);
		switch(opc)
		{
			case 1:{
				gets(producto);
				printf("Introduce el dato que quieres insertar\n");
				gets(producto);
				insertar(&ini,&fin,producto);
				break;
			}
			case 3:{
				imprimir(ini);
				break;
			}
			case 4:{
				c=5;
				break;
			}
		}
	}
	return 0;
}
void insertar(listaPtr *ini,listaPtr *fin,char pro[]){
	listaPtr nuevo,ant,act;
	nuevo=(listaPtr)malloc(sizeof(tipolista));
	if(nuevo==NULL)
	{
		printf("No hay memoria\n");
	}
	else{
		strcpy(nuevo->producto,pro);
		nuevo->ant=NULL;
		nuevo->sig=NULL;
		ant=NULL;
		act=*ini;
		while(act!=NULL && strcmp(act->producto,pro)<0)
		{
			ant=act;act=act->sig;
		}
		if(ant==NULL)
		{
			if(act==NULL)
			{
				*ini=nuevo;
				*fin=nuevo;
			}
			else
			{
				nuevo->sig=act;
				act->ant=nuevo;
				*ini=nuevo;
			}
		}
		else{
			if(act!=NULL)
			{
				ant->sig=nuevo;nuevo->sig=act;
				nuevo->ant=ant;act->ant=nuevo;
			}
			else
			{
				ant->sig=nuevo;
				nuevo->ant=ant;
			}
		}
	}
}
void imprimir(listaPtr lista)
{
	while(lista->sig!=NULL)
	{
		printf("Nombre: ");puts(lista->producto);
		lista=lista->sig;
	}
	printf("Nombre: ");puts(lista->producto);
}
