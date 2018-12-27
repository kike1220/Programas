//Operaciones Basicas Con Pilas Dinamicas
#include <stdio.h>
#include <stdlib.h>
#define T 10
struct pila{
	int dato;
	struct pila *sig;
};
typedef struct pila tipoPila;
typedef tipoPila *tipoPilaPtr;
int vacia(tipoPilaPtr topetemp)
{
	int bandera;
	if(topetemp==NULL)
	{
		bandera=1;
	}
	else
	{
		bandera=0;
	}
	return bandera;
}
int llena(tipoPilaPtr topetemp)
{
	int bandera;
	if(topetemp==T)
	{
		bandera=1;
	}
	else
	{
		bandera=0;
	}
	return bandera;
}
void imprimir(tipoPilaPtr topetemp)
{
	if(topetemp==NULL)
		return;
	else
		printf("%5d", topetemp->dato);
	imprimir(topetemp->sig);
}
void push(tipoPilaPtr *tope,int num)
{
	tipoPilaPtr nuevo;
	nuevo=(tipoPilaPtr) malloc(sizeof(tipoPila));
	if(nuevo==NULL)
	{
		printf("No hay ningun elemento en la pila");
		getch();
	}
	else
	{
		nuevo->dato=num;
		nuevo->sig=*tope;
		*tope=nuevo;	
	}
}
int pop(tipoPilaPtr *topetemp)
{
	int num;
	tipoPilaPtr temp;
	temp=*topetemp;
	num=temp->dato;
	*topetemp=temp->sig;
	free(temp);
	return num;
}
int main(){
	tipoPilaPtr tope=NULL;
	int num,opc,x=1;
	while(x==1)
	{
			printf("Que operacion desea hacer\n");
			printf("1.-Introducir un elemento\n");
			printf("2.-Eliminar un elemento\n");
			printf("3.-Pila Llena\n");
			printf("4.-Pila Vacia\n");
			scanf("%d", &opc);
			switch(opc)
			{
				case 1:
					if(!llena(tope))
					{
						printf("Introduzca el elemento que desea insertar\n");
						scanf("%d", &num);
						push(&tope,num);
						imprimir(tope);
					}
					else
					{
						printf("La pila esta llena\n");
					}
					break;
				case 2:
					if(!vacia(tope))
					{
						pop(&tope);
						imprimir(tope);
					}
					else
					{
						printf("La pila esta vacia\n");
					}
					break;
				case 3: 
					if(!llena(tope))
					{
						printf("La pila no esta llena\n");	
					}
					else
					{
						printf("La pila esta llena\n");
					}break;
				case 4:
					if(!vacia(tope))
					{
						printf("La pila no esta vacia\n");	
					}
					else
					{
						printf("La pila esta vacia\n");
					}break;
			}
			printf("\nSi desea continuar presione 1 y si no oprima cualquier tecla\n");
		scanf("%d", &x);
	}
	return 0;
}
