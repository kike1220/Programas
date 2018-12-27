//Programa Operaciones con Arboles AVL//
//Curso: Estructura de Datos//
//Autor:Luis Enrique Reyes Martinez//
//Fecha:26 de Junio del 2017//
//Grupo:202-B//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct arbol{
	int dato;
	int altura,izq1,der1;
    struct arbol *izq;
    struct arbol *der;
}A;
typedef A *Aptr;
void altura(Aptr raiz);
void insertar(Aptr *raiz,int dato);
int sucesor(Aptr raiz);
int buscar(Aptr raiz,int dato);
void eliminar(Aptr *raiz,int dato);
void rotacion(Aptr *raiz);
void enorden(Aptr raiz);
void preorden(Aptr raiz);
void postorden(Aptr raiz);
int main(){
    Aptr raiz={NULL};
    int c=1,opc,opc2,dato,busq,i;
    while(c==1){
    	printf("Que es lo que desea hacer\n1.-Insertar un dato\n2.-Eliminar un dato\n3.-Imprimir\n4.-Salir\n");
        scanf("%d", &opc);
        switch(opc){
		    case 1:{       		 
			    printf("Introduce el dato que deseas insertar\n");
                scanf("%d", &dato);
                insertar(&raiz,dato);
                for(i=0;i<3;i++)
                {
                	rotacion(&raiz);
					altura(raiz);	
				}	
                system("pause");
        	    break;
            }
            case 2:{
            	printf("Introduce el dato que deseas eliminar\n");
                scanf("%d", &dato);
                busq=buscar(raiz,dato);
                if(busq==1){
                	eliminar(&raiz,dato);
                	for(i=0;i<3;i++)
                	{
                		rotacion(&raiz);
						altura(raiz);	
					}	
				}
				else{
					printf("El dato que deseas eliminar no se encuentra en el arbol\n");
				}
                system("pause");
                break;
            }
            case 3:{
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
            case 4:{
            	c=2;
                break;
            }
        }
        system("cls");
    }
    return 0;
}
void altura(Aptr raiz)
{
	Aptr der,izq;
	if(raiz!=NULL)
	{
		altura(raiz->izq);
		altura(raiz->der);
		if(raiz->der==NULL && raiz->izq==NULL)
		{
		     raiz->altura=0;
		     raiz->der1=0;
		     raiz->izq1=0;
		}
		else
		{
		    if(raiz->der!=NULL && raiz->izq!=NULL)
			{	
				izq=raiz->izq;
				if(izq->der1>izq->izq1)
				{
					raiz->izq1=izq->der1+1;
				}
				else
				{
					raiz->izq1=izq->izq1+1;
				}	
				der=raiz->der;
				if(der->der1>der->izq1)
				{
					raiz->der1=der->der1+1;
				}
				else
				{
					raiz->der1=der->izq1+1;
				}		
				raiz->altura=raiz->der1-raiz->izq1;
			}
			else
			{
				if(raiz->der==NULL && raiz->izq!=NULL)
				{
					izq=raiz->izq;
					if(izq->der1>izq->izq1)
					{
						raiz->izq1=izq->der1+1;
						raiz->der1=0;
						raiz->altura=raiz->der1-raiz->izq1;	
					}
					else
					{
						raiz->izq1=izq->izq1+1;
						raiz->der1=0;
						raiz->altura=raiz->der1-raiz->izq1;
					}					
				}
				else
				{
					der=raiz->der;
					if(der->der1>der->izq1)
					{
						raiz->der1=der->der1+1;
						raiz->izq1=0;
						raiz->altura=raiz->der1-raiz->izq1;	
					}
					else
					{
						raiz->der1=der->izq1+1;
						raiz->izq1=0;
						raiz->altura=raiz->der1-raiz->izq1;
					}
				}
				
			}    
		}
	}
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
     	nuevo->altura=0;
     	nuevo->der1=0;
     	nuevo->izq1=0;
        nuevo->izq=NULL;
        nuevo->der=NULL;
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
            }
        }
        altura(*raiz);
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
				if(ant->izq!=NULL)
				{
					if(ant->izq->dato==dato)
					{
						ant->izq=NULL;
					}
					else if(ant->der->dato==dato)
					{
						ant->der=NULL;
					}
				}
				else if(ant->der!=NULL)
				{
					if(ant->der->dato==dato)
					{
						ant->der=NULL;
					}
					else if(ant->izq->dato==dato)
					{
						ant->izq=NULL;
					}
				}
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
							*raiz=act->izq;
						}
						else
						{
							*raiz=act->der;
						}
					}
					else
					{
						if(ant->izq->dato==dato){
							if(act->der==NULL)
							{
								ant->izq=act->izq;
							}
							else
							{
								ant->izq=act->der;
							}
						}
						else{
							if(act->der==NULL)
							{
								ant->der=act->izq;
							}
							else
							{
								ant->der=act->der;
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
						}
					}
					free(act);
				}
			}
		  }
     }
     altura(*raiz);
}
void rotacion(Aptr *raiz){
	Aptr der,izq,n2;
	if((*raiz)!=NULL)
	{
		rotacion(&(*raiz)->izq);
		rotacion(&(*raiz)->der);
		altura(*raiz);
		if((*raiz)->altura==2 || (*raiz)->altura==-2)
		{
			der=(*raiz)->der;
			izq=(*raiz)->izq;
			if((*raiz)->der1>(*raiz)->izq1)
			{
				if(der->der1>der->izq1)
				{
					(*raiz)->der=der->izq;
					der->izq=*raiz;
					*raiz=der;					
				}
				else
				{ 
					n2=der->izq;
					der->izq=n2->der;
					n2->der=der;
					(*raiz)->der=n2->izq;
					n2->izq=*raiz;
					*raiz=n2;
				}
			}
			else
			{
				if(izq->der1>izq->izq1)
				{
					n2=izq->der;
					izq->der=n2->izq;
					n2->izq=izq;
					(*raiz)->izq=n2->der;
					n2->der=*raiz;
					*raiz=n2;				
				}
				else
				{
					(*raiz)->izq=izq->der;
					izq->der=*raiz;
					*raiz=izq;
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
        printf("   altura= %d\n",raiz->altura);
        enorden(raiz->der);
    }
}
void preorden(Aptr raiz){
	if(raiz==NULL){
    	return;
    }
    else{
		printf("%3d",raiz->dato);
		printf("   altura= %d\n",raiz->altura);
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
        printf("   altura= %d\n",raiz->altura);
    }
}
