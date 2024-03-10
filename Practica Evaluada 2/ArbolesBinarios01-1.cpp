#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
      int dato;
      Nodo* der;
      Nodo* izq;
      Nodo* padre;
};

Nodo* crearNodo(int, Nodo*);
void insertar(Nodo*&, int, Nodo*);
void mostrarArbol(Nodo*, int);
bool busqueda(Nodo*, int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
void eliminar(Nodo*, int);
void eliminarNodo(Nodo*);
Nodo* minimo(Nodo*);
void reemplazar(Nodo*, Nodo*);
void destruirNodo(Nodo*);

Nodo* arbol = NULL;

int main()
{
      int dato, opcion, contador = 0;

      do
      {
            cout << "\t. :MENU: ." << endl;
            cout << "1. Insertar un nuevo nodo" << endl;
            cout << "2. Mostrar arbol completo" << endl;
            cout << "3. Buscar un elemento en el arbol" << endl;
            cout << "4. Recorrer el arbol en PreOrden" << endl;
            cout << "5. Recorrer el arbol en InOrden" << endl;
            cout << "6. Recorrer el arbol en PostOrden" << endl;
            cout << "7. Eliminar un nodo del arbol" << endl;
            cout << "8. Salir" << endl;
            cout << "Opcion: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1: cout << "\nDigite un numero: ";
                  cin >> dato;
                  insertar(arbol, dato, NULL);
                  cout << "\n";
                  //system("pause");
                  break;
                  system("cls");
            case 2: cout << "\nMostrando el arbol completo: \n\n";
                  mostrarArbol(arbol, contador);
                  cout << "\n";
                  system("pause");
                  break;
            case 3: cout << "\nDigite el elemento a buscar: ";
                  cin >> dato;
                  if (busqueda(arbol, dato))
                  {
                        cout << "\nElemento  " << dato << " ha sido encontrado en el arbol\n";
                  }
                  else
                  {
                        cout << "\nElemento no encotrado\n";
                  }
                  cout << "\n";
                  system("pause");
                  break;
            case 4: cout << "\nRecorrido en PreOrden: ";
                  preOrden(arbol);
                  cout << "\n\n";
                  system("pause");
                  break;
            case 5: cout<<"\nRecorrido en InOrden: ";
                  inOrden(arbol);
                  cout << "\n\n";
                  system("pause");
                  break;
            case 6: cout << "\nRecorrido en PostOrden: ";
                  postOrden(arbol);
                  cout << "\n\n";
                  system("pause");
                  break;
            case 7: cout << "\nDigite el numero a eliminar: ";
                  cin >> dato;
                  eliminar(arbol, dato);
                  cout << "\n";
                  system("pause");
                  break;
            }
      } while (opcion != 8);
      return 0;
}

Nodo* crearNodo(int n, Nodo *padre)
{
      //reservando memoria para el nuevo nodo
      Nodo* nuevo_nodo = new Nodo();

      //introduciendo datos al nodo y apuntando a NULL en ambos lados
      nuevo_nodo->dato = n;
      nuevo_nodo->der = NULL;
      nuevo_nodo->izq = NULL;
      nuevo_nodo->padre = padre;

      return nuevo_nodo;
}

void insertar(Nodo*& arbol, int n, Nodo* padre)
{
      if (arbol == NULL)
      {
            Nodo* nuevo_nodo = crearNodo(n, padre);
            arbol = nuevo_nodo;
      }
      else
      {
            int valorRaiz = arbol->dato;
            if (n < valorRaiz)
            {
                  insertar(arbol->izq, n, arbol);
            }
            else
            {
                  insertar(arbol->der, n, arbol);
            }
      }
}

void mostrarArbol(Nodo* arbol, int contador)
{
      if (arbol == NULL)
      {
            return;
      }
      else
      {
            mostrarArbol(arbol->der, contador + 1);
            for (int i = 0; i < contador; i++)
            {
                  cout << "     ";
            }
            cout << arbol->dato << endl;
            mostrarArbol(arbol->izq, contador + 1);
      }
}

bool busqueda(Nodo* arbol, int n)
{
      if (arbol == NULL)
      {
            return false;
      }
      else
      {
            if (arbol->dato == n)
            {
                  return true;
            }
            else
            {
                  if (n < arbol->dato)
                  {
                        return busqueda(arbol->izq, n);
                  }
                  else
                  {
                        return busqueda(arbol->der, n);
                  }
            }
      }
}

void preOrden(Nodo* arbol)
{
      if (arbol == NULL)
      {
            return;
      }
      else
      {
            cout << arbol->dato << " - ";
            preOrden(arbol->izq);
            preOrden(arbol->der);
      }
}

void inOrden(Nodo* arbol)
{
      if (arbol == NULL)
      {
            return;
      }
      else
      {
            inOrden(arbol->izq);
            cout << arbol->dato << " - ";
            inOrden(arbol->der);
      }
}

void postOrden(Nodo* arbol)
{
      if (arbol == NULL)
      {
            return;
      }
      else
      {
            preOrden(arbol->izq);
            preOrden(arbol->der);
            cout << arbol->dato << " - ";
      }
}

void eliminar(Nodo* arbol, int n)
{
      if (arbol == NULL)
      {
            return;
      }
      else
      {
            if (n < arbol->dato)
            {
                  eliminar(arbol->izq, n);
            }
            else
            {
                  if (n > arbol->dato)
                  {
                        eliminar(arbol->der, n);
                  }
                  else
                  {
                        eliminarNodo(arbol);
                  }
            }
      }
}

void eliminarNodo(Nodo* nodoEliminar)
{
      if (nodoEliminar->der && nodoEliminar->izq)
      {
            Nodo* menor = minimo(nodoEliminar->der);
            nodoEliminar->dato = menor->dato;
            eliminarNodo(menor);
      }
      else
      {
            if (nodoEliminar->izq)
            {
                  reemplazar(nodoEliminar, nodoEliminar->izq);
                  destruirNodo(nodoEliminar);
            }
            else
            {
                  if (nodoEliminar->der)
                  {
                        reemplazar(nodoEliminar, nodoEliminar->der);
                        destruirNodo(nodoEliminar);
                  }
                  else
                  {
                        reemplazar(nodoEliminar, NULL);
                        destruirNodo(nodoEliminar);
                  }
            }
      }
}

Nodo* minimo(Nodo* arbol)
{
      if (arbol == NULL)
      {
            return NULL;
      }
      if (arbol->izq)
      {
            return minimo(arbol->izq);
      }
      else
      {
            return arbol;
      }
}

void reemplazar(Nodo* arbol, Nodo* nuevoNodo)
{
      if (arbol->padre)
      {
            if (arbol->padre->izq) {
                  if (arbol->dato == arbol->padre->izq->dato) {
                        arbol->padre->izq = nuevoNodo;
                  }
                  else {
                        if (arbol->dato == arbol->padre->der->dato) {
                              arbol->padre->der = nuevoNodo;
                        }
                  }
            }
      }
      if (nuevoNodo)
      {
            nuevoNodo->padre = arbol->padre;
      }
}

void destruirNodo(Nodo* nodo)
{
      nodo->izq = NULL;
      nodo->der = NULL;
      delete nodo;
}