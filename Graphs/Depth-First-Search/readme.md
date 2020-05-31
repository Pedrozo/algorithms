# Depth First Search

## Objetivos
* Em um [grafo](https://en.wikipedia.org/wiki/Graph_theory), a partir de uma vértice qualquer de origem, encontrar o primeiro caminho lexicográfico.
* Em uma [árvore](https://en.wikipedia.org/wiki/Tree_(graph_theory)), checar se um vértice é ancestral de um outro vértice.
* Em uma árvore, encontrar o [Menor Ancestral Comum](https://en.wikipedia.org/wiki/Lowest_common_ancestor) entre dois vértices.
* Encontrar [ciclos]((https://en.wikipedia.org/wiki/Cycle_graph)) em grafos.
* Encontrar [componentes fortemente conexos](https://en.wikipedia.org/wiki/Strongly_connected_component).
* Encontrar [arestas de corte](https://en.wikipedia.org/wiki/Bridge_(graph_theory)) (pontes) de um grafo.

## Aplicações e Variações
* [Ancestralidade de vértices em árvores](Tree-Vertex-Ancestrality/readme.md)
* 

## Complexidade
* *O(n + m)*, onde *n* é o número de vértices e *m* de arestas.

## Implementação
```c++
int n; // número de vértices
bool visitado[MAX_N]; // vértices já vistos na busca
vector<int> adj[MAX_N]; // lista de adjacência

/* adiciona uma aresta entre os vértices u e v */
void conectar(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/* busca em profundidade a partir do vértice v */
void dfs(int v) {
    visitado[v] = true;

    for (int u : adj[v]) {
        if (!visitado[v])
            dfs(u);
    }
}
```

## Problemas
* [Componentes Conexos - URI Online Judge](Problems/Componentes-Conexos.cpp)

## Referências
* [CP Algorithms](https://cp-algorithms.com/graph/depth-first-search.html)