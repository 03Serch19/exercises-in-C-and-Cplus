#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
/* Estructuras y tipos */
	typedef struct _nodo {
 		int dato;
 		struct _nodo *derecho;
 		struct _nodo *izquierdo;
	} tipoNodo;

	typedef tipoNodo *pNodo;
	typedef tipoNodo *Arbol;
	
	void Insertar(Arbol *a, int dat);
	int Vacio(Arbol r);
	void InOrden(Arbol);
	void Podar(Arbol *a);
	int ModiNodo(Arbol, int);

 int main(){
	 Arbol ArbolInt=NULL;
	 int suma = 0;
	 Insertar(&ArbolInt, 55);
	 Insertar(&ArbolInt, 120);
	 Insertar(&ArbolInt, 4);
	 Insertar(&ArbolInt, 32);
	 Insertar(&ArbolInt, 95);
	 printf("Los nodos del arbol Binario en InOrden son:\n");
	 InOrden(ArbolInt);
	 suma = ModiNodo(ArbolInt, suma);
	 printf("\nEl resultado de la Funcion ModiNodo es: %i", suma);
	 getch();
	 return 0;
}

/* Poda: borrar todos los nodos a partir de uno, incluido */
void Podar(Arbol *a)
{
 /* Algoritmo recursivo, recorrido en postorden */
 if(*a) {
 Podar(&(*a)->izquierdo); /* Podar izquierdo */
 Podar(&(*a)->derecho); /* Podar derecho */
 free(*a); /* Eliminar nodo */
 *a = NULL;
 }
}
/* Insertar un dato en el árbol ABB */
void Insertar(Arbol *a, int dat)
{
 pNodo padre = NULL;
 pNodo actual = *a;
/* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
 while(!Vacio(actual) && dat != actual->dato) {
 padre = actual;
 if(dat < actual->dato) actual = actual->izquierdo;
 else if(dat > actual->dato) actual = actual->derecho;
 }
/* Si se ha encontrado el elemento, regresar sin insertar */
 if(!Vacio(actual)) return;
 /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
 el nodo raiz */
 if(Vacio(padre)) {
 *a = (Arbol)malloc(sizeof(tipoNodo));
 (*a)->dato = dat;
 (*a)->izquierdo = (*a)->derecho = NULL;
 }
/* Si el dato es menor que el que contiene el nodo padre, lo insertamos en la rama 
izquierda */
 else if(dat < padre->dato) {
 actual = (Arbol)malloc(sizeof(tipoNodo));
 padre->izquierdo = actual;
 actual->dato = dat;
 actual->izquierdo = actual->derecho = NULL;
 }
/* Si el dato es mayor que el que contiene el nodo padre, lo insertamos en la rama 
derecha */
 else if(dat > padre->dato) {
 actual = (Arbol)malloc(sizeof(tipoNodo));
 padre->derecho = actual;
 actual->dato = dat;
 actual->izquierdo = actual->derecho = NULL;
 }
}

void InOrden(Arbol a)
{
 if(a->izquierdo) InOrden(a->izquierdo);
 printf("[%i] ", a->dato);
 if(a->derecho) InOrden(a->derecho);
}

int Vacio(Arbol r)
{
 return r==NULL;
}

int ModiNodo(Arbol arbol, int sum){
	if(arbol->izquierdo) sum = ModiNodo(arbol->izquierdo, sum);
	if(arbol->dato > 3 && arbol->dato < 98) sum += arbol->dato + 25;
	if(arbol->derecho) sum = ModiNodo(arbol->derecho, sum);
	return sum;
}



