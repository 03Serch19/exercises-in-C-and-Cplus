#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#define MAXCOLS 80 
typedef struct nodo { 
 char dato; 
 struct nodo *siguiente; 
}tiponodo; 
typedef tiponodo *pNodo; 
typedef tiponodo *Pila; 
/*prototipos de funciones de Pila*/ 
int empty(Pila *); 
char pop(Pila *); 
void push(Pila *, char); 

 int main() { 
 char linea[MAXCOLS]; 
 char invert[MAXCOLS]; 
 int pos=0, i; 
Pila p1=NULL; 
 printf("\tDigite una linea de texto:\n"); 
 while ((linea[pos++]=getchar()) != '\n'); 
 linea[--pos]='\0'; 
 
 printf("La linea original es:\n %s", linea); 
 for (i=0; i<pos; i++) 
 push(&p1, linea[i]); 
 for (i=0; i<pos; i++) 
 invert[i]=pop(&p1); 
 invert[pos]='\0'; 
 
 printf("\nLa linea invertida es: \n %s", invert); 
 getch(); 
} 

int empty(Pila *ps) 
{ 
 return ((*ps)== NULL); 
} 
void push(Pila *ps, char a) 
{ 
 pNodo nuevo; 
 nuevo = (pNodo) malloc(sizeof(tiponodo)); 
 if (nuevo != NULL) 
 { 
 nuevo->dato = a; 
 nuevo->siguiente = *ps; 
 *ps = nuevo; 
 } 
 else 
 printf("No se pudo insertar el elemento. Falta de memoria\n"); 
} 
char pop(Pila * ps) 
{ 
 pNodo temp; 
 char popvalue; 
 temp = *ps; 
 popvalue = (*ps)->dato; 
 *ps = (*ps)->siguiente; 
 free(temp); 
 return popvalue; 
} 
