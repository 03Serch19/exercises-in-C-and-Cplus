#include <stdio.h>
main( )
{
int*px; /* puntero a un entero */
int i = 1;
float f = 0.3;
double d = 0.005;
char c = '*' ;
px = &i;
printf ( "Valores: i=%i f=%f d=%f c=%c\n\n", i, f, d, c);
printf("Direcciones: &i=%x &f=%x &d=%x &c=%x\n\n", &i, &f, &d, &c);
/*printf("Valores de punteros: px=%x px + 1=%x px + 2=%x");
printf("px + 3=%x", px, px+1, px+2, px+3);*/ //no sirve esto xd
printf("Valores de punteros: px = %x  px + 1 = %x  px + 2 = %x  px + 3 = %x", px, px+1, px+2, px+3);

}
