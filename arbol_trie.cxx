#include "arbol_trie.h"
#include "nodo.h"


using namespace std;


Arbol::Arbol(){
  this->raiz = new Nodo();
}


Arbol::Arbol(char valor){
  this->raiz = new Nodo(valor, false);
}


void Arbol::insertarPalabra(string palabra){
  Nodo* auxiliar = this->raiz;
  bool bandera = false;
  for(int i = 0; i < palabra.length(); i++){
    if(i == palabra.length() - 1){
      bandera = true;
    }
    char letra = palabra[i];
    auxiliar = insertarNodo(auxiliar, letra, bandera);
  }  
}


Nodo* Arbol::insertarNodo(Nodo* padre, char valor,bool finalPalabra){
  Nodo* nodoAbuscar = padre->buscar(valor);
  int posicionAinsertar = valor - 97;
  if(nodoAbuscar == nullptr){
    //padre->hijos[posicionAinsertar] = new Nodo(valor, finalPalabra);
    Nodo* hijo = new Nodo(valor, finalPalabra);
    padre->crearNodoHijo(posicionAinsertar, hijo);
    return hijo;
  }
  else{
    return nodoAbuscar;
  }
}

bool Arbol::buscarPalabra(string palabra){
  Nodo* aux = this->raiz;
  for(int i = 0; i < palabra.length(); i++){
    char letra = palabra[i];
    aux = aux->buscar(letra);
    if(aux == nullptr){
      return false;
    }
  }
  return aux->esFinalPalabra() && aux != nullptr;
}

Nodo* Arbol::buscarPrefijo(string prefijo){
  Nodo* aux = raiz;
  for(int i = 0; i < prefijo.length(); i++){
    char letra = prefijo[i];
    aux = aux->buscar(letra);
    if(aux == nullptr){
      return nullptr;
    }
  }
  return aux;
}

void Arbol::imprimirPalabrasPorPrefijo(string prefijo){
  Nodo* aux = buscarPrefijo(prefijo);
  if(aux == nullptr){
    cout << "No hay palabras con ese prefijo en el arbol" << endl;
    return;
  }
  cout << "Prefijo encontrado" << endl;
  imprimirPalabrasRecursiva(aux, prefijo);
}

void Arbol::imprimirPalabrasRecursiva(Nodo* nodo, string prefijo){
  if(nodo == nullptr){
    return;
  }
  if(nodo->esFinalPalabra() == true){
    cout << "\n" << prefijo;
  }
  for(int i = 0; i < 26; i++){
    if(nodo->getHijo(i) != nullptr){
      char letra = i + 97;
      imprimirPalabrasRecursiva(nodo->getHijo(i), prefijo + string(1, letra));
    }
  }
}

void Arbol::imprimirArbol(){
  cout << "Imprimiendo arbol" << endl;
  raiz->printData();
  cout << "Fin de impresion" << endl;
}