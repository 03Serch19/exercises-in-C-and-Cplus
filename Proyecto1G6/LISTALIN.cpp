/* LISTALIN.C */ 
#include "listalin.h" 
#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
# include <string.h>//se agrego xd
void LimpiarLista(ApuntaNodo * pl) 
{ 
 *pl=NULO; 
} 
int ListaVacia(ApuntaNodo l) 
{ 
 return((l == NULO)? CIERTO: FALSO); 
} 
ApuntaNodo PostInsert(TipoInfo x, ApuntaNodo l) 
{ 
 ApuntaNodo T; 
 T=NULO; 
 
if (!ListaVacia(l)){ 
 while ((strcmp(x.ISSS, l->Info.ISSS)>=0) && (l->Sgte!= NULO)){ 
 T=l; 
 l=l->Sgte; 
 } 
 if (strcmp(x.ISSS,l->Info.ISSS)>=0) 
 T=l; 
 } 
 return(T); 
} 
void InserOrden(TipoInfo x , ApuntaNodo * pl) 
{ 
 ApuntaNodo A,N; 
 N=(ApuntaNodo) malloc (sizeof(struct Nodo)); 
 N->Info=x; 
 N->Sgte=NULO; 
 if (ListaVacia(*pl)) 
 *pl=N; 
 else{ 
 A=PostInsert(x,*pl); 
 if (A==NULO){ 
 N->Sgte=*pl; 
 *pl=N; 
 } 
 else{ 
 N->Sgte=A->Sgte; 
 A->Sgte=N; 
 } 
 } 
} 
void Suprimir(TipoInfo * px, ApuntaNodo *pl) 
{ 
 ApuntaNodo A; 
 if (! ListaVacia(*pl)){ 
 A=*pl; 
 *px=A->Info; 
 *pl=A->Sgte; 
 free(A); 
 } 
} 

