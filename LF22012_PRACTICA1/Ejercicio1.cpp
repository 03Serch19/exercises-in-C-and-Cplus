#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define ASCENDENTE 1
#define DESCENDENTE 0
#define TRUE 1
#define FALSE 0

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
   struct _nodo *anterior;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

void Insertar(Lista *lista, int v);
void Borrar(Lista *lista, int v);
void BorrarLista(Lista *lista);
void MostrarLista(Lista lista, int orden);
pNodo getnodo(void);
pNodo buscar_nodo( Lista lista, int v, int *enc );

void Insertar(Lista *lista, int v)
{
   pNodo nuevo, actual;

   /* pedir un nodo nuevo */
   nuevo = getnodo();

   nuevo->valor = v;

   /* Colocamos actual en la primera posición de la lista */
   actual = *lista;
   if(actual) while(actual->anterior) actual = actual->anterior;

   /* Si la lista está vacía o el primer miembro es mayor que el nuevo*/
   if(!actual || actual->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = actual;
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
   else {
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga
	 un valor mayor que v */
      while(actual->siguiente && actual->siguiente->valor <= v)
	 actual = actual->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void Borrar(Lista *lista, int v)   {
   pNodo nodo;

   /* Buscar el nodo de valor v */
   nodo = *lista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   /* El valor v no está en la lista */
   if(!nodo || nodo->valor != v) return;

   /* Borrar el nodo */
   /* Si lista apunta al nodo que queremos borrar, apuntar a otro */
   if(nodo == *lista)
     if(nodo->anterior) *lista = nodo->anterior;
     else *lista = nodo->siguiente;

   if(nodo->anterior) /* no es el primer elemento */
      nodo->anterior->siguiente = nodo->siguiente;

   if(nodo->siguiente) /* no es el último nodo */
      nodo->siguiente->anterior = nodo->anterior;
   free(nodo);
}

void BorrarLista(Lista *lista)
{
   pNodo nodo, actual;

   actual = *lista;
   while(actual->anterior) actual = actual->anterior;

   while(actual) {
      nodo = actual;
      actual = actual->siguiente;
      free(nodo);
   }
   *lista = NULL;
}

void MostrarLista(Lista lista, int orden)
{
   pNodo nodo = lista;

   if(!lista) printf("Lista vacía");

   nodo = lista;
   if(orden == ASCENDENTE) {
      while(nodo->anterior) nodo = nodo->anterior;
      printf("Orden ascendente: ");
      while(nodo) {
	 printf("%d -> ", nodo->valor);
	 nodo = nodo->siguiente;
      }
   }
   else {
      while(nodo->siguiente) nodo = nodo->siguiente;
      printf("Orden descendente: ");
      while(nodo) {
	 printf("%d -> ", nodo->valor);
	 nodo = nodo->anterior;
      }
   }
   printf("\n");
}

pNodo getnodo(void) {
   pNodo nuevo;


   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   return nuevo;
}

pNodo buscar_nodo( Lista lista, int v, int *enc ) {
   pNodo nodo;

   /* Buscar el nodo de valor v */
   nodo = lista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   /* El valor v no está en la lista */
   if(!nodo || nodo->valor != v)
      *enc = FALSE;            /* devolver a través de enc si v fue encontrado en la lista */
   else
      *enc = TRUE ;

   /* devolver el apuntador al nodo */
   return nodo;
}
void InvertirYConcatenar(Lista *lista1, Lista lista2) {
    pNodo nodo = *lista1;

    if (!*lista1 || !lista2) {
        printf("Una de las listas es nula.\n");
        return;
    }

    while (nodo->siguiente) {
        nodo = nodo->siguiente;
    }

    nodo->siguiente = lista2;
    lista2->anterior = nodo;
    *lista1 = nodo;
    
}

int main() {
    Lista lista1 = NULL;
    Lista lista2 = NULL;

    // Llena las listas como desees
    Insertar(&lista1, 1);
    Insertar(&lista1, 2);
    Insertar(&lista1, 3);

    Insertar(&lista2, 4);
    Insertar(&lista2, 5);
    Insertar(&lista2, 6);

    printf("Lista 1 antes de invertir y concatenar:\n");
    MostrarLista(lista1, ASCENDENTE);
    printf("Lista 2:\n");
    MostrarLista(lista2, ASCENDENTE);

    InvertirYConcatenar(&lista1, lista2);

    printf("Lista resultante despues de invertir y concatenar:\n");
    MostrarLista(lista1, ASCENDENTE);

    // Libera la memoria de las listas si es necesario
    BorrarLista(&lista1);
    BorrarLista(&lista2);

    return 0;
}


