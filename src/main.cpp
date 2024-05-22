#include <iostream>

#include "dfs.cpp"

using namespace std;

int main() {
  DFS *grafo = new DFS(5);
  grafo->criaAresta(0, 1, 2);
  grafo->criaAresta(1, 2, 4);
  grafo->criaAresta(2, 0, 12);
  grafo->criaAresta(2, 4, 40);
  grafo->criaAresta(3, 1, 3);
  grafo->criaAresta(4, 3, 8);

  grafo->getArranjoVertices()[0].setChave(10);
  grafo->getArranjoVertices()[1].setChave(11);
  grafo->getArranjoVertices()[2].setChave(11);
  
  grafo->imprime();

  grafo->profundidade(9);
  grafo->profundidade(10);
  grafo->profundidade(11);
  
  return 0;
}