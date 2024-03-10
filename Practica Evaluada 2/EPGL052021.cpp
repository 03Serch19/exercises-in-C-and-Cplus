#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
/* Estructuras y tipos */
typedef struct _nodo {
	  int dato;
	  struct _nodo* derecho;
	  struct _nodo* izquierdo;
} tipoNodo;
typedef tipoNodo* pNodo;
typedef tipoNodo* Arbol;
void Insertar(Arbol* a, int dat);
int Vacio(Arbol r);
void InOrden(Arbol, void (*func)(int*));
void Podar(Arbol* a);
void Mostrar(int* d);
void multiNodos(Arbol);
void PreOrden(Arbol, void (*func)(int*));
int main()
{
	  Arbol ArbolInt = NULL;
	  Insertar(&ArbolInt, 7);
	  Insertar(&ArbolInt, 35);
	  Insertar(&ArbolInt, 5);
	  Insertar(&ArbolInt, 0);
	  Insertar(&ArbolInt, 1);
	  Insertar(&ArbolInt, 14);
	  printf("Arbol recorrido en PreOrden: ");
	  PreOrden(ArbolInt, Mostrar);
	  printf("\n\n");
	  multiNodos(ArbolInt);
	  printf("Arbol modificado recorrido en PreOrden: ");
	  PreOrden(ArbolInt, Mostrar);
	  return 0;
}
/* Poda: borrar todos los nodos a partir de uno, incluido */
void Podar(Arbol* a)
{
	  /* Algoritmo recursivo, recorrido en postorden */
	  if (*a) {
			Podar(&(*a)->izquierdo); /* Podar izquierdo */
			Podar(&(*a)->derecho); /* Podar derecho */
			free(*a); /* Eliminar nodo */
			*a = NULL;
	  }
}
/* Insertar un dato en el árbol ABB */
void Insertar(Arbol* a, int dat)
{
	  pNodo padre = NULL;
	  pNodo actual = *a;
	  /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
	  while (!Vacio(actual) && dat != actual->dato) {
			padre = actual;
			if (dat < actual->dato) actual = actual->izquierdo;
			else if (dat > actual->dato) actual = actual->derecho;
	  }
	  /* Si se ha encontrado el elemento, regresar sin insertar */
	  if (!Vacio(actual)) return;
	  /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
	  el nodo raiz */
	  if (Vacio(padre)) {
			*a = (Arbol)malloc(sizeof(tipoNodo));
			(*a)->dato = dat;
			(*a)->izquierdo = (*a)->derecho = NULL;
	  }
	  /* Si el dato es menor que el que contiene el nodo padre, lo insertamos en la rama
	  izquierda */
	  else if (dat < padre->dato) {
			actual = (Arbol)malloc(sizeof(tipoNodo));
			padre->izquierdo = actual;
			actual->dato = dat;
			actual->izquierdo = actual->derecho = NULL;
	  }
	  /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos en la rama
	  derecha */
	  else if (dat > padre->dato) {
			actual = (Arbol)malloc(sizeof(tipoNodo));
			padre->derecho = actual;
			actual->dato = dat;
			actual->izquierdo = actual->derecho = NULL;
	  }
}
void InOrden(Arbol a, void (*func)(int*))
{
	  if (a->izquierdo) InOrden(a->izquierdo, func);
	  func(&(a->dato));
	  if (a->derecho) InOrden(a->derecho, func);
}
int Vacio(Arbol r)
{
	  return r == NULL;
}
void Mostrar(int* d)
{
	  printf("%d, ", *d);
}

void PreOrden(Arbol a, void (*func)(int*))
{
	  if (a == NULL)
	  {
			return;
	  }
	  else
	  {
			func(&(a->dato));
			if (a->izquierdo) InOrden(a->izquierdo, func);
			if (a->derecho) InOrden(a->derecho, func);
	  }
}
void multiNodos(Arbol arbol)
{
	  if (arbol == NULL)
	  {
			return;
	  }
	  else
	  {
			if ((arbol->dato % 7) == 0)
			{
				  arbol->dato = arbol->dato * 5;
			}
			multiNodos(arbol->izquierdo);
			multiNodos(arbol->derecho);
	  }
}