/*Nombre:PROPAGA*/ 
#include <conio.h> 
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include "coladim.h" 
#include "listalin.h" 
#include <stdlib.h>  // por system()
main() 
{ /* Variable */ 
 TipoCola DatosDiarios; 
 ApuntaNodo DatosGenerales, Aux; 
 TipoDato DatoCola; 
 TipoInfo DatoLista; 
 FILE * arch; 
 /* Inicializaciones */ 
 LimpiarLista(&DatosGenerales); 
 LimpiarCola(&DatosDiarios); 
 arch=fopen("General.txt","r"); 
 /*Creaci¢n de la lista*/ 
 while (!feof(arch)) 
 { fscanf(arch, "%s \n", DatoLista.ISSS); 
 fscanf(arch, "%s \n", DatoLista.Nombre); 
 fscanf(arch, "%d \n", &DatoLista.DiasTrabajados); 
 InserOrden(DatoLista,&DatosGenerales); 
 } 
 fclose(arch); 
 /* Registro de datos diarios */ 
 system("cls"); 
// system("clear"); 
 printf("\nDigite -1 en Numero de Seguro Social para terminar\n"); 
 printf("Numero de Seguro Social:"); 
 fflush(stdin); 
 scanf("%s",DatoCola.SeguroSocial); 
 while (strcmp(DatoCola.SeguroSocial,"-1")) 
 { fflush(stdin); 
 printf("Entidad:"); 
 scanf("%s",DatoCola.Entidad); 
 Poner(DatoCola,&DatosDiarios); 
 printf("\nDigite -1 en Numero de Seguro Social para terminar\n"); 
 printf("Numero de Seguro Social:"); 
 scanf("%s",DatoCola.SeguroSocial); 
 } 
 /* Actualizar Lista */ 
 while (!ColaVacia(DatosDiarios)) 
 { 
 Quitar(&DatoCola,&DatosDiarios); 
 /*Busqueda de empleado*/ 
 Aux=DatosGenerales; 
 while((strcmp(Aux->Info.ISSS,DatoCola.SeguroSocial)<0) && 
(Aux->Sgte != NULO) ) 
 Aux=Aux->Sgte; 
 /*Actualiza o Agrega*/ 
 if (!strcmp(Aux->Info.ISSS,DatoCola.SeguroSocial)) 
 Aux->Info.DiasTrabajados++; 
 else 
 {strcpy(DatoLista.ISSS,DatoCola.SeguroSocial); 
 DatoLista.DiasTrabajados=1; 
 system("cls"); 
 printf("\nAgregando un Nuevo Empleado\n"); 
 printf("Numero Seguro Social:%s\n",DatoLista.ISSS); 
 printf("Nombre:"); 
 scanf("%s",DatoLista.Nombre); 
 InserOrden(DatoLista,&DatosGenerales); 
 } 
 } 
 /*Mostrar el contenido de la Lista*/ 
 system("cls"); 
 printf("\nListado General de Empleados\n"); 
 Aux=DatosGenerales;
 while(Aux!=NULO){ 
 printf("Numero Seguro Social:%s\n",Aux->Info.ISSS); 
 printf("Nombre:%s\n",Aux->Info.Nombre); 
 printf("Dias Trabajados:%d\n\n",Aux->Info.DiasTrabajados); 
 Aux=Aux->Sgte; 
 } 
 printf("<ENTER> para continuar.....\n\n"); 
 getch(); 
 /*Actualizando Archivos de texto*/ 
 arch=fopen("General.txt","w"); 
 printf("Guardando en Archivo"); 
 while(!ListaVacia(DatosGenerales)){ 
 Suprimir(&DatoLista,&DatosGenerales); 
 fprintf(arch,"%s\n",DatoLista.ISSS); 
 fprintf(arch,"%s\n",DatoLista.Nombre); 
 fprintf(arch,"%d\n",DatoLista.DiasTrabajados); 
 } 
 fclose(arch); 
 return(0); 
}/* main */ 

