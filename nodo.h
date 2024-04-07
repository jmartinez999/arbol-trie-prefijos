#ifndef __NODO__H__
#define __NODO__H__


class Nodo {
protected:
  char dato;
  Nodo* hijos[26];
  bool finalPalabra;

public:
  Nodo();
  Nodo(char valor, bool esFinal);
  char obtenerDato();
  bool esFinalPalabra();
  void fijarDato(char valor, bool esFinal);
  void crearNodoHijo(int posicion, Nodo* hijo);
  Nodo* getHijo(int posicion);
  Nodo* buscar(char val);
  void printData();
};

#endif