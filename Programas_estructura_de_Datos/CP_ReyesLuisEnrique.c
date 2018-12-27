#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodo{
	int info,prio;
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
void insertar(tipoColaPtr cola, int dato, int pri){
	tipoNodoPtr nuevo;
	nuevo=(tipoNodoPtr)malloc(sizeof(N));
	if(nuevo==NULL)
	{
		printf("No hay memoria\n");
	}
	else
	{
		nuevo->prio=pri;
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
		printf("Prioridad: %d ", tmp.prio);
		printf("Dato: %d\n", tmp.info);
		return;
	}
	else
	{
		printf("Prioridad: %d ", tmp.prio);
		printf("Dato: %d\n", tmp.info);
	}
	imprimir(*(tmp.sig));
}
void ordenar(C tmp) {
	N *tmp1, *tmp2;
	int priori;
	int dato;
	tmp1 = tmp.ini;
	while((tmp1->sig)!= NULL)
	{
		tmp2 = tmp1->sig;
		while(tmp2!=NULL)
		{
			if(tmp1->prio < tmp2->prio)
			{
				priori=tmp1->prio;
				dato=tmp1->info;
				tmp1->prio=tmp2->prio;
				tmp1->info=tmp2->info;
				tmp2->prio=priori;
				tmp2->info=dato;
			}
			tmp2=tmp2->sig;
		}
		tmp1=tmp1->sig;
	}
}
int main(){
	C cola1={NULL};
	int x=1, opc,dato, dato1,pri;
	printf("Colas de prioridad\n");
	while(x==1){
		printf("Presione el numero de lo que deseas hacer.\n1.-Introducir un elemento.\n2.-Eliminar un elemento.\n3.-Imprimir cola.\n4.-Salir.\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf("Introduce la prioridad del elemento\n");
				scanf("%d", &pri);
				printf("Introduce el elemento\n");
				scanf("%d", &dato);
				if(cola1.ini==NULL || pri==0)
				{
					insertar(&cola1,dato,pri);	
				}
				else
				{
					if (pri==1){
						insertar(&cola1,dato,pri);
						ordenar(cola1);
					}
				}
				printf("Se inserto el elemento: %d, con prioridad: %d\n", dato, pri);
				printf("\n");
				break;
			case 2:
				if(!vacia(&cola1))
				{
					dato1=eliminar(&cola1);
					{
						printf("Se elimino el dato= %d\n", dato1);
						printf("\n");
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
