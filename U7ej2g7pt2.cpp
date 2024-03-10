#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ORDEN 2
typedef struct bnodo
{
 unsigned int clavesUsadas, nhijos; // Claves usadas en el nodo
 int *claves[2 * ORDEN]; // Arreglo de claves del nodo
 struct bnodo *hijo[2*ORDEN]; // Arreglo de punteros a bnodo
 struct bnodo *padre; // Puntero a nodo padre
} NODO;
typedef NODO *pbnodo;
void crearClave(pbnodo *n, int dato)
{
 (*n)->claves[(*n)->clavesUsadas] = (int *)malloc(sizeof(int));
 *((*n)->claves[(*n)->clavesUsadas]) = dato;
 (*n)->clavesUsadas++;
}
void crearNodo(NODO **x)
{
 int i;
 (*x) = (NODO *)malloc(sizeof(NODO));
 (*x)->padre = NULL;
 (*x)->clavesUsadas = (*x)->nhijos = 0;
 for (i = 0; i < 2 * ORDEN; i++){
 (*x)->claves[i] = NULL;
 (*x)->hijo[i] = NULL;
 }
}
void Inserta(int clave, pbnodo *nodo, pbnodo hijo1, pbnodo hijo2, pbnodo *Entrada)
{
 pbnodo padre, nuevo, *listapunt;
 int i, j, lista[2 * ORDEN + 1];
 int salir = 0;
 // Insertar nueva clave en nodo:
 do
 {
 if (!(*nodo))
 {
 crearNodo(nodo);
 *Entrada = *nodo;
 }
 padre = (*nodo)->padre;
 
 if ((*nodo)->clavesUsadas == 2 * ORDEN) // overflow
 {
 // Nodo derecho
 crearNodo(&nuevo);
 // Construye lista ordenada:
 i = 0;
 while (i <= 2 * ORDEN -1 && *((*nodo)->claves[i]) < clave )
 { 
 lista[i] = *((*nodo)->claves[i]);
 listapunt[i] = (*nodo)->hijo[i];
 i++;
 }
 lista[i] = clave;
 listapunt[i] = hijo1;
 listapunt[i+1] = hijo2;
 
 while (i < 2 * ORDEN)
 {
 lista[i + 1] = *((*nodo)->claves[i]);
listapunt[i + 2] = (*nodo)->hijo[i + 1];
 i++;
 }
 
 // Dividir nodos:
 // Nodo izquierdo:
 (*nodo)->clavesUsadas = ORDEN;
 for (j = 0; j < (*nodo)->clavesUsadas; j++)
 {
 *((*nodo)->claves[j]) = lista[j];
 (*nodo)->hijo[j] = listapunt[j];
 }
 ((*nodo)->hijo[(*nodo)->clavesUsadas]) = listapunt[(*nodo)->clavesUsadas];
 // Nodo derecho:
 nuevo->clavesUsadas = 2 * ORDEN - (*nodo)->clavesUsadas;
 for (j = 0; j < nuevo->clavesUsadas; j++)
 {
 (nuevo->claves[j]) = (int *)malloc(sizeof(int));
 *(nuevo->claves[j]) = lista[j + (ORDEN) + 1];
 nuevo->hijo[j] = listapunt[j + (ORDEN - 1) + 1];
 }
 nuevo->hijo[nuevo->clavesUsadas] = listapunt[2 * ORDEN];
 for (j = 0; j <= (*nodo)->clavesUsadas; j++)
 if ((*nodo)->hijo[j])
 ((*nodo)->hijo[j])->padre = *nodo;
 for (j = 0; j <= nuevo->clavesUsadas; j++)
 if (nuevo->hijo[j])
 (nuevo->hijo[j])->padre = nuevo;
 clave = lista[ORDEN];
 hijo1 = *nodo;
 hijo2 = nuevo;
 *nodo = padre;
 
 } else {
 // Inserta nueva clave en su lugar:
 i = 0;
 if ((*nodo)->clavesUsadas > 0)
 {
 while (i < (*nodo)->clavesUsadas && *((*nodo)->claves[i]) < clave )
 i++; 
 for (j = (*nodo)->clavesUsadas; j > i; j--)
 (*nodo)->claves[j] = (*nodo)->claves[j - 1];
 for (j = (*nodo)->clavesUsadas + 1; j > i; j--)
 (*nodo)->hijo[j] = (*nodo)->hijo[j - 1];
 }
 (*nodo)->claves[i] = (int *)malloc(sizeof(int));
 *((*nodo)->claves[i]) = clave;
 (*nodo)->hijo[i] = hijo1;
 (*nodo)->hijo[i + 1] = hijo2;
 (*nodo)->clavesUsadas++;
 if (hijo1)
 hijo1->padre = *nodo;
 if (hijo2)
hijo2->padre = *nodo;
 salir = 1;
 }
 } while (!salir);
}
void imprimirArbolB(pbnodo);
int Insertar(int clave, pbnodo *Entrada)
{
 pbnodo nodo, padre;
 int i;
 padre = nodo = *Entrada;
 while (nodo)
 {
 padre = nodo;
 i = 0;
 while (i < nodo->clavesUsadas && (*(nodo->claves[i]) < clave))
 i++;
 if ( i < nodo->clavesUsadas && *(nodo->claves[i]) == clave)
 return 0;
 else
 nodo = nodo->hijo[i];
 }
 nodo = padre;
 Inserta(clave, &nodo, NULL, NULL, Entrada);
 return 1;
}
void PasarClaveDerecha(pbnodo derecha, pbnodo padre, pbnodo nodo, int posClavePadre)
{
 int i;
 nodo->claves[nodo->clavesUsadas] = padre->claves[posClavePadre];
 nodo->clavesUsadas++;
 padre->claves[posClavePadre] = derecha->claves[0];
 nodo->hijo[nodo->clavesUsadas] = derecha->hijo[0];
 if (derecha->hijo[0])
 derecha->hijo[0]->padre = nodo;
 for (i = 0; i < derecha->clavesUsadas; i++)
 derecha->claves[i] = derecha->claves[i + 1];
 for (i = 0; i <= derecha->clavesUsadas; i++)
 derecha->hijo[i] = derecha->hijo[i + 1];
 derecha->clavesUsadas--;
 free(derecha->claves[0]);
}
void PasarClaveIzquierda(pbnodo izquierda, pbnodo padre, pbnodo nodo, int posClavePadre)
{
 int i;
 for (i = nodo->clavesUsadas; i > 0; i--)
 nodo->claves[i] = nodo->claves[i - 1];
 for (i = nodo->clavesUsadas + 1; i > 0; i--)
 nodo->hijo[i] = nodo->hijo[i - 1];
 nodo->clavesUsadas++;
 nodo->claves[0] = padre->claves[posClavePadre];
 padre->claves[posClavePadre] = izquierda->claves[izquierda->clavesUsadas - 1];
 nodo->hijo[0] = izquierda->hijo[izquierda->clavesUsadas];
 if (nodo->hijo[0])
 nodo->hijo[0]->padre = nodo;
 free(izquierda->claves[izquierda->clavesUsadas - 1]);
 izquierda->clavesUsadas--;
}
void FundirNodo(pbnodo izquierda, pbnodo *padre, pbnodo derecha, int posClavePadre, pbnodo *Entrada)
{
 int i;
 izquierda->claves[izquierda->clavesUsadas] = (*padre)->claves[posClavePadre];
 free((*padre)->claves[posClavePadre]);
 (*padre)->clavesUsadas--;
 for (i = posClavePadre; i < (*padre)->clavesUsadas; i++)
 {
 (*padre)->claves[i] = (*padre)->claves[i + 1];
 (*padre)->hijo[i + 1] = (*padre)->hijo[i + 2];
 }
 izquierda->clavesUsadas++;
 for (i = 0; i < derecha->clavesUsadas; i++)
 izquierda->claves[izquierda->clavesUsadas + i] = derecha->claves[i];
 for (i = 0; i <= derecha->clavesUsadas; i++)
 {
 izquierda->hijo[izquierda->clavesUsadas + i] = derecha->hijo[i];
 if (derecha->hijo[i])
 derecha->hijo[i]->padre = izquierda;
 }
 izquierda->clavesUsadas += derecha->clavesUsadas;
 if ((*padre) == *Entrada && (*padre)->clavesUsadas == 0)
 {
 // Cambio de entrada
 *Entrada = izquierda;
 (*Entrada)->padre = NULL;
 free(*padre);
 *padre = NULL;
 }
 free(derecha);
}
void BorrarClave(pbnodo nodo, int valor, pbnodo *Entrada)
{
 pbnodo actual, derecha, izquierda, padre;
 int posClavePadre, pos, i;
 // Buscar posicion dentro de lista de claves:
 pos = 0;
 while (*(nodo->claves[pos]) < valor)
 pos++;
 // ¿Esta la clave en un nodo hoja?
 if (nodo->hijo[0])
 {
 // Buscar actual del valor siguiente:
 actual = nodo->hijo[pos + 1];
 while (actual->hijo[0])
 actual = actual->hijo[0];
 // Intercambio con el valor siguiente:
 *(nodo->claves[pos]) = *(actual->claves[0]);
// La posicion de la clave a borrar en ahora la 0:
 pos = 0;
 }
 else
 actual = nodo;
 // Borrar clave
 for (i = pos; i < actual->clavesUsadas - 1; i++)
 *(actual->claves[i]) = *(actual->claves[i + 1]);
 free(actual->claves[i]);
 actual->clavesUsadas--;
 if (actual == *Entrada && actual->clavesUsadas == 0)
 {
 free(actual);
 *Entrada = NULL;
 return;
 }
 if (actual == *Entrada || actual->clavesUsadas >= ORDEN)
 return;
 do
 {
 // El numero de claves es menor que el maximo:
 // Buscar nodos a derecha e izquierda:
 padre = actual->padre;
 for (posClavePadre = 0; padre->hijo[posClavePadre] != actual; posClavePadre++)
 ;
 if (posClavePadre > 0)
 izquierda = padre->hijo[posClavePadre - 1];
 else
 izquierda = NULL;
 if (posClavePadre < padre->clavesUsadas)
 derecha = padre->hijo[posClavePadre + 1];
 else
 derecha = NULL;
 // Intentar pasar una clave de un nodo cercano:
 if (derecha && derecha->clavesUsadas > ORDEN)
 PasarClaveDerecha(derecha, padre, actual, posClavePadre);
 else if (izquierda && izquierda->clavesUsadas > ORDEN)
 PasarClaveIzquierda(izquierda, padre, actual, posClavePadre - 1);
 //Si no fue posible,fundir con un nodo cercano y una clave padre:
 else if (derecha) // Usar nodo derecho
 FundirNodo(actual, &padre, derecha, posClavePadre, Entrada);
 else // Usar el nodo izquierdo
 FundirNodo(izquierda, &padre, actual, posClavePadre - 1, Entrada);
 // Vuelta a empezar:
 actual = padre;
 } while (actual && actual != *Entrada && actual->clavesUsadas < ORDEN);
}
void Borrar(int valor, pbnodo *Entrada)
{
 pbnodo nodo;
 int encontrado = 0;
 int i;
 // Busca el nodo que contiene la clave, si existe
 nodo = *Entrada;
 while (nodo && !encontrado)
 {
i = 0;
 while (i < nodo->clavesUsadas && (*(nodo->claves[i]) < valor))
 i++;
 if (*(nodo->claves[i]) == valor && i < nodo->clavesUsadas)
 encontrado = 1;
 else
 nodo = nodo->hijo[i];
 }
 if (encontrado)
 {
 BorrarClave(nodo, valor, Entrada);
 puts("\n El nodo se ha borrado");
 }
 else
 puts("\n El nodo no se encontro");
 getch();
}
void hojas(pbnodo);
void internos(pbnodo);
int main()
{
 pbnodo arbol = NULL;
 int clave = 0;
 int i, op, ban = 1;
 while (ban)
 {
 system("cls");
 puts("\n\n\n\n\t\t\t\t---------");
 printf("\t\t\t\t MENU PRINCIPAL:");
 printf("\n\t\t\t\t---------\n\n");
 printf("\t\t\t\t%d. %s\n\n", 1, "Agregar. Solo se pueden introducir 2 x ORDEN, en este caso 2 x 2= 4");
 printf("\t\t\t\t%d. %s\n\n", 2, "Borrar");
 printf("\t\t\t\t%d. %s\n\n", 3, "Imprimir arbol");
 printf("\t\t\t\t%d. %s\n\n", 4, "Salir");
 printf("\n\t\t\t Seleccione su opcion: ");
 
 scanf("%d", &op);
 switch (op)
 {
 case 1:
 system("cls");
 printf("\n Digite la clave que desea insertar: ");
 scanf("%d", &clave);
 Insertar(clave, &arbol);
 break;
 case 2:
 system("cls");
 printf("\n Digite la clave que desea borrar: ");
 scanf("%d", &clave);
 Borrar(clave, &arbol);
 break;
 case 3:
system("cls");
 imprimirArbolB(arbol);
 getch();
 break;
 case 4:
 ban = 0;
 break;
 default:
 puts("\n Opcion Invalida, presione una tecla.");
 getch();
 break;
 }
 }
 return 0;
} //Fin del main
void hojas(pbnodo n)
{
 int i = 0;
 if (n != NULL)
 {
 puts("\n Las claves hojas son:\n");
 while (n->claves[i] != NULL)
 {
 printf(" ");
 if (n->hijo == NULL)
 printf("%d - ", *(n)->claves[i]);
 i++;
 }
 getch();
 }
}
void imprimirArbolB(pbnodo nodo)
{
 int i;
 if (nodo)
 {
 for (i = 0; i < nodo->clavesUsadas; i++)
 printf(" %d ", *(nodo->claves[i]));
 getch();
 printf("\n");
 for (i = 0; i < nodo->clavesUsadas + 1; i++)
 imprimirArbolB(nodo->hijo[i]);
 }
 return;
}

