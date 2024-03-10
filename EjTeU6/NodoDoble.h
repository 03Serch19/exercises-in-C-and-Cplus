// archivo de cabecera NodoDoble.h 
#include <iostream> 
typedef int Dato; 
class NodoDoble 
{ 
 protected: 
 Dato dato; 
 NodoDoble* adelante; 
 NodoDoble* atras; 
 public: 
 NodoDoble(Dato t) 
 { 
 dato = t; 
 adelante = atras = NULL; 
 } 
 
 Dato datoNodo() const { return dato;} 
 NodoDoble* adelanteNodo() const { return adelante;} 
 NodoDoble* atrasNodo() const { return atras; } 
void ponerAdelante(NodoDoble* a) { adelante = a; } 
 void ponerAtras(NodoDoble* a) { atras = a; } 
}; 
