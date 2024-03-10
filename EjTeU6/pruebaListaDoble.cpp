#include <iostream> 
#include "ListaDoble.h" 
using namespace std; 
int main() 
{ 
 int dato; 
 NodoDoble *a; 
 
 ListaDoble cc= ListaDoble(); 
 cc.insertarCabezaLista(1); 
 cc.insertarCabezaLista(2); 
 cc.insertarCabezaLista(3); 
 cout << endl; 
 cc.visualizar(); 
 a=cc.buscar(2); 
 if (a != NULL) 
 cc.insertaDespues(a,6); 
 cout << endl; 
 cc.visualizar(); 
 cc.eliminar(1); 
 cout << endl; 
 cc.visualizar(); 
 cc.insertarCabezaLista(4); 
 cout << endl; 
 cc.visualizar(); 
 return 0; 
}

