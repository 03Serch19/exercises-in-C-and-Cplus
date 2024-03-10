// archivo ColaCircular.hpp
#include "ColaLineal.hpp"
class ColaCircular : public ColaLineal
{
protected:
int siguiente(int r);
//Constructor, inicializa a cola vac�a
public:
ColaCircular();
// operaciones de modificaci�n de la cola
void insertar(const TipoDeDato& elemento);
TipoDeDato quitar();
void borrarCola();
// acceso a la cola
TipoDeDato frenteCola();
// m�todos de verificaci�n del estado de la cola
bool colaVacia();
bool colaLlena();
};
