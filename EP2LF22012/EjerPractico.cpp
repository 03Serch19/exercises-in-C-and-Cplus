//Código:
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
void Borrar(Arbol *a, int dat);
int Vacio(Arbol r);
void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));
int NumeroNodos(Arbol a, int* c);
void auxContador(Arbol a, int*);
void Podar(Arbol *a);
void Mostrar(int *d);
int EsHoja(pNodo r);
void copiaMultiplo(Arbol original, Arbol *copia, int *suma, int *contador);
float promedio(int suma, int contador);
int main()
{	
 Arbol ArbolInt=NULL;
    Insertar(&ArbolInt, 10);
    Insertar(&ArbolInt, 7);
    Insertar(&ArbolInt, 15);
    Insertar(&ArbolInt, 3);
    Insertar(&ArbolInt, 12);

    printf("Arbol original (PreOrden): ");
    PreOrden(ArbolInt, Mostrar);
    printf("\n");

    Arbol ArbolCopia = NULL;
    int suma = 0, contador = 0;
    copiaMultiplo(ArbolInt, &ArbolCopia, &suma, &contador);

    printf("Arbol copia con multiplos de 5 (PreOrden): ");
    PreOrden(ArbolCopia, Mostrar);
    printf("\n");

    float promedioMultiplos = promedio(suma, contador);
    printf("Promedio de los nodos del arbol copia: %.2f\n", promedioMultiplos);

    // Liberar memoria de los árboles
    Podar(&ArbolInt);
    Podar(&ArbolCopia);
 return 0;
}
void copiaMultiplo(Arbol original, Arbol *copia, int *suma, int *contador) {
    if (!Vacio(original)) {
        if (original->dato % 5 == 0) {
            Insertar(copia, original->dato);
            *suma += original->dato;
            (*contador)++;
        }
        copiaMultiplo(original->izquierdo, copia, suma, contador);
        copiaMultiplo(original->derecho, copia, suma, contador);
    }
}

float promedio(int suma, int contador) {
    if (contador == 0) {
        return 0.0;
    }
    return (float)suma / contador;
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
/* Eliminar un elemento de un árbol ABB */
void Borrar(Arbol *a, int dat)
{
 pNodo padre = NULL;
 pNodo actual;
 pNodo nodo;
 int aux;
 actual = *a; 
  /* Mientras sea posible que el valor esté en el árbol */
 while(!Vacio(actual)) {
 if(dat == actual->dato) { /* Si el valor está en el nodo actual */
 if(EsHoja(actual)) { /* Y si además es un nodo hoja: lo borramos */
 if(padre) /* Si tiene padre (no es el nodo raiz) */
 /* Anulamos el puntero que le hace referencia */
 if(padre->derecho == actual) padre->derecho = NULL;
 else if(padre->izquierdo == actual) padre->izquierdo = NULL;
 free(actual); /* Borrar el nodo */
 actual = NULL;
 return;
 }
 else { /* Si el valor está en el nodo actual, pero no es hoja */
 padre = actual;
 /* Buscar nodo más izquierdo de rama derecha */
 if(actual->derecho) {
 nodo = actual->derecho;
 while(nodo->izquierdo) {
 padre = nodo;
 nodo = nodo->izquierdo;
 }
 }
 /* O buscar nodo más derecho de rama izquierda */
 else {
 nodo = actual->izquierdo;
 while(nodo->derecho) {
 padre = nodo;
 nodo = nodo->derecho;
 }
 }
/* Intercambiar valores de nodo a borrar u nodo encontrado y continuar,
cerrando el bucle. */
 aux = actual->dato;
 actual->dato = nodo->dato;
 nodo->dato = aux;
 actual = nodo;
 }
 }
 else { /* Todavía no hemos encontrado el valor, seguir buscándolo */
 padre = actual;
 if(dat > actual->dato) actual = actual->derecho;
 else if(dat < actual->dato) actual = actual->izquierdo;
 }
 }
} 
/*Recorrido en InOrden*/
void InOrden(Arbol a, void (*func)(int*))
{
 if(a->izquierdo) InOrden(a->izquierdo, func);
 func(&(a->dato));
 if(a->derecho) InOrden(a->derecho, func);
}
/*Recorrido en PreOrden*/
void PreOrden(Arbol a, void (*func)(int*))
{
 func(&a->dato);
 if(a->izquierdo) PreOrden(a->izquierdo, func);
 if(a->derecho) PreOrden(a->derecho, func);
}
/* Recorrido PostOrden */
void PostOrden(Arbol a, void (*func)(int*))
{
 if(a->izquierdo) PostOrden(a->izquierdo, func);
 if(a->derecho) PostOrden(a->derecho, func);
 func(&a->dato);
}
/*comprueba si el árbol es vacío*/
int Vacio(Arbol r)
{
 return r==NULL;
}
/*Función de prueba para los recorridos del árbol*/
void Mostrar(int *d)
{
 printf("%d, ", *d);
}
/* Contar el número de nodos */
int NumeroNodos(Arbol a, int *contador)
{
 *contador = 0;
 auxContador(a, contador); /* Función auxiliar */
 return *contador;
}
/* Función auxiliar para contar nodos. */
void auxContador(Arbol nodo, int *c)
{
 (*c)++; /* Otro nodo */
 /* Continuar recorrido */
 if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
 if(nodo->derecho) auxContador(nodo->derecho, c);
}
/* Comprobar si un nodo es hoja */
int EsHoja(pNodo r)
{
 return !r->derecho && !r->izquierdo;
} 
