//Programa Operaciones con Arboles Binarios//
//Curso: Estructura de Datos//
//Autor:Luis Enrique Reyes Martinez//
//Fecha:12 de Junio del 2017//
//Grupo:202-B//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct arbol{
	int dato;
    struct arbol *p;
    struct arbol *izq;
    struct arbol *der;
}A;
typedef A *Aptr;
void insertar(Aptr *raiz,int dato);
void eliminar(Aptr *raiz,int dato);
int buscar(Aptr raiz,int dato);
void minimo(Aptr raiz);
void maximo(Aptr raiz);
int predecesor(Aptr raiz);
int sucesor(Aptr raiz);
void enorden(Aptr raiz);
void preorden(Aptr raiz);
void postorden(Aptr raiz);
int main(){
    Aptr raiz={NULL};
    int c=1,opc,opc2,dato,busq,pre,suc;
    while(c==1){
    	printf("Que es lo que desea hacer\n1.-Insertar un dato\n2.-Eliminar un dato\n3.-Buscar un dato\n4.-Minimo\n5.-Maximo\n6.-Predecesor\n7.-Sucesor\n8.-Imprimir\n9.-Salir\n");
        scanf("%d", &opc);
        switch(opc){
		    case 1:{       		 
			    printf("Introduce el dato que deseas insertar\n");
                scanf("%d", &dato);
                insertar(&raiz,dato);
                system("pause");
        	    break;
            }
            case 2:{
            	printf("Introduce el dato que deseas eliminar\n");
                scanf("%d", &dato);
                busq=buscar(raiz,dato);
                if(busq==1){
                	eliminar(&raiz,dato);	
				}
				else{
					printf("El dato que deseas eliminar no se encuentra en el arbol\n");
				}
                system("pause");
                break;
            }
            case 3:{
            	printf("Introduce el dato que deseas buscar\n");
            	scanf("%d", &dato);
            	busq=buscar(raiz,dato);
            	if(busq==1)
            	{
            		printf("El dato %d si se encuentra en el arbol\n");
				}
				else{
					printf("El dato que estas buscando no se encuentra en el arbol\n");
				}
            	system("pause");
				break;
			}
			case 4:{
				if(raiz==NULL)
				{
					printf("No hay elementos en el arbol\n");
				}
				else{
					minimo(raiz);	
				}
				system("pause");
				break;
			}
			case 5:{
				if(raiz==NULL)
				{
					printf("No hay elementos en el arbol\n");
				}
				else{
					maximo(raiz);	
				}
				system("pause");
				break;
			}
			case 6:{
				if(raiz==NULL){
					printf("No hay elementos en el arbol\n");
				}
				else
				{
					if(raiz->der==NULL || raiz->izq==NULL)
					{
						printf("No hay predecesor\n");
					}
					else
					{
						pre=predecesor(raiz);
						printf("El predecesor es: %d\n", pre);
					}
				}
				system("pause");
				break;
			}
			case 7:{
				if(raiz==NULL){
					printf("No hay elementos en el arbol\n");
				}
				else
				{
					if(raiz->der==NULL || raiz->izq==NULL)
					{
						printf("No hay sucesor \n");
					}
					else
					{
						suc=sucesor(raiz);
						printf("El sucesor es: %d\n",suc);	
					}
				}
				system("pause");
				break;
			}
            case 8:{
            	printf("Que tipo de impresion deseas hacer\n1.-En orden\n2.-En preorden\n3.-En postorden\n");
            	scanf("%d", &opc2);
                switch(opc2){
            	    case 1:{
            	    	if(raiz==NULL){
            	    		printf("No hay elementos en el arbol\n");
						}
						else{
							enorden(raiz);
							printf("\n");
						}
                        break;
                    }
                    case 2:{
                    	if(raiz==NULL){
            	    		printf("No hay elementos en el arbol\n");
						}
						else{
							preorden(raiz);
							printf("\n");
						}
                	    break;
                    }
                    case 3:{
                    	if(raiz==NULL){
            	    		printf("No hay elementos en el arbol\n");
						}
						else{
							postorden(raiz);
                	    	printf("\n");
						}
                	    break;
                    }                                            
                }
                system("pause");
                break;
            }
            case 9:{
            	c=2;
                break;
            }
        }
        system("cls");
    }
    return 0;
}
void insertar(Aptr *raiz,int dato){
     Aptr nuevo,ant,act;
     nuevo=(Aptr)malloc(sizeof(A));
     if(!nuevo)
     {
     	printf("No hay memoria\n");
     }
     else{
     	nuevo->dato=dato;
        nuevo->izq=NULL;
        nuevo->der=NULL;
        nuevo->p=NULL;
        if(*raiz==NULL)
     	   *raiz=nuevo;
        else{
       		ant=*raiz;
            act=*raiz;
            while(act!=NULL && dato!=ant->dato)
            {
        	    ant=act;
                if(dato<ant->dato)
        	        act=act->izq;
                else
        	        act=act->der;
            }
            if(dato==ant->dato)
        	    printf("El dato ya existe\n");
            else{
        	    if(dato<ant->dato){
            	    ant->izq=nuevo;
                }
                else{
               		ant->der=nuevo;
                }
                nuevo->p=ant;
            }
        }
     }
}
int buscar(A *raiz,int dato){
    int band=0;
    while(raiz!=NULL && band==0){
		if(raiz->dato==dato){
        	 band=1;
        }
        else{
        	if(raiz->dato>dato)
        		raiz=raiz->izq;
        	else
				raiz=raiz->der;    
        }
    }
    return band;
}
void minimo(Aptr raiz){
	while(raiz->izq!=NULL){
		raiz=raiz->izq;
	}
	printf("El minimo es: %d\n", raiz->dato);
}
void maximo(Aptr raiz){
	while(raiz->der!=NULL){
		raiz=raiz->der;
	}
	printf("El maximo es: %d\n", raiz->dato);
}
int predecesor(Aptr raiz){
	raiz=raiz->izq;
	while(raiz->der!=NULL)
	{
		raiz=raiz->der;
	}
	return raiz->dato;
}
int sucesor(Aptr raiz)
{
	raiz=raiz->der;
	while(raiz->izq!=NULL)
	{
		raiz=raiz->izq;
	}
	return raiz->dato;	
}
void eliminar(Aptr *raiz,int dato){
     Aptr ant,act;
     int suce;
     if(*raiz==NULL)
     {
          printf("El arbol esta vacio\n");
     }
     else{
          if((*raiz)->izq==NULL && (*raiz)->der==NULL)
          {
        	  act=*raiz;
              *raiz=NULL;
              free(act);
          }
          else
		  {
        	ant=NULL;
          	act=*raiz;
          	while(act!=NULL && act->dato!=dato)
          	{
          		ant=act;
          		if(dato>act->dato)
					act=act->der;
				else
					act=act->izq;	
			}
			if(act->der==NULL && act->izq==NULL)
			{
				if(ant->izq->dato==dato)
					ant->izq=NULL;
				else
					ant->der=NULL;
				free(act);			
			}
			else
			{
				if((act->izq!=NULL && act->der==NULL) || (act->izq==NULL && act->der!=NULL))
				{
					if(act->dato==(*raiz)->dato)
					{
						if(act->der==NULL)
						{
							act->izq->p=NULL;
							*raiz=act->izq;
						}
						else
						{
							act->der->p=NULL;
							*raiz=act->der;
						}
					}
					else
					{
						if(ant->izq->dato==dato){
							if(act->der==NULL)
							{
								ant->izq=act->izq;
								act->izq->p=ant;
							}
							else
							{
								ant->izq=act->der;
								act->der->p=ant;
							}
						}
						else{
							if(act->der==NULL)
							{
								ant->der=act->izq;
								act->izq->p=ant;
							}
							else
							{
								ant->der=act->der;
								act->der->p=ant;
							}
						}
					}
					free(act);
				}
				else{
					suce=sucesor(act);
					act->dato=suce;
					ant=act;
					act=act->der;
					while(act!=NULL && act->dato!=suce)
					{
						ant=act;
						act=act->izq;
					}
					if(ant->dato==act->dato)
					{
						ant->der=act->der;
					}
					else
					{
						ant->izq=act->der;
						if(act->der!=NULL)
						{
							act->der->p=ant;
						}	
					}
					free(act);
				}
			}
		  }
     }
}
void enorden(Aptr raiz){
	if(raiz==NULL){
    	return;
	}
    else{
    	enorden(raiz->izq);
        printf("%3d",raiz->dato);
        enorden(raiz->der);
    }
}
void preorden(Aptr raiz){
	if(raiz==NULL){
    	return;
    }
    else{
		printf("%3d",raiz->dato);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}
void postorden(Aptr raiz){
	if(raiz==NULL){
    	return; 	
	}
	else
	{
		postorden(raiz->izq);
        postorden(raiz->der);
        printf("%3d",raiz->dato);
    }
}
