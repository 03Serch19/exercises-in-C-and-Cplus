#include <stdlib.h> //por malloc() 
#include <stdio.h> //por printf() 
#include "listaCirc.h" 
Lista Crear(){ 
 Lista l; 
 l = (Lista)malloc(sizeof(tipoNodo)); 
 if (!l){ 
 printf("Error: Memoria insuficiente\n"); 
 exit(1); 
 } 
 l->siguiente = l->anterior = l; 
 return l; 
} 
//devuelve un apuntador al primer nodo de la lista el cual es 
//el nodo despues de la cabecera 
pNodo Primero(Lista l){ 
 return l->siguiente; 
}
//libera la memoria de todos los nodos de la lista 
void Destruir(Lista l){ 
 pNodo p; 
 for (p=l, l->anterior->siguiente=NULL;l != NULL; p=l){ 
 l = l->siguiente; 
 free(p); 
 } 
} 
//inserta el nuevo nodo a la izquierda (antes) de p 
void Insertar(int x, pNodo p, Lista l){ 
 pNodo nuevo; 
 
 nuevo = (pNodo)malloc(sizeof(tipoNodo)); 
 if (!nuevo){ 
 printf("Error: Memoria insuficiente\n"); 
 exit(1); 
 } 
 nuevo->valor=x; 
 nuevo->siguiente = p; 
 nuevo->anterior = p->anterior; 
 printf("insertando el valor %d \n",x); 
 p->anterior->siguiente = nuevo; 
 p->anterior = nuevo; 
} 
//devuelve un puntero al nodo cabecera 
pNodo Fin(Lista l){ 
 return l; 
} 
//devuelve el valor del nodo p 
int elemento(pNodo p, Lista l){ 
 if (p==l){ 
 printf("Posicion Fin. Nodo cabecera\n"); 
 exit(1); 
 } 
 return p->valor; 
} 
void Borrar(pNodo* p, Lista l){ 
 pNodo q; 
 if (*p==l) 
 { 
 printf("Posicion Fin. Nodo cabecera\n"); 
 exit(1); 
 } 
 q = (*p)->siguiente; 
 (*p)->anterior->siguiente = q; 
 q->anterior = (*p)->anterior; 
free(*p); 
 (*p)=q; 
} 
pNodo siguiente (pNodo p, Lista l){ 
 if (p==l) 
 { 
 printf("Posicion Fin. Nodo cabecera\n"); 
 exit(1); 
 } 
 return p->siguiente; 
} 
pNodo anterior (pNodo p, Lista l){ 
 if (p==l->siguiente) 
 { 
 printf("Posicion primero(l)\n"); 
 exit(1); 
 } 
 return p->anterior; 
} 
pNodo posicion (int x, Lista l){ 
 pNodo p; 
 int encontrado; 
 
 p=Primero(l); 
 encontrado=0; 
 while ((p != Fin(l)) && (!encontrado)) 
 if (p->valor == x) 
 encontrado = 1; 
 else 
 p = p->siguiente; 
 return p; 
} 

