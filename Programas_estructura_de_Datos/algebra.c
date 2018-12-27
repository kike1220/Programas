#include <stdio.h>
#include <stdlib.h>
#define T 100
void leer(int f, int c, int m[T][T], int x){
	int i, j;
	if(x==1){
		char t='a';
		printf("\n");
		for (i = 0; i < f; i++)
		{
			for (j = 0; j <c ; j++)
			{
				printf("Ingrese %c(%d,%d)\n", t, i, j);
				scanf("%d", &m[i][j]);
			}
		}		
	}
	else{
		char t='b';
		printf("\n");
		for (i = 0; i < f; i++)
		{	
			for (j = 0; j <c ; j++)
			{
				printf("Ingrese %c(%d,%d)\n", t, i, j);
				scanf("%d", &m[i][j]);
			}
		}
	}
}
void imprimir(int f, int c, int m[T][T]){
	int i,j;
	printf("Esta es tu matriz:\n");
	for( i=0; i < f; i++)
	{
		for (j = 0; j <c ; j++)
		{
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
}
void imprimir2(int f, int c, int m[T][T]){
	int i,j;
	printf("Esta es tu matriz resultante:\n");
	for( i=0; i < f; i++)
	{
		for (j = 0; j <c ; j++)
		{
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
}
void suma(int f1, int c1, int m1[T][T], int f2, int c2, int m2[T][T]){
	int m[T][T]={0};
	int i,j;
	if(f1==f2 && c1==c2){
		for( i=0; i<f1; i++){
			for( j=0; j<c1; j++){
				m[i][j]=m1[i][j]+m2[i][j];
			}
		}
		printf("\n");		
		imprimir2(f1, c1, m);
	}
	else
		printf("No se pueden sumar las matrices\n");
}
void multi(int f1, int c1, int m1[T][T], int f2, int c2, int m2[T][T]){
	int m[T][T]={0};
	int i,j,y,x;
	if(c1==f2){
		for( i=0; i<f1; i++){
			for( y=0; y<c2; y++){
				int suma=0;				
				for( j=0, x=0; j<c1 && x<f2; j++, x++){
					suma+=m1[i][j]*m2[x][y];
				}
				m[i][y]=suma;
			}
		}
		printf("\n");
		imprimir2(f1, c2, m);
	}
	else{
		printf("No se pueden multiplicar las matrices\n");
	}
}
int determinante(int f, int c, int m[T][T]){
	int det=0;
	if(f==2){
		det=((m[0][0])*(m[1][1]))-((m[1][0])*(m[0][1]));
		return det;
	}
	if(f==3){
		det=(m[0][0])*((m[1][1])*(m[2][2])-(m[2][1])*(m[1][2]));
		det=det - (m[0][1])*((m[1][0])*(m[2][2])-(m[2][0])*(m[1][2]));
		det=det + (m[0][2])*((m[1][0])*(m[2][1])-(m[2][0])*(m[1][1]));
		return det;
	}
}
int main (){
	int opc, m1[T][T]={0}, f1,c1, f2,c2, m2[T][T]={0},x=1;
	while(x==1)
	{
		printf("Que deseas hacer\n1.- Suma de matrices.\n2.- Producto de matrices.\n3.- Determinante de una matriz\n");
		printf("\nIntroduce la opcion que quieres escoger= ");scanf("%d", &opc);
		switch (opc){
			case 1:
			{
				printf("\nIngrese la matriz A\n");
				printf("\n");
				printf("Numero de filas que deseas= ");scanf("%d", &f1);
				printf("\nNumero de columnas que deseas= ");scanf("%d", &c1);
				int x=1;
				leer(f1, c1, m1, x);
				imprimir(f1, c1,m1);
				printf("Ingrese la matriz B\n");
				x=0;
				printf("\n");
				printf("Numero de filas que deseas= ");scanf("%d", &f2);
				printf("\nNumero de columnas que deseas= ");scanf("%d", &c2);
				leer(f2, c2, m2, x);
				imprimir(f2, c2,m2);
				suma(f1, c1, m1, f2, c2, m2);
			}break;
			case 2:
			{
				printf("Ingrese la matriz A\n");
				printf("\n");
				printf("Numero de filas que deseas= ");scanf("%d", &f1);
				printf("\nNumero de columnas que deseas= ");scanf("%d", &c1);
				int x=1;
				leer(f1, c1, m1, x);
				imprimir(f1, c1,m1);
				printf("Ingrese la matriz B\n");
				x=0;
				printf("\n");
				printf("Numero de filas que deseas= ");scanf("%d", &f2);
				printf("\nNumero de columnas que deseas= ");scanf("%d", &c2);
				leer(f2, c2, m2, x);
				imprimir(f2, c2,m2);
				multi(f1, c1, m1, f2, c2, m2);			
			}break;
			case 3:
			{
				printf("Ingrese la matriz A\n");
				printf("Ingresa el numero de filas que deseas= "); 
				scanf("%d", &f1);
				printf("Ingresa elnumero de columnas que deseas= "); 
				scanf("%d", &c1);
				if(f1==c1){
						x=1;
						leer(f1, c1, m1, x);
						imprimir(f1, c1,m1);
						int det1;
						det1=determinante(f1, c1, m1);
						printf("El determinante de la matriz es :%5d\n", det1);
				}
				else
					printf("No es posible calcular el determinante.\n La matriz no es cuadrada\n");					
			}
		}
		printf("\nSi desea continuar oprime 1 sino oprime cualquier otra tecla\n");
		scanf("%d", &x);
		system("cls");
	}
	return 0;
}
