#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef int TipoElemento ;
struct _nodocola {
 TipoElemento e ;
 struct _nodocola *sig ;
 } ;
typedef struct _nodocola NodoCola ;
typedef struct {
NodoCola *Frente, *Final ;
} Cola ;
void VaciaC(Cola *C) ;
void AnadeC(Cola *C, TipoElemento e) ;
void BorraC(Cola *C) ;
TipoElemento PrimeroC(Cola C) ;
int EsVaciaC(Cola C) ;
void MostrarCola(Cola *C) ;


/*void*/int main() 
{
 Cola C ;
 int n, n1, n2, n3, i ;
 srand(500);
//  srand(499);
 n = 1 + rand() ;
 VaciaC(&C);
 
 for(i=1; i<=n ; i++ )
 AnadeC(&C, 1+rand()) ;
 n1 = 3 ;
 while (n1 <= n) {
 printf("\n Se quitan elementos a distancia %d ", n1) ;
 n2 = 0 ; // Contador de elementos que quedan
 for (i=1; i <= n; i++) {
 n3 = PrimeroC(C);
 BorraC(&C);
 if (i % n1 == 2)
 printf("\n\t %d se quita ", n3) ;
 else {
 AnadeC(&C, n3);
 n2++ ;
 } // else
 } //for
 
 n = n2 ;
 n1++ ;
 } //while 
 printf("\n Los numeros de la suerte: ") ;
 MostrarCola(&C);
 printf("\n") ;
 getch() ;
} // int main


void VaciaC(Cola *C) {
 C->Frente = NULL ;
 C->Final = NULL ;
 } // void VaciaC
int EsVaciaC(Cola C) {
 return (C.Frente == NULL ) ;
 } // int EsVaciaC
void AnadeC(Cola *C, TipoElemento e) 
{
 NodoCola *a ;
 a = (NodoCola*)malloc(sizeof(NodoCola)) ;
 a->e = e ;
 a->sig = NULL ;
 if (EsVaciaC(*C))
 C->Frente = a ;
 else
 C->Final->sig = a ;
 C->Final = a ;
} // void AnadeC
void BorraC(Cola *C)
{
 NodoCola *a ;
 if (!EsVaciaC(*C)) {
 a = C->Frente ;
 C->Frente = C->Frente->sig ;
 if (C->Frente == NULL)
 C->Final = NULL ;
 free(a);
 }
 else {
 puts("Error Eliminacion de una Cola Vacia") ;
 exit(-1) ;
 }
} // void BorraC
TipoElemento PrimeroC(Cola C) 
{
 if (EsVaciaC(C)) {
 puts("Error: Cola Vacia") ;
 exit(-1) ;
 } // if 
 return (C.Frente->e) ;
} // TipoElemento PrimeroC
void MostrarCola(Cola *C) 
{
 /* Muestra los elementos de una cola 
 que se le pase como parametro */
 TipoElemento e;
 while (!EsVaciaC(*C)) {
 e = PrimeroC(*C) ;
 printf("%d ", e) ;
 BorraC(C) ;
 } // while 
} // void MostrarCola
