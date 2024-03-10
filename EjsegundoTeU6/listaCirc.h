/*listaCirc.h*/ 
typedef struct _nodo { 
 int valor; 
 struct _nodo *siguiente; 
 struct _nodo *anterior; 
} tipoNodo; 
typedef tipoNodo * pNodo; 
typedef tipoNodo * Lista; 
//prototipos de funciones 
Lista Crear(); 
pNodo Primero(Lista); 
void Destruir(Lista); 
void Insertar(int, pNodo, Lista); 
pNodo Fin(Lista); 
int elemento(pNodo, Lista); 
void Borrar(pNodo*, Lista); 
pNodo siguiente(pNodo, Lista); 
pNodo anterior(pNodo, Lista); 
pNodo posicion(int, Lista); 
