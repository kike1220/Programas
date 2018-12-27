#include <stdio.h>
#include <string.h>
typedef struct Arbol{
        int dato;
        int alt;
        struct arbol *izq;
        struct arbol *der;
        struct arbol *p;
}AVL;
typedef AVL *AVLptr;
int altura(AVLptr raiz);
void insertar(AVLptr *raiz,int dato);
void enorden(AVLptr raiz);
void preorden(AVLptr raiz);
void postorden(AVLptr raiz);
int main(){
    AVLptr raiz={NULL};
    int dato,c=1,opc,opc2;
    while(c==1){
                printf("Que es lo que deseas hacer\n1.-Insertar un dato\n2.-Eliminar un dato\n3.-Imprimir\n4.-Salir\n");
                scanf("%d", &opc);
                switch(opc){
                            case 1:{
                                 break;
                            }
                            case 2:{
                                 break;
                            }
                            case 3:{
                                 printf("Que tipo de impresion deseas hacer\n1.-En orden\n2.-En preorden\n3.-En postorden\n");
                                 scanf("%d", &opc2);
                                 switch(opc2){
                                              case 1:{
                                                   enorden(raiz);
                                                   printf("\n");
                                                   break;
                                              }
                                              case 2:{
                                                   preorden(raiz);
                                                   printf("\n");
                                                   break;
                                              }
                                              case 3:{
                                                   postorden(raiz);
                                                   printf("\n");
                                                   break;
                                              }
                                 }
                                 break;
                            }
                            case 4:{
                                 c=2;
                                 break;
                            }
                }
    }
    return 0;    
}
int altura(AVLptr raiz)
{
    AVLptr izq,der;
    int izq1=0,der1=0,alt=0;
}
void insertar(AVLptr *raiz,int dato){
     AVLptr act,ant,nuevo;
     int alt;
     nuevo=(AVLptr)malloc(sizeof(AVL));
     if(!nuevo)
        printf("No hay memoria");
     else{
          nuevo->dato=dato;
          nuevo->alt=0;
          nuevo->izq=NULL;
          nuevo->der=NULL;
          nuevo->p=NULL;
          if(*raiz==NULL)
             *raiz=nuevo;
          else{
               act=*raiz;
               ant=NULL;
               while(act!=NULL && act->dato!=dato){
                   ant=act;             
                   if(dato<act->dato)
                       act=act->izq;
                   else
                        act=act->der;
               }
               if(act->dato==dato){
                    printf("El dato que deseas insertar ya se encuentra en el arbol");
               }
               if(act==NULL){
                  if(ant->dato>dato)
                      ant->izq=nuevo;
                      alt=(ant);
                  else
                       ant->der=nuevo;
               }
               else
               {
               }
               
          }
     }
}
void enorden(AVLptr raiz){
	if(raiz==NULL){
    	return;
	}
    else{
    	enorden(raiz->izq);
        printf("%3d",raiz->dato);
        enorden(raiz->der);
    }
}
void preorden(AVLptr raiz){
	if(raiz==NULL){
    	return;
    }
    else{
		printf("%3d",raiz->dato);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}
void postorden(AVLptr raiz){
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
