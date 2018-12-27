#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define T 5
typedef struct alumno{
	int matricula;
	char nombre[40];
	float promedio;
}A;
int nrepetir(A grupo[], int mat);
void crear(A grupo[]);
void imprimir(A grupo[]);
void burbuja(A grupo[]);
void quicksort(A grupo[],int ini, int fin);
void mergesort(A grupo[], int ini, int fin, int op);
void merging(A grupo[], int ini, int medio, int fin, int op);
//void secuencial(A grupob[]);
int main(){
	A grupo[T]={0};
	int op,op2;
	crear(grupo);
	printf("Que desea hacer\n 1.- Ordenamiento\n 2.- Busqueda\n");
	scanf ("%d", &op);
	switch(op){
		//Ordenamientos
		case 1:{
			printf("Esto es lo que se va a ordenar\n");
			imprimir(grupo);
			printf("\nQue tipo de ordenamiento deseas hacer\n");
			printf("1.- Burbuja\n 2.-Quicksort\n 3.-Mergesort\n");
			scanf("%d", &op2);
			switch(op2){
				case 1:{
					burbuja(grupo);
					imprimir(grupo);
					break;
				}
				case 2:{
					quicksort(grupo,0,T);
					imprimir(grupo);
					break;
				}
				case 3:{
					mergesort(grupo,0,T,1);
					imprimir(grupo);
					break;
				}
			}
		}
		//Busqueda
		case 2:{
			
			break;
		}
	}
}
//guardar datos en la estructura
int norepetir(A grupo[], int matri){
	int i, band=0;
	for(i=0; i<T; i++){
		if(grupo[i].matricula==matri)
			band=1;
	}
	return band;
}
void crear(A grupo[]){
	int matri;
	char *nombres[5]={"Pedro", "Juan", "Juan", "Pedro", "andres"};
	float prom;
	int i, band=0;
	for(i=0; i<T; i++){
		srand(time(NULL));
		matri=rand()%100;
		band=norepetir(grupo,matri);
		if(band==0){
			grupo[i].matricula=matri;
			strcpy(grupo[i].nombre, nombres[i]);
			srand(time(NULL));
			prom=rand()%10;
			if(prom<5){
				prom=prom + 1.5;
			}
			else{
				prom=prom - 1.8;
			}
			grupo[i].promedio=prom;
		}
		else{
			i--;
		}
	}
}
void imprimir(A grupo[]){
	int i;
	for(i=0; i<T; i++){
		printf("Matricula: %d ", grupo[i].matricula);
		puts(grupo[i].nombre);
		printf("Promedio: %f\n", grupo[i].promedio);
	}
}
void burbuja(A grupo[]){
	int i,j;
	A tmp;
	for(i=1;i<=T-1;i++){
		for(j=0;j<=T-2;j++){
			if(strcmp(grupo[j].nombre,grupo[j+1].nombre)>0){
				tmp=grupo[j];
				grupo[j]=grupo[j+1];
				grupo[j+1]=tmp;
			}
		}
	}
}
void quicksort(A grupo[],int izq, int der )
{ 
	int i,j;
	A x,aux; 
	i=izq; 
	j=der; 
	x=grupo[ (izq + der) /2 ]; 
    do{ 
        while((grupo[i].matricula<x.matricula) && (j<=der))
        { 
            i++;
        } 
        while((x.matricula<grupo[j].matricula) && (j>izq))
        { 
            j--;
        } 
        if(i<=j)
        { 
            aux=grupo[i];
			grupo[i]=grupo[j];
			grupo[j]=aux; 
            i++;  
			j--; 
        }
         
    }while(i<=j); 
 
    if(izq<j) 
        quicksort(grupo,izq,j); 
    if(i<der) 
        quicksort(grupo,i,der); 
}
void mergesort(A grupo[], int ini, int fin, int op){
	int medio;
	if(ini<fin){
		medio=(ini+fin)/2;
		mergesort(grupo,ini,medio,op);
		mergesort(grupo,medio+1,fin,op);
		merging(grupo,ini,medio,fin, op);
	}
	else{
		return;
	}
}
void merging(A grupo[], int ini, int medio, int fin, int op){
	int ini1,ini2,i,j;
	A b[T]={0};
		for(ini1=ini, ini2=medio+1, i=ini; ini1<=medio && ini2<=fin; i++){
			if(strcmp(grupo[ini1].nombre,grupo[ini2].nombre)<0 || strcmp(grupo[ini1].nombre,grupo[ini2].nombre)==0){
				b[i]=grupo[ini1++];
			}
			else{
				b[i]=grupo[ini2++];
			}
		}
		while(ini1<=medio){
			b[i++]=grupo[ini1++];
		}
		while(ini2<=fin){
			b[i++]=grupo[ini2++];
		}
		for(j=ini;j<=fin;j++){
			grupo[j]=b[j];
		}	
	}
/*void secuencial(A grupo[], int op){
	int op, mat, i, band=0;
	char nombre[30];
	float prom;
	if(op==1){
		printf("Introduzca la Matricula a buscar:\n");
		scanf("%d", &mat);
		for(i=0; i<Tam && ban==0; i++){
			if(grupo[i].matricula==mat){
				ban=1;
				printf("Posicion: %d\n", i);
			}
		}
		if(ban==0){
			printf("El elemento no se encuentra\n");
		}
		break;
	}
	else if(op==2){
		gets(name);
		printf("Introduzca la Matricula a buscar:\n");
		gets(name);
		for(i=0; i<Tam && ban==0; i++){
			if((strcmp(grupo[i].nombre, name))==0){
				ban=1;
				printf("Posicion: %d\n", i);
			}
		}
		if(ban==0){
			printf("El elemento no se encuentra\n");
		}		
		break;
	}
	else if(op==1){
		printf("Introduzca la Matricula a buscar:\n");
		scanf("%f", &prom);
		for(i=0; i<Tam && ban==0; i++){
			if(grupo[i].matricula==prom){
				ban=1;
				printf("Posicion: %d\n", i);
			}
		}
		if(ban==0){
			printf("El elemento no se encuentra\n");
		}
		break;
	}

}
void binaria(lista grupo[]){
	int op, mat, i, ban=0;
	char name[30];
	float prom;
	printf("Elija su tipo de busqueda.\n 1.Matricula.\n 2.Nombre.\n 3.Promedio\n");
	scanf("%d", &op);
	switch(op){
		case 1:{
			printf("Introduzca la Matricula a buscar:\n");
			scanf("%d", &mat);
			for(i=0; i<Tam && ban==0; i++){
				if(grupo[i].matricula==mat){
					ban=1;
					printf("Posicion: %d\n", i);
				}
			}
			if(ban==0){
				printf("El elemento no se encuentra\n");
			}
			break;
		}
		case 2:{
			gets(name);
			printf("Introduzca la Matricula a buscar:\n");
			gets(name);
			for(i=0; i<Tam && ban==0; i++){
				if((strcmp(grupo[i].nombre, name))==0){
					ban=1;
					printf("Posicion: %d\n", i);
				}
			}
			if(ban==0){
				printf("El elemento no se encuentra\n");
			}		
			break;
		}
		case 3:{
			printf("Introduzca la Matricula a buscar:\n");
			scanf("%f", &prom);
			for(i=0; i<Tam && ban==0; i++){
				if(grupo[i].matricula==prom){
					ban=1;
					printf("Posicion: %d\n", i);
				}
			}
			if(ban==0){
				printf("El elemento no se encuentra\n");
			}
			break;
		}
	}
}*/
