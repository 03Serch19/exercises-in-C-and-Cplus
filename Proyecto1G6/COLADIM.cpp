/* COLAS.C */ 
#include "coladim.h" 
#include <conio.h> 
#include <stdio.h> 
# include <stdlib.h>//se agrego xd
void freenode(Ptrnodoq p) 
{ 
 free(p); 
} 
Ptrnodoq getnode(void) 
{ 
 Ptrnodoq p; 
 p=(Ptrnodoq)malloc(sizeof(struct Nodoq)); 
 return(p); 
} 
void LimpiarCola(TipoCola * pq) 
{ 
 pq->Frente=NULO; 
 pq->Final=NULO; 
} 
int ColaVacia(TipoCola q) 
{ 
 return((q.Frente == NULO)? CIERTO: FALSO); 
} 
void Poner(TipoDato x , TipoCola * pq) 
{ 
 Ptrnodoq T; 
 T=getnode(); 
 T->Info=x; 
 T->Sgte=NULO; 
 if (ColaVacia(*pq)) 
 pq->Frente=T; 
 else 
 (pq->Final)->Sgte=T; 
 pq->Final=T; 
} 
void Quitar(TipoDato * px, TipoCola * pq ) 
{ 
 Ptrnodoq A; 
 if (!ColaVacia(*pq)) 
 { *px=(pq->Frente)->Info; 
 A=pq->Frente; 
pq->Frente=(pq->Frente)->Sgte; 
 if (pq->Frente==NULO) 
 pq->Final=NULO; 
 freenode(A); 
 } 
} 
