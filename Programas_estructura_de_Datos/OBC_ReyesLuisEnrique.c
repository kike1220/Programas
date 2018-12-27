//Programa Operaciones Basicas con Colas
#include <stdio.h>
#define T 10
typedef struct cola{
	int frente,final;
	int elemento[T];
} C;
int llena(C cola){
	int bandera=0;
	if(cola.final==T)
		bandera=1;
	return bandera;
}
void insertar(C *cola, int dato){
	cola->elemento[(cola->final)++]=dato;
}
int vacia(C cola){
	int bandera=0;
	if((cola.frente)+1==(cola.final))
		bandera=1;
	return bandera;
}
void imprimir(C cola){
	int i;
	for ( i = 0; i < (cola.final); i++)
	{
		printf("%5d", cola.elemento[i] );
	}
}
int borrar(C *cola){
	int i,j;
	cola->frente=0;
	for( i=1, j=(cola->frente); i<(cola->final); i++, j++)
	{
		cola->elemento[j]=cola->elemento[i];	
	}
	(cola->final)--;
	return 0;	
}

int main(){
	C cola;
	cola.final=0;
	int opcion,dato, x=1;
	while( x==1){
		printf("Que deseas hacer, presiona el numero de la opcion elegida\n 1.-Insertar un dato\n 2.-Eliminar dato\n 3.-Cola llena\n 4.-Cola vacia\n");
		scanf("%d", &opcion);
		switch (opcion){
			case 1:
				if(!llena(cola))
				{
					printf("Teclea el dato que deseas ingresar\n");
					scanf("%d", &dato);
					insertar(&cola, dato);
					imprimir(cola);
				}
				else{
					printf("La cola esta llena\n");
				}
				break;
			case 2:
				if(!vacia(cola)){
					borrar(&cola);
					imprimir(cola);
				}
				else{
					printf("La cola esta vacia\n");
				}
				break;
			case 3:
				if(!llena(cola)){
					printf("La cola no esta llena\n");
				}
				else{
					printf("La cola esta llena\n");
				}
				break;
			case 4:
				if(!vacia(cola)){
					printf("La cola no esta vacia\n");
				}
				else{
				printf("La cola esta vacia\n");
				}
				break;
		}
		printf ("\n Si desea continuar presione 1, si no presione cualquier tecla\n");
		scanf ("%d", &x);
	}
	return 0;
}
