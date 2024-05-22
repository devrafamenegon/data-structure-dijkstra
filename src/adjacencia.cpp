#ifndef ADJACENCIA_CPP
#define ADJACENCIA_CPP

#include <iostream>
#include <stdlib.h>

#include "tipos.h"

using namespace std;

class ADJACENCIA {
private:
  int verticeDestino; // Vértice de destino
  PESO pesoAteVerticeDestino; // Peso associado à aresta que leva ao vértice destino
  ADJACENCIA* proximaAdjacencia; // Próximo elemento na lista de adjacências

public:
  int getVerticeDestino() {
    return verticeDestino;
  }

  void setVerticeDestino(int verticeDestino) {
    this->verticeDestino = verticeDestino;
  }

  PESO getPesoAteVerticeDestino() {
    return pesoAteVerticeDestino;
  }

  void setPesoAteVerticeDestino(PESO pesoAteVerticeDestino) {
    this->pesoAteVerticeDestino = pesoAteVerticeDestino;
  }

  ADJACENCIA* getProximaAdjacencia() {
    return proximaAdjacencia;
  }

  void setProximaAdjacencia(ADJACENCIA* proximaAdjacencia) {
    this->proximaAdjacencia = proximaAdjacencia;
  }

  ADJACENCIA(int verticeDestino, int pesoAteVerticeDestino) {
    setVerticeDestino(verticeDestino);
    setPesoAteVerticeDestino(pesoAteVerticeDestino);
    setProximaAdjacencia(NULL);
  }
};

#endif