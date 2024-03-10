#include <iostream> 
#include "ListaDoble.h" 
void ListaDoble::insertarCabezaLista(int entrada) 
{ 
 NodoDoble* nuevo; 
 nuevo = new NodoDoble (entrada); 
 nuevo -> ponerAdelante(cabeza); 
 if (cabeza != NULL ) 
 cabeza -> ponerAtras(nuevo); 
 cabeza = nuevo; 
} 
void ListaDoble::insertaDespues (NodoDoble* anterior, int entrada) 
{ 
 NodoDoble* nuevo; 
 nuevo = new NodoDoble(entrada); 
 nuevo -> ponerAdelante(anterior -> adelanteNodo()); 
 if (anterior -> adelanteNodo() != NULL) 
 anterior -> adelanteNodo() -> ponerAtras(nuevo); 
 anterior-> ponerAdelante(nuevo); 
 nuevo -> ponerAtras(anterior); 
} 
void ListaDoble::eliminar (int entrada) 
{ 
 NodoDoble* actual; 
 bool encontrado = false; 
 actual = cabeza; 
 // Bucle de búsqueda 
 while ((actual != NULL) && (!encontrado)) 
 { 
 encontrado = (actual -> datoNodo() == entrada); 
 if (!encontrado) 
 actual = actual -> adelanteNodo(); 
 } 
 // Enlace de nodo anterior con el siguiente 
 if (actual != NULL) 
 { 
 //distingue entre nodo cabecera o resto de la lista 
 if (actual == cabeza) 
 { 
 cabeza = actual -> adelanteNodo(); 
 if (actual -> adelanteNodo() != NULL) 
 actual -> adelanteNodo() -> ponerAtras(NULL); 
 } 
 else if (actual -> adelanteNodo() != NULL) // No es el último 
 { 
 actual->atrasNodo()->ponerAdelante(actual->adelanteNodo()); 
 actual->adelanteNodo()->ponerAtras(actual->atrasNodo()); 
 } 
 else // último nodo 
 actual->atrasNodo()->ponerAdelante(NULL); 
 } 
} 
void ListaDoble::visualizar() 
{ 
 NodoDoble* n; 
 int k = 0; 
 n = cabeza; 
 while (n != NULL) 
 { 
 char c; 
 k++; c = (k % 15 != 0 ? ' ' : '\n'); 
 std::cout << n -> datoNodo() << c; 
 n = n -> adelanteNodo(); 
 } 
} 
NodoDoble* ListaDoble::buscar(int ele) 
{ 
NodoDoble* n; 
 bool encontrado = false; 
 NodoDoble* b = NULL; 
 n = cabeza; 
 while ((n != NULL) && (!encontrado)) 
 { 
 if (n -> datoNodo() == ele ) 
 { 
 encontrado = true; 
 b=n; 
 } 
 if (!encontrado) 
 n = n -> adelanteNodo(); 
 } 
 return b; 
} 

