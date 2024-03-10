/*Implementacion de una lista enlazada lineal ordenada */ 
#define CIERTO 1 
#define FALSO 0 
#define NULO 0 
typedef struct{ 
 char ISSS[10]; 
 char Nombre[41]; 
 int DiasTrabajados; 
 }TipoInfo; 
struct Nodo{ 
 TipoInfo Info; 
 struct Nodo * Sgte; 
 }; 
typedef struct Nodo * ApuntaNodo; 
 void LimpiarLista(ApuntaNodo *); 
 int ListaVacia(ApuntaNodo); 
 ApuntaNodo PostInsert(TipoInfo, ApuntaNodo ); 
 void InserOrden(TipoInfo , ApuntaNodo *); 
 void Suprimir(TipoInfo * , ApuntaNodo *);
