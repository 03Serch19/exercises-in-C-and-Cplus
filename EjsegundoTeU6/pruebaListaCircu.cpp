#include <iostream> //no es c++
//#include <stdio.h>
#include "listaCirc.h"
int main(){ 
 Lista listc; 
 pNodo p; 
 int x; 
 //se crea la lista circular 
 listc=Crear(); 
 //obtengo el apuntador al primer nodo 
 p=Primero(listc);
 //introduzco un elemento a la izquierda del final 
 Insertar(10,p,listc); 
 Insertar(20,p->siguiente,listc); 
 Insertar(30,p->siguiente,listc); 
 Insertar(40,p->siguiente,listc); 
 p=listc; 
 //imprimir el valor en p 
 while (p->siguiente != listc) 
 { 
 printf("%d ", p->siguiente->valor); 
 p = p->siguiente; 
 } 
 
 return 0; 
} 
/*#include <iostream> 
#include "listaCirc.h"
using namespace std; 

int main() { 
    Lista listc; 
    pNodo p; 

    // Crear la lista circular
    listc = Crear(); 
    // Obtener el apuntador al primer nodo 
    p = Primero(listc);

    // Insertar elementos a la izquierda del final
    Insertar(10, p, listc); 
    Insertar(20, p->siguiente, listc); 
    Insertar(30, p->siguiente, listc); 
    Insertar(40, p->siguiente, listc); 
    p = listc; 

    // Imprimir el valor en p 
    while (p->siguiente != listc) { 
        std::cout << p->siguiente->valor << " "; 
        p = p->siguiente; 
    }

    return 0; 
}*/

