// archivo de definición de la clase ColaLineal.cpp
#include "ColaLineal.hpp"
ColaLineal :: ColaLineal()
{
frente = 0;
final = -1;
}
// operaciones de modificación de la cola
void ColaLineal :: insertar(const TipoDeDato& elemento)
{
if (!colaLlena())
{
listaCola[++final] = elemento;
}
else
throw "Overflow en la cola";
}
TipoDeDato ColaLineal :: quitar()
{
if (!colaVacia())
{
return listaCola[frente++];
}
else
throw "Cola vacia ";
}
void ColaLineal :: borrarCola()
{
frente = 0;
final = -1;
}
// acceso a la cola
TipoDeDato ColaLineal :: frenteCola()
{
if (!colaVacia())
{
return listaCola[frente];
}
else
throw "Cola vacia ";
}
// métodos de verificación del estado de la cola
bool ColaLineal :: colaVacia()
{
return frente > final;
}
bool ColaLineal :: colaLlena()
{
return final == MAXTAMQ - 1;
}

