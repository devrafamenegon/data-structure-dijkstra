#include <iostream>
#include <stdlib.h>

#include "tipos.h"

#include "vertice.cpp"
#include "adjacencia.cpp"

using namespace std;

class GRAFO {
private:
  int nVertices; // Número de vértices
  int nArestas; // Número de arestas
  VERTICE* arranjoVertices; // Arranjo de vértices

public:
  int getNVertices() {
    return nVertices;
  }

  void setNVertices(int nVertices) {
    this->nVertices = nVertices;
  }

  int getNArestas() {
    return nArestas;
  }

  void setNArestas(int nArestas) {
    this->nArestas = nArestas;
  }

  VERTICE* getArranjoVertices() {
    return arranjoVertices;
  }

  void setArranjoVertices(VERTICE* arranjoVertices) {
    this->arranjoVertices = arranjoVertices;
  }

  GRAFO() {
    cout << "Necessario informar o numero de vertices" << endl;
    cout << "Programa sera encerrado" << endl << endl;
    exit(-1);
  }

  /*
    1. Com um número fixo de vértices

    2. Alocamos espaço para a estrutura

    3. Inicializamos o total de vértices e
    arestas

    4. Dentro do Grafo há apenas um
    ponteiro para o arranjo de
    vértices, não o arranjo em si

    5. Temos que alocar o arranjo com
    o número de vértices desejado

    6. Uma vez alocada em memória,
    atribuímos NULL
  */
  GRAFO(int nVertices) {
    setNVertices(nVertices); // 1.
    setNArestas(0);
    setArranjoVertices(new VERTICE[nVertices]); // 2.
    
    // 3. 4. 5.
    for (int i = 0; i < nVertices; i++) {
      getArranjoVertices()[i].setAdjacencias(NULL); // 6.
    }
  }

  bool criaAresta(int verticeOrigem, int verticeDestino, PESO peso) {
    if (!saoValoresValidos(verticeOrigem, verticeDestino)) return false;

    ADJACENCIA *novaAdj = new ADJACENCIA(verticeDestino, peso);

    novaAdj->setProximaAdjacencia(
      getArranjoVertices()[verticeOrigem].getAdjacencias()
    );

    getArranjoVertices()[verticeOrigem].setAdjacencias(novaAdj);

    setNArestas(getNArestas() + 1);

    return true;
  }

  bool saoValoresValidos(int verticeOrigem, int verticeDestino) {
    if (verticeDestino < 0 || verticeDestino >= nVertices)
      return false;

    if (verticeOrigem < 0 || verticeOrigem >= nVertices)
      return false;

    return true;
  }

  void imprime() {
    cout << "Vertices: " << getNVertices() << ", Aresta: " << getNArestas() << endl;

    for (int i = 0; i < getNVertices(); i++) {
      cout << "v" << i << ": ";
      
      ADJACENCIA *ad = arranjoVertices[i].getAdjacencias();

      while (ad) {
        cout << "v" << ad->getVerticeDestino() << "(" << ad->getPesoAteVerticeDestino() << ") ";
        ad = ad->getProximaAdjacencia();
      }

      cout << endl;
    }
  }
};
