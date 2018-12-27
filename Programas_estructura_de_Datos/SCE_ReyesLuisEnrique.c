//PROGRAMA SISTEMA DE CONTROL ESCOLAR
//ESTRUCTUIRA DE DATOS
//Reyes Martinez Luis Enrique
//GRUPO:202-B
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct alumno{
	int matri;
	char nombre[20];
	float prom;
}A;
typedef struct lista{
	A dato;
	struct lista *sig;
}tipolista;
typedef tipolista *listaPtr;
void insertar(listaPtr *lista,A dato);
void consulta(tipolista lista, int matri, int i);
void consulta2(tipolista lista, float prom, int i);
void consulta3(tipolista lista, char nombre[], int i);
int busqueda(tipolista lista, int matri);
void eliminar(listaPtr *lista,int dato);
void imprimir(listaPtr lista);
void leer(listaPtr *lista);
void guardar(listaPtr lista);
int main(){
    A dato;
 	int matri,j;
 	char nombre[20];
 	float prom;
 	int x=1,opc,opc1;
 	listaPtr lista=NULL;
	while(x==1)
	    {
     	    int i=1;
     		printf("Que quieres hacer\n 1.-Insertar dato\n 2.-Eliminar dato\n 3.-Consulta en la lista\n 4.-Guardar lista\n 5.-imprimir la lista\n 6.-Salir\n");
      		scanf("%d", &opc);
      		leer(&lista);
      		switch(opc)
      		{
      			   case 1:
      			   	gets(nombre);
						printf("introduzca el nombre del alumno\n");
				      	gets(nombre);
				      	printf("introduzca la matricula del alumno\n");
				      	scanf("%d", &matri);
				     	printf("Introduzca el promedio del alumno\n");			 
				      	scanf("%f", &prom); 
				       	strcpy(dato.nombre,nombre);
				      	dato.matri=matri;
				      	dato.prom=prom; 
      			    if(lista==NULL)
             		{
                 		insertar(&lista,dato);
              		}
             		else
             		{
                  		j=busqueda(*(lista),matri);
                  		if(j==0)
                 		 {
      			             insertar((&lista),dato);
           	      		 }
           	      	 	else
           	      		{
           	            	printf("La matricula ya se encuentra en la lista\n");
     	                
           	            }
             		}
      			   break;
      			   case 2:
      				   printf("Introduzca la matricula del dato que quieres eliminar\n");
      				   scanf("%d", &matri);
      				   eliminar(&lista,matri);
      				   break;
      			   case 3:
      				   printf("Como quieres hacer tu consulta\n 1.-Matricula\n 2.-Promedio\n 3.-Nombre\n");
      				   scanf("%d", &opc1);
      				   switch(opc1){
      				      case 1: printf("Introduce la matricula que quieres consultar\n"); 
      				      scanf("%d", &matri);
      				      consulta(*(lista),matri,i);
      				      break;
      				      case 2: printf("Introduce el promedio que quieres consultar\n"); 
      				      scanf("%f", &prom);
      				      consulta2(*(lista),prom,i);
      				      break;
      				      case 3:
							gets(nombre); 
      				      printf("Introduce el nombre que quieres consultar\n"); 
      				      gets(nombre);
      				      consulta3(*(lista),nombre,i);
      				      break;
      				     }
      				    break;
      			   case 4:
      			      guardar(lista);
      				   break;	
      			   case 5:
      			     imprimir(lista);
      				   break;	
      			   case 6:
      			      	guardar(lista);
      				   x=x+2;
      				   break;
		    }
	   }
	return 0;
}
void leer(listaPtr *lista)
{
	A dato;
 	int matri,i,n=0;
 	char nombre[20];
 	float prom;
 	FILE *arch=fopen("l.txt","rb");
 	listaPtr anterior,actual,nuevo;
 	if(arch==NULL)
 	{
 		return;	
	}
	else
	{
		fread(&n,sizeof(int),1,arch);
		for(i=0;i<=n;i++)
		{
	   	fread(nombre,sizeof(char),20,arch);
			fread(&matri,sizeof(int),1,arch);
			fread(&prom,sizeof(float),1,arch);
			strcpy(dato.nombre,nombre);
			dato.matri=matri;
			dato.prom=prom;
		 	nuevo=(listaPtr)malloc(sizeof(tipolista));
 			if(nuevo==NULL)
 			{
 				printf("No hay memoria\n");
 			}
 			else
    		{
   				nuevo->dato=dato;
   				nuevo->sig=NULL;
   				if(*lista==NULL)
   					*lista=nuevo;
   				else
    	 		{
  	   				anterior=NULL;
     				actual=*lista;
     				while(actual!=NULL && (actual->dato.matri)<dato.matri) 
     				{
     					anterior=actual;
     					actual=actual->sig;
     				}
     				if(anterior==NULL)
     				{
     					nuevo->sig=actual;
     					*lista=nuevo;
     				}
     				else
     				{
     					anterior->sig=nuevo;
     					nuevo->sig=actual;
   			     	}
   			     }
   			}
 		}
		fclose(arch);	
	}
	
}
void insertar(listaPtr *lista,A dato)
{
 	listaPtr anterior,actual,nuevo;
 	nuevo=(listaPtr)malloc(sizeof(tipolista));
 	if(nuevo==NULL)
 	{
 		printf("No hay memoria\n");
 	}
 	else
    {
   		nuevo->dato=dato;
   		nuevo->sig=NULL;
   		if(*lista==NULL)
   			*lista=nuevo;
   		else
    	 {
  	   		anterior=NULL;
     		actual=*lista;
     		while(actual!=NULL && (actual->dato.matri)<dato.matri) 
     		{
     			anterior=actual;
     			actual=actual->sig;
     		}
     		if(anterior==NULL)
     		{
     			nuevo->sig=actual;
     			*lista=nuevo;
     		}
     		else
     		{
     			anterior->sig=nuevo;
     			nuevo->sig=actual;
   		   }
   		}
 	}
}
void eliminar(listaPtr *lista,int dato){
	listaPtr tmp,act,ant;
	if((*lista)->dato.matri==dato)
	{
		tmp=*lista;
		*lista=tmp->sig;
		free(tmp);
	}
	else
	{
		ant=NULL;
		act=*lista;
		for(;act!=NULL && act->dato.matri!=dato;)
		{
			ant=act;
			act=ant->sig;
		}
		if(act->dato.matri==dato && act!=NULL)
		{
			tmp=act;
			ant->sig=act->sig;
			free(tmp);
		}
	}
}
int busqueda(tipolista lista, int matri){
   if((lista.dato.matri)==matri){
      return 1;
    }
    else
    {
      if(lista.sig==NULL)
      {
         return 0;
       }
     busqueda(*(lista.sig),matri);
    }
}
void consulta(tipolista lista, int matri, int i){
   if(lista.dato.matri==matri){
      printf("El matricula= %d esta en la posicion %d\n", matri,i);
   }
   else
   {
      if(lista.sig==NULL)
      {
         printf("la matricula no se encuentra\n");
         return;
      }
      consulta(*(lista.sig),matri,i+1);
    }
}
void consulta2(tipolista lista, float prom, int i){
   if(lista.dato.prom==prom){
      printf("El promedio= %f esta en la posicion %d\n", prom,i);
      if(lista.sig==NULL)
      {
         return;
       }
       else
       {
         consulta2(*(lista.sig),prom,i+1);
        }
   }
   else
   {
      if(lista.sig==NULL)
      {
           return;
      }
      consulta2(*(lista.sig),prom,i+1);
    }
}
void consulta3(tipolista lista, char nombre[], int i){
   if(strcmp(lista.dato.nombre,nombre)==0){
      puts(nombre);
      printf("esta en la posicion %d\n", i);
   }
   else
   {
      if(lista.sig==NULL)
      {
         printf("el nombre no se encuentra\n");
         return;
      }
      consulta3(*(lista.sig),nombre,i+1);
    }
}
void imprimir(listaPtr lista){
	if(lista->sig==NULL)
	{
		puts(lista->dato.nombre);
		printf("La matricula es= %d", lista->dato.matri);
		printf("promedio= %f\n", lista->dato.prom);
		return;
	}
	else
	{
		puts(lista->dato.nombre);
		printf("La matricula es= %d\n" ,lista->dato.matri);
		printf("promedio= %f\n", lista->dato.prom);
		imprimir(lista->sig);
	}
}
void guardar(listaPtr lista){
   int i, c=0;
	FILE *arch2=fopen("lista.txt","wb");
   listaPtr tmp=lista;
   if(arch2==NULL)
   {
      printf("no se pudo escribir en el archivo");
    }
   while(tmp!=NULL)
   {
      c++;
      tmp=tmp->sig;
   }
   fwrite(&c,sizeof(int),1,arch2);

   for(i=0;i<c;i++)
   {
      fwrite(lista->dato.nombre,sizeof(char),20,arch2);
      fwrite(&lista->dato.matri,sizeof(int),1,arch2);
      fwrite(&lista->dato.prom,sizeof(float),1,arch2);
      lista=lista->sig;
     }
	fclose(arch2);
}
