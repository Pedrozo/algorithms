# Tree Vertex Ancestrality

## Objetivos
* Em uma [árvore](https://en.wikipedia.org/wiki/Tree_(graph_theory)), checar se um vértice é ancestral de um outro vértice.

## Complexidade
* *O(n)*, onde *n* é o número de vértices.

## Implementação
```c++
vector<int> adj[MAX_N]; // lista de adjacência
int entry[MAX_N];       // momento de chegada no vértice
int egress[MAX_N];      // momento de saída do vértice

/* adiciona uma aresta entre os vértices u e v */
void connect(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/* se o vértice u é ancestral do vértice v */
bool is_ancestral(int u, int v) {
    return entry[u] < entry[v] && egress[u] > egress[v];
}

/* busca em profundidade que salva o momento de chegada e saída de cada vértice */
void dfs(int v) {
    static int timer = 0;

    entry[v] = ++timer;
    for (int u : adj[v]) {
        if (!entry[u])
            dfs(u);
    }
    egress[v] = ++timer;
}
```

## Referências
* [CP Algorithms](https://cp-algorithms.com/graph/depth-first-search.html)