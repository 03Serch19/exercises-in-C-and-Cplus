#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
/* Aplicacion de listas circulares con nodos de encabezado. El Hw solo 
permite enteros de una longitud maxima especifica. Suponga que queremos 
representar enteros positivos de longitud arbitraria y escribir una funcion 
que retorne la suma de esos dos enteros. 
Para agregar dos enteros, se recorren sus digitos de derecha a izquierda 
y se suman los digitos correspondientes y un posible acarreo de la suma de 
digitos anterior. */ 
// estructura de los nodos 
struct node { 
 long int info; 
 struct node *next; 
}; 
typedef struct node *NODEPTR; 
// el nodo de encabezado de la lista circular se distingue por un valor -1. 
NODEPTR addint ( NODEPTR , NODEPTR ); 
NODEPTR getnode ( void ); 
void insert ( NODEPTR *, long int ); 
void imprimir( NODEPTR ); 
void insafter (NODEPTR, long int ); 
int main ( void ) { 
 long int a[10]={0}, a1, a2, a3, a4; 
 int i,dig; 
 NODEPTR r = NULL,lista = NULL, lis2=NULL; 
 printf( "Este es un programa que puede representar enteros bastante largos. "); 
 printf( "Se le pide digite el numero de 5 en 5 dígitos, seguidos de un <enter>"); 
 printf(" Ejemplo: el numero a digitar es: 459763497210698463 \n"); 
 printf("Digite: 459 <enter> 76349 <enter> 72106 <enter> 98463 <enter>\n"); 
 printf("Capacidad maxima: 50 digitos \n"); 
 printf("Cuantos grupos de 5 digitos o menos va a digitar: (maximo: 10) "); 
 scanf("%d", &dig); 
 printf("arreglo:"); 
 for (i=0; i<10; i++) 
 printf("%d", a[i]); 
 printf("\n"); 
 for ( i=0; i<dig; i++) 
 { 
 fflush(stdin); 
 scanf("%D",&a[i]); 
 } 
 for ( i=0; i < dig; i++) 
 insert(&lista, a[i]); 
 imprimir(lista); 
 printf("Probemos ahora la suma de dos listas: \n"); 
 printf("Sumaremos a su numero, el numero: 45976349721069846354\n"); 
 a1 = 45976; 
 a2 = 34972; 
 a3 = 10698; 
 a4 = 46354; 
 insert(&lis2, a1); 
 insert(&lis2, a2); 
 insert(&lis2, a3); 
 insert(&lis2, a4); 
 r= addint(lista, lis2); 
 printf("La suma de los 2 numeros es: "); 
 imprimir(r); 
 printf("\n"); 
 getch(); 
} 
NODEPTR getnode(void) 
{ 
 NODEPTR p; 
 p = (NODEPTR) malloc ( sizeof ( struct node )); 
 return p; 
} 
/* inserta un nodo al inicio de la lista circular */ 
void insert ( NODEPTR *pq, long int x) 
{ 
 NODEPTR p, aux; 
 p = getnode(); 
 p->info = x; 
 if ( *pq == NULL ) 
 { 
 aux = getnode();
 aux->info = -1; 
 aux->next = p; 
 *pq = aux; 
 p->next = aux; 
 } 
 else 
 { 
 p->next = (*pq)->next; 
 (*pq)->next = p; 
 } /*fin del else */ 
} /*fin del insert */ 
NODEPTR addint ( NODEPTR p, NODEPTR q) 
{ 
 long int hunthou = 100000L; 
 long int carry, number, total; 
 NODEPTR s; 
 /*establecer p y q para los nodos despues de los encabezados */ 
 p = p->next; 
 q = q->next; 
 /*preparar un nodo de encabezado para la suma */ 
 s = getnode(); 
 s->info = -1; 
 s->next = s; 
 /*inicialmente no hay acarreo */ 
 carry = 0; 
 while ( p->info != -1 && q->info != -1 ) 
 { 
 /*sumar el campo info de los dos nodos y el acarreo previo */ 
 total = p->info + q->info + carry; 
 /*determinar los 5 digitos de orden inferior de la suma e 
 insertarlos en la lista */ 
 number = total % hunthou; 
 insafter(s, number); 
 /*avanzar los recorridos */ 
 s = s->next; 
 p = p->next; 
 q = q->next; 
 
 /*determinar si hay acarreo */ 
 carry = total / hunthou; 
 } /*fin de while */ 
 /*en este punto pueden quedar nodos en una de las dos listas de ingreso*/ 
 while (p->info != -1) 
 { 
 total = p->info + carry; 
number = total % hunthou; 
 insafter(s, number); 
 carry = total / hunthou; 
 s = s->next; 
 p = p->next; 
 } /*fin de while */ 
 while (q->info != -1) 
 { 
 total = q->info + carry; 
 number = total % hunthou; 
 insafter(s, number); 
 carry = total / hunthou; 
 s = s->next; 
 q = q->next; 
 } /*fin de while */ 
 /*comprobar si hay un acarreo extra de los primeros cinco dígitos*/ 
 if (carry == 1) 
 { 
 insafter(s, carry); 
 s = s->next; 
 } /*fin de if */ 
 /* s apunta al ultimo nodo en la suma. s->next apunta al encabezado 
 de la lista de suma. */ 
 return ( s->next ); 
} /*fin de addint */ 
/*inserta un nodo después del nodo apuntado por p */ 
void insafter (NODEPTR p, long int x) 
{ 
 NODEPTR q; 
 q = getnode(); 
 if ( p == NULL ) 
 { 
 p=getnode(); 
 p->info = -1; 
 p->next = q; 
 q->info = x; 
 q->next = p; 
 } 
 else 
 { 
 q->info = x; 
 q->next = p->next; 
 p->next = q; 
 } 
} /*fin de insafter */ 
void imprimir( NODEPTR L ) 
{ 
 NODEPTR L1; 
 long int B[10]={0};
  int i=0, k; 
 if (L->info == -1) 
 { 
 L1=L->next; 
 while ( L1->info != -1 ) 
 { 
 B[i++]=L1->info; 
 L1 = L1->next; 
 } 
 k=i-1; 
 for ( ; k>=0; k--) 
 printf("%d", B[k]); 
 printf("\n"); 
 } 
}
