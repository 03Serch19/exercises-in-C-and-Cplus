// archivo de cabecera ColaLineal.hpp
typedef int TipoDeDato; // tipo ha de ser conocido
const int MAXTAMQ = 39;
class ColaLineal
{
protected:
int frente;
int final;
TipoDeDato listaCola[MAXTAMQ];
public:
ColaLineal();
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

