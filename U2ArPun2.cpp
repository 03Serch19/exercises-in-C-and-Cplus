# include <ctype.h>
# include <stdio.h>
void uppercase(char *ps){
 while(*ps){
if (islower (*ps)){
*ps = toupper(*ps);
}
ps++; 
 }
}
void fn(){
 char *pString;
 char c[] = "Estructura";
 pString = c;
 uppercase(pString);
 printf("String convertido a mayusculas: %c",*pString);
}
int main()
{
 fn();
 return 0;
}

