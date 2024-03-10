# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <conio.h>
typedef struct datos elemento;
struct datos {
 char suceso[81];
 elemento *siguiente;
};
void error(void) {
 printf("Error: insuficiente espacio de memoria");
 exit(1);
}
elemento *nuevoelemento(void) {
 elemento *q=(elemento*)malloc(sizeof(elemento));
 if(!q) error();
 return q;
}
void menu(void);
void introducir(elemento**, elemento**, char[]);
char *realizar(elemento**, elemento**);
int main() {
 elemento *principio, *final; 
 char opcion,suceso[81];
 principio=final=NULL;
 while(1) {
 do {
 menu();
 opcion=toupper(getche());
 } while(opcion!='I'&&opcion!='R'&&opcion!='S');
 
 switch(opcion){
 case 'I': printf("\n Introduzca un suceso:");
 gets(suceso);
 introducir(&principio,&final,suceso);
 break;
 case'R':strcpy(suceso,realizar(&principio, 
 &final));
 if (*suceso)
 printf ("\n realizando el suceso %s", suceso);
printf("\n pulse una tecla para continuar");
 getch();
 break;
 case 'S': exit(0);
 }
 } 
 } 
void menu (void) {
 printf ("\n \t introducir suceso");
 printf ("\n \t realizar suceso");
 printf ("\n \t salir");
 printf ("\n \t elija la opcion deseada(I, R, S):");
}
/*añadir un dato a la cola*/
void introducir (elemento**p, elemento **f, char suceso[]) {
 elemento *pc, *fc, *q;
 pc=*p; /*principio de la cola*/
 fc=*f; /*final de la cola*/
 q=nuevoelemento ();
 strcpy(q->suceso, suceso);
 q->siguiente =NULL;
 if (fc ==NULL)
 pc=fc=q;
 else
 fc=fc->siguiente=q;
 *p=pc;
 *f=fc;
}
/* recuperar un dato de la cola*/
char *realizar(elemento **p, elemento**f) {
 elemento *pc, *fc, *q;
 char *suceso;
 pc=*p;/* principio de la cola */
 fc=*f; /*final de la cola*/
 if (pc!=NULL){
 q=pc;
 suceso = (char*)malloc(strlen(q->suceso)+1);
 strcpy(suceso, q->suceso);
 pc=pc->siguiente;
 if(pc==NULL)
 fc=NULL;
 free(q);
 *p=pc;
 *f=fc;
 }
 else {
 printf("\n no hay sucesos");
 suceso [0]='\0';
 }
 return suceso;
}


