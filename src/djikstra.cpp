#include <iostream>
#include <limits.h>

#include "grafo.cpp"
#include "tipos.h"

using namespace std;

class DIJKSTRA: public GRAFO {
private:
  int* distancias;
  int* predecessores;

public:
  DIJKSTRA() {
    cout << "Erro, informe o número de vértices";
    exit(-1);
  }

  DIJKSTRA(int nVertices): GRAFO(nVertices) {
    distancias = new int[nVertices];
    predecessores = new int[nVertices];
  }

  ~DIJKSTRA() {
    delete[] distancias;
    delete[] predecessores;
  }

  void inicializar(int origem) {
    for (int vertice = 0; vertice < this->getNVertices(); vertice++) {
      distancias[vertice] = INT_MAX / 2;
      predecessores[vertice] = -1;
    }
    distancias[origem] = 0;
  }

  void relaxa(int verticeOrigem, int verticeDestino) {
    VERTICE *vertices = this->getArranjoVertices();
    ADJACENCIA *adjacencia = vertices[verticeOrigem].getAdjacencias();

    while ((adjacencia) && (adjacencia->getVerticeDestino() != verticeDestino))
      adjacencia = adjacencia->getProximaAdjacencia();

    if (adjacencia) {
      if (distancias[verticeDestino] > distancias[verticeOrigem] + adjacencia->getPesoAteVerticeDestino()) {
        distancias[verticeDestino] = distancias[verticeOrigem] + adjacencia->getPesoAteVerticeDestino();
        predecessores[verticeDestino] = verticeOrigem;
      }
    }
  }

  bool existeVerticeAberto(const bool* verticesAbertos) {
    for (int i = 0; i < this->getNVertices(); i++)
      if (verticesAbertos[i]) return true;

    return false;
  }

  int obterVerticeComMenorDistancia(const bool* verticesAbertos) {
    int i;
    for (i = 0; i < this->getNVertices(); i++)
      if (verticesAbertos[i]) break;
      
    if (i == this->getNVertices()) return -1;

    int verticeComMenorDistancia = i;
    for (i = verticeComMenorDistancia + 1; i < this->getNVertices(); i++)
      if (verticesAbertos[i] && (distancias[verticeComMenorDistancia] > distancias[i]))
        verticeComMenorDistancia = i;

    return verticeComMenorDistancia;
  }

  void dijkstra(int origem) {
    bool* verticesAbertos = new bool[this->getNVertices()];

    inicializar(origem);

    for (int i = 0; i < this->getNVertices(); i++)
      verticesAbertos[i] = true;

    while (existeVerticeAberto(verticesAbertos)) {
      int verticeAtual = obterVerticeComMenorDistancia(verticesAbertos);
      verticesAbertos[verticeAtual] = false;

      VERTICE *vertices = this->getArranjoVertices();
      ADJACENCIA *adjacencia = vertices[verticeAtual].getAdjacencias();

      while (adjacencia) {
        relaxa(verticeAtual, adjacencia->getVerticeDestino());
        adjacencia = adjacencia->getProximaAdjacencia();
      }
    }

    delete[] verticesAbertos;
  }

  void imprimeCaminho(int vertice) {
    if (predecessores[vertice] == -1) {
      cout << vertice;
      return;
    }

    imprimeCaminho(predecessores[vertice]);
    cout << "->" << vertice;
  }

  void imprimirResultados() {
    for (int vertice = 0; vertice < this->getNVertices(); vertice++) {
      cout << "Distancia (V0 -> V" << vertice << ") = " << distancias[vertice] << " => Caminho ";
      imprimeCaminho(vertice);
      cout << endl;
    }
  }

  int getDistancia(int vertice) const {
    return distancias[vertice];
  }
};