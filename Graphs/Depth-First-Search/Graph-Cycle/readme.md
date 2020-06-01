# Graph Cycle

## Objetivos
* Encontrar [ciclos]((https://en.wikipedia.org/wiki/Cycle_graph)) em grafos.

## Complexidade
* *O(n + m)*, onde *n* é o número de vértices e *m* de arestas.

## Implementação
### Grafo Direcionado:
```c++
vector<int> adj[MAX_N]; // lista de adjacência
bool visited[MAX_N];    // se o vértice já foi visto na busca
bool path[MAX_N];       // se o vértice já foi visto durante o caminho

/* adiciona uma aresta do vértice u até v */
void connect(int u, int v) {
    adj[u].push_back(v);
}

/* 
 * diz se o grafo direcionado possui algum ciclo
 * isto é, se um vértice qualquer for adjacente a
 * um vertice já visto em seu caminho
 */
bool dfs(int v) {
    visited[v] = true;
    path[v] = true;

    for (int u : adj[v]) {
        if (path[u])
            return true;

        if (!visited[u] && dfs[u])
            return true;
    }

    path[v] = false;
    return false;
}
```

### Grafo Não-Direcionado:
```c++
vector<int> adj[MAX_N]; // lista de adjacência
int visited[MAX_N];     // se o vértice já foi visitado
int parent[MAX_N];      // parent[i] denota o vértice imediatamente visto antes de i (i.e. vértice pai)

/* adiciona uma aresta entre os vértices u e v */
void connect(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/* 
 * diz se o grafo não-direcionado possui algum ciclo
 * ou seja, se um vértice qualquer é adjacente a outro vértice
 * já visto durante a busca, excluindo o vértice visitado
 * imediatamente antes desse.
 */
bool dfs(int v) {
    visited[v] = true;

    for (int u : adj[v]) {
        if (visited[u]) {
            if (u != parent[v])
                return true;
        } else {
            parent[u] = v;
            if (dfs(u))
                return true;
        }
    }

    return false;
}
```

## Problemas
* [Dudu Faz Serviço - URI Online Judge](Problems/cycles.cpp)

## Referências
* [CP Algorithms](https://cp-algorithms.com/graph/finding-cycle.html)