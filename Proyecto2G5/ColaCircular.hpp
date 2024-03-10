// archivo ColaCircular.hpp
#include "ColaLineal.hpp"
class ColaCircular : public ColaLineal
{
protected:
int siguiente(int r);
//Constructor, inicializa a cola vacía
public:
ColaCircular();
// operaciones de modificación de la cola
void insertar(const TipoDeDato& elemento);
TipoDeDato quitar();
void borrarCola();
// acceso a la cola
TipoDeDato frenteCola();
// métodos de verificación del estado de la cola
bool colaVacia();
bool colaLlena();
};
