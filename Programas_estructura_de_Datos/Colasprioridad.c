//Colas de Prioridad
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodo{
	int prio;
	int info;
	struct nodo *sig;
}N;
typedef struct cola{
	struct nodo *ini;
	struct nodo *fin;
}C;
typedef C *tipoColaPtr;
typedef N *tipoNodoPtr;
int vacia(tipoColaPtr cola){
	int bandera=0;
	if(cola->ini==NULL && cola->fin==NULL)
	{
		bandera=1;
	}
	return bandera;
}
void insertar(tipoColaPtr cola, int dato,int dato2){
	tipoNodoPtr nuevo;
	nuevo=(tipoNodoPtr)malloc(sizeof(N));
	if(nuevo==NULL)
	{
		printf("No hay memoria\n");
	}
	else
	{
		nuevo->prio=dato2;
		nuevo->info=dato;
		nuevo->sig=NULL;
	}
	if(cola->fin==NULL)
	{
		cola->ini=nuevo;
	}
	else{
		cola->fin->sig=nuevo;
	}
	cola->fin=nuevo;
}
void ordenar(C *cola,int dato,int dato2)
{
	for(;;)
	{
		
	}
}
int eliminar(C *cola)
{
	tipoNodoPtr tmp=cola->ini;
	int dato=tmp->info;
	if(cola->ini==cola->fin)
	{
		cola->fin=NULL;
		cola->ini=NULL;
	}
	else
	{
		cola->ini=tmp->sig;
	}
	free(tmp);
	return dato;
}
void imprimir(N tmp)
{
	if(tmp.sig==NULL)
	{
		printf("%5d %5d", tmp.prio, tmp.info);
		return;
	}
	else
	{
		printf("%5d %5d", tmp.prio, tmp.info);
	}
	imprimir(*(tmp.sig));
}
int main(){
	C cola1={NULL};
	int x=1, opc,dato, dato1,prio;
	while(x==1){
		printf("Que es lo que deseas hacer\n 1.-Insertar un elemento en la cola\n 2.-Eliminar un elemento en la cola\n 3.-Imprimir la cola\n 4.-Salir\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf("Introduce la prioridad del elemento\n");
				scanf("%d", &prio);
				printf("Introduce el elemento que deseas ingresar\n");
				scanf("%d", &dato);
				insertar(&cola1,dato,prio);
				if(prio=1)
				{
					ordenar(&cola,dato,prio);
				}
				break;
			case 2:
				if(!vacia(&cola1))
				{
					dato1=eliminar(&cola1);
					{
						printf("Se elimino este dato= %d\n", dato1);
					}
				}
				else
				{
					printf("La cola esta vacia\n");
				}
				break;
			case 3:
				printf("La cola es: \n");
				imprimir(*(cola1.ini));
				printf("\n");
			break;
			case 4:	
				x=2;
				printf("Se ha terminado de ejecutar el programa");
			break;
		}
	}
	return 0;
	
}
