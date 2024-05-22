#include <iostream>
#include <stdlib.h>

#include "tipos.h"

#include "adjacencia.cpp"

using namespace std;

class VERTICE {
private:
  CHAVE chave;
  ADJACENCIA* adjacencias; // Arranjo de vértices, onde cada
                           // vértice contém uma lista de suas adjacências.

public:
  ADJACENCIA* getAdjacencias() {
    return adjacencias;
  }

  void setAdjacencias(ADJACENCIA* adjacencias) {
    this->adjacencias = adjacencias;
  }

  CHAVE getChave() {
    return chave;
  }

  void setChave(CHAVE chave) {
    this->chave = chave;
  }
};
