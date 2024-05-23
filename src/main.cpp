#include <iostream>

#include "djikstra.cpp"

using namespace std;

int main() {
  DIJKSTRA* grafo = new DIJKSTRA(6);

  grafo->criaAresta(0, 1, 10);
  grafo->criaAresta(0, 2, 5);
  grafo->criaAresta(2, 1, 3);
  grafo->criaAresta(1, 3, 1);
  grafo->criaAresta(2, 3, 8);
  grafo->criaAresta(2, 4, 2);
  grafo->criaAresta(4, 5, 6);
  grafo->criaAresta(3, 5, 4);
  grafo->criaAresta(3, 4, 4);
  grafo->imprime();

  grafo->dijkstra(0);
  
  cout << "Menor distancia entre V0 e V5 = " << grafo->getDistancia(5) << endl;

  grafo->imprimirResultados();

  return 0;
}