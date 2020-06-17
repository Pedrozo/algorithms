# Bridges

## Objetivos
* Encontrar [pontes](https://en.wikipedia.org/wiki/Bridge_(graph_theory)) em grafos.

## Complexidade
* *O(n + m)*, onde *n* é o número de vértices e *m* de arestas.

## Implementação
```c++
int timer = 0;
vector<int> adj[MAX_N]; // lista de adjacência
int disc[MAX_N]; // o momento que o vértice foi descoberto

/* 
low[v] denota, na árvore obtida pela busca em profundidade, o vértice
mais antigo (i.e. descoberto primeiro na busca) que é possível alcançar
com uma aresta de volta (back-edge) a partir de v ou qualquer um de 
seus descendentes.
*/
int low[MAX_N];

/*
na árvore da busca, uma aresta (u, v) é uma ponte se nenhum vértice
da sub-árvore enraizada em v possuir uma aresta de volta para o 
vértice u ou algum de seus ancestrais
*/
void dfs(int u, int p = -1) {
    disc[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (!disc[v]) {
            // vértice não descoberto
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                printf("bridge: %d - %d\n", u, v);
        } else if (v != p) {
            // vértice já foi descoberto e não é o pai
            // ou seja, é uma aresta de volta (back-edge)
            low[u] = min(low[u], disc[v]);
        }
    }
}
```

## Referências
* [CP Algorithms](https://cp-algorithms.com/graph/bridge-searching.html)
* [Geeks for Geeks - Tree, Back, Edge and Cross Edges in DFS of Graph](https://www.geeksforgeeks.org/tree-back-edge-and-cross-edges-in-dfs-of-graph/)
* [Geeks for Geeks - Bridges in a graph](https://www.geeksforgeeks.org/bridge-in-a-graph/)