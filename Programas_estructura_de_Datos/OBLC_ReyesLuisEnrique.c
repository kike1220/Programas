//Programa Operaciones Básicas con Colas Circulares//
//Curso: Estructura de Datos//
//Autor:Luis Enrique Reyes Martinez//
//Fecha:2 de Mayo del 2017//
//Grupo:202-B//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define T 30
typedef struct listaC{
	char nombre[T];
	struct listaC *sig;
}listaC;
typedef listaC *listaCptr;
void insertar(listaCptr *lista, char *dato);
void eliminar(listaCptr *lista,char *dato);
void imprimir(listaCptr lista);
int buscar(listaCptr lista, char *dato);
int main (){
	listaCptr lista=NULL;
	int opc,x=1,busq;
	char nombre[T];
	while(x==1){
		printf(" Que desea hacer\n 1.-Insertar un dato\n 2.- Eliminar un dato \n 3.- Imprimir lista\n 4.- Salir\n");
		scanf("%d", &opc);
		switch(opc){
			case 1: {
				gets(nombre);
				printf("Introduzca el dato\n");
				gets(nombre);
				insertar(&lista, nombre);
			break;
			}
			case 2: {
				gets(nombre);
				printf("Introduzca el dato que desea eliminar\n");
				gets(nombre);
				busq=buscar(lista,nombre);
				if(busq==1)
				{
					eliminar(&lista, nombre);
				}
				else
				{
					printf("El dato que quieres eliminar no se encuentra\n");	
				}
			break;
			}
			case 3:{
	    		imprimir(lista);
			break;
			}
			case 4: {
				x=5;
			break;
			}
		}
	}
}
void insertar(listaCptr *lista, char *dato){
	listaCptr nuevo;
	nuevo=(listaCptr)malloc(sizeof(listaC));
	if(nuevo==NULL){
		printf("No hay memoria\n");
	}
	else{
		strcpy(nuevo->nombre,dato);
		if(*lista==NULL){
			nuevo->sig=nuevo;
			*lista=nuevo;
		}
		else{
			nuevo->sig=(*lista)->sig;
			(*lista)->sig=nuevo;
			*lista=nuevo;
		}
	}
}
void eliminar(listaCptr *lista,char *dato)
{
	listaCptr tmp,ant,act;
	tmp=*lista;
	if((strcmp(tmp->nombre,dato)==0) && (strcmp(tmp->sig->nombre,dato)==0))
	{
		*lista=NULL;
		free(tmp);
	}
	else
	{
		ant=NULL;
		act=*lista;
		while((strcmp(act->nombre,dato)>0) || (strcmp(act->nombre,dato)<0))
		{
			ant=act;
			act=act->sig;
		}
		if(ant==NULL)
		{
			while((strcmp(act->sig->nombre,dato)>0) || (strcmp(act->sig->nombre,dato)<0))
			{
				act=act->sig;
			}
			act->sig=tmp->sig;
			*lista=act;
			free(tmp);
		}
		else
		{
			if(strcmp(tmp->nombre,act->sig->nombre)==0)
			{
					ant->sig=tmp;
					*lista=tmp;
					free(act);
			}
			else
			{
				while((strcmp(tmp->nombre,ant->nombre)<0) || (strcmp(tmp->nombre,ant->nombre)>0))
				{
					tmp=tmp->sig;
				}
				tmp->sig=act->sig;
				while((strcmp(tmp->nombre,(*lista)->nombre)<0) || (strcmp(tmp->nombre,(*lista)->nombre)>0))
				{
					tmp=tmp->sig;
				}
				*lista=tmp;
				free(act);
			}
		}
	}
}
void imprimir(listaCptr lista){
	char aux[20];
	if(lista==NULL)
	{
		printf("La lista esta vacia\n");
	}
	else
	{
		strcpy(aux,lista->nombre);
		printf("Nombre: ");puts(lista->nombre);
		lista=lista->sig;
	    while((strcmp(lista->nombre,aux)<0) || (strcmp(lista->nombre,aux)>0))
	    {
	    	printf("Nombre: ");puts(lista->nombre);
	    	lista=lista->sig;
		}
	}
}
int buscar(listaCptr lista, char *dato)
{
	int bandera=0;
	char aux[T];
	strcpy(aux,lista->nombre);
	if(strcmp(aux,dato)==0)
	{
		bandera=1;
	}
	else
	{
		lista=lista->sig;
		while((strcmp(lista->nombre,aux)<0) || (strcmp(lista->nombre,aux)>0))
		    {
		    	if(strcmp(lista->nombre,dato)==0)
				{	
					bandera=1;
				}
		    	lista=lista->sig;
			}	
	}
	return bandera;
}

