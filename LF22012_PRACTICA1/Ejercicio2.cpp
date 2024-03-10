# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

typedef struct datos elemento;

struct datos {
            int dato;
            elemento *siguiente;
};

int remover(elemento **principio, elemento**final);
void error(void);
elemento *nuevoelemento(void);
void introducir (elemento**principio, elemento **final, int v);

//A CONTINUACIÓN, LA DEFINICIÓN DE LAS FUNCIONES DE COLA

void error(void) {
    printf("Error: insuficiente espacio de memoria");
    exit(1);
 }

elemento *nuevoelemento(void) {
  elemento *q=(elemento*)malloc(sizeof(elemento));
  if(!q) error();
  return q;
 }

void introducir (elemento**p, elemento **f, int v)  {
    elemento *pc, *fc, *q;
    pc=*p; /*principio de la  cola*/
    fc=*f;  /*final de la cola*/
    q=nuevoelemento ();
    q->dato=v;
    q->siguiente =NULL;

    if (fc ==NULL)
        pc=fc=q;
    else
        fc=fc->siguiente=q;
    *p=pc;
    *f=fc;
}

int remover(elemento **p, elemento**f)  {
    elemento *pc, *fc, *q;
    int v;
    pc=*p;/* principio de la cola */
    fc=*f; /*final de la cola*/
    if (pc!=NULL){
         q=pc;
         v= q->dato;
         pc=pc->siguiente;
         if(pc==NULL)
              fc=NULL;	
         free(q);
         *p=pc;
         *f=fc;
      }
      else {
          printf("\n no hay datos");
          v=-1;
      }
      return v;
}
int MultiplicarYSumar(elemento **principio, int valor) {
    elemento *temp = *principio;
    int suma = 0;
    
    if (!temp) {
        printf("La cola está vacía.\n");
        return 0;
    }

    int pos = 0;

    while (temp) {
        if (pos % 2 == 0) {
            temp->dato *= valor;
        }
        suma += temp->dato;
        temp = temp->siguiente;
        pos++;
    }
    
    return suma;
}

int main() {
    elemento *principio = NULL;
    elemento *final = NULL;
    int valor = 5; // Puedes cambiar este valor

    // Llena la cola con valores (ejemplo)
    introducir(&principio, &final, 1);
    introducir(&principio, &final, 2);
    introducir(&principio, &final, 3);
    introducir(&principio, &final, 4);
    introducir(&principio, &final, 5);

    printf("Cola antes de multiplicar y sumar:\n");
    int suma = 0;
    elemento *temp = principio;

    while (temp) {
        printf("%d -> ", temp->dato);
        suma += temp->dato;
        temp = temp->siguiente;
    }

    printf("\n");

    printf("Suma de elementos antes de multiplicar y sumar: %d\n", suma);

    suma = MultiplicarYSumar(&principio, valor);

    printf("Cola despues de multiplicar y sumar:\n");
    temp = principio;

    while (temp) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }

    printf("\n");

    printf("Suma de elementos despues de multiplicar y sumar: %d\n", suma);

    // Libera la memoria de la cola si es necesario
    while (principio != NULL) {
        remover(&principio, &final);
    }

    return 0;
}

