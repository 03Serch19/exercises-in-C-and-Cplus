// archivo de cabecera ListaDoble.h 
#include "NodoDoble.h" 
class ListaDoble 
{ 
 protected: 
 NodoDoble* cabeza; 
 public: 
 ListaDoble() 
 { 
 cabeza = NULL; 
 } 
 void insertarCabezaLista(int entrada); 
 void insertaDespues (NodoDoble* anterior, int entrada); 
 void eliminar(int entrada); 
 void visualizar (); 
 NodoDoble* buscar(int ele); 
}; 
