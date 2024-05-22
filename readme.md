# Implementação do Algoritmo de Dijkstra

## Introdução

O algoritmo de Dijkstra é um algoritmo de busca de caminho mais curto em um grafo com pesos não negativos. É amplamente utilizado em problemas de roteamento e navegação, como encontrar o caminho mais curto entre duas cidades em um mapa rodoviário.

## Algoritmo de Dijkstra

### Descrição

O algoritmo de Dijkstra encontra o caminho mais curto de um nó inicial para todos os outros nós em um grafo. Ele mantém um conjunto de nós cuja distância mínima do nó inicial já é conhecida e, iterativamente, encontra o nó mais próximo que ainda não foi processado, atualizando as distâncias dos seus vizinhos.

### Pseudocódigo

```plaintext
Função Dijkstra(grafo, início):
    criar um dicionário distâncias com valor infinito para todos os nós
    definir distâncias[início] = 0
    criar um conjunto vazio processados
    criar uma fila de prioridade e adicionar início com prioridade 0

    enquanto a fila de prioridade não estiver vazia:
        nó_atual = remover nó com menor distância da fila de prioridade
        se nó_atual em processados:
            continuar para o próximo nó

        adicionar nó_atual ao conjunto processados

        para cada vizinho, peso em vizinhos do nó_atual:
            distância = distâncias[nó_atual] + peso
            se distância < distâncias[vizinho]:
                distâncias[vizinho] = distância
                adicionar vizinho à fila de prioridade com prioridade distância

    retornar distâncias
```

### Como Executar

1. Crie uma função ou um programa seguindo o pseudocódigo acima.
2. Teste o algoritmo com um grafo de exemplo.

## Exemplo de Uso

Considere um grafo representado como um dicionário, onde as chaves são os nós e os valores são listas de tuplas representando os vizinhos e os pesos das arestas.

```plaintext
grafo = {
    'A': [('B', 1), ('C', 4)],
    'B': [('A', 1), ('C', 2), ('D', 5)],
    'C': [('A', 4), ('B', 2), ('D', 1)],
    'D': [('B', 5), ('C', 1)]
}

resultado = Dijkstra(grafo, 'A')
print(resultado)  # Output esperado: {'A': 0, 'B': 1, 'C': 3, 'D': 4}
```

### Considerações

- O algoritmo de Dijkstra é eficiente para grafos densos e quando todas as arestas têm pesos não negativos.
- Em casos onde o grafo possui arestas com pesos negativos, o algoritmo de Bellman-Ford deve ser utilizado em vez de Dijkstra.

## Conclusão

Neste projeto, explicamos o algoritmo de Dijkstra e fornecemos um pseudocódigo detalhado para sua implementação. O algoritmo é essencial para encontrar caminhos mais curtos em grafos ponderados com pesos não negativos, e é amplamente aplicado em problemas de roteamento e navegação.

## Autor

Rafael Henrique Menegon
