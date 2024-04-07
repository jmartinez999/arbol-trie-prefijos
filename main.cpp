#include <iostream>
#include "arbol_trie.h"

using namespace std;

int main() {
  Arbol* arbol = new Arbol();
  cout << "Inicia prueba" << endl;
  arbol->insertarPalabra("hola");
  
  arbol->insertarPalabra("hoja");

  arbol->insertarPalabra("hombre");
  cout << "Fin prueba" << endl;

  cout <<"Resultado buscar hombre: " << arbol->buscarPalabra("hombre") << endl;
  cout <<"Resultado buscar homonimo: " << arbol->buscarPalabra("homonimo") << endl;
  
  arbol->imprimirPalabrasPorPrefijo("ho");
  //arbol->imprimirArbol();
  delete arbol;

}