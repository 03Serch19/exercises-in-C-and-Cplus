/*Implementacion de cola lineal con memoria dinámica */ 
#define CIERTO 1 
#define FALSO 0 
#define NULO 0 
typedef struct{ 
 char SeguroSocial[10]; 
 char Entidad[40]; 
 }TipoDato; 
struct Nodoq{ 
 TipoDato Info; 
 struct Nodoq * Sgte; 
 }; 
typedef struct Nodoq * Ptrnodoq;
typedef struct{ 
 Ptrnodoq Frente, 
 Final; 
 }TipoCola; 
 void freenode(Ptrnodoq); 
 Ptrnodoq getnode(void); 
 void LimpiarCola(TipoCola *); 
 int ColaVacia(TipoCola ); 
 void Quitar(TipoDato *, TipoCola *); 
 void Poner(TipoDato , TipoCola *); 
