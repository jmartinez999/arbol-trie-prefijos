#include "nodo.h"
#include <iostream>

using namespace std;


Nodo::Nodo(){
  this->dato = '\0';
  this->finalPalabra = false;
  for(int i = 0; i < 26; i++){
    this->hijos[i] = nullptr;
  }
}


Nodo::Nodo(char valor, bool esFinal){
  this->dato = valor;
  this->finalPalabra = esFinal;
  for(int i = 0; i < 26; i++){
    this->hijos[i] = nullptr;
  }
}


char Nodo::obtenerDato(){
  return this->dato;
}


bool Nodo::esFinalPalabra(){
  return this->finalPalabra;
}


void Nodo::fijarDato(char valor, bool esFinal){
  this->dato = valor;
  this->finalPalabra = esFinal;
}

void Nodo::crearNodoHijo(int posicion, Nodo* hijo){
  this->hijos[posicion] = hijo;
}

Nodo* Nodo::getHijo(int posicion){
  return this->hijos[posicion];
}



Nodo* Nodo::buscar(char val){
  int posicionArreglo = val - 97;
  if(this->hijos[posicionArreglo] != nullptr){
    return hijos[posicionArreglo];
  }
  else{
    return nullptr;
  }
}

/**
 * Imprime recursivamente el dato del nodo, si es final de palabra imprime un salto de linea.
 * invoca recursivamente a los hijos del nodo.
*/
void Nodo::printData(){
  if(this->dato != '\0'){
    cout << this->dato;
    if(this->esFinalPalabra() == true){
      cout << "\n";
    }
  }
  for(int i = 0; i < 26; i++){
    if(this->hijos[i] != nullptr)
      this->hijos[i]->printData();
  }
}

