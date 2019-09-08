/*
 * Algoritmo para encontrar componentes fortemente conexas
 * 
 * Testado: https://www.hackerearth.com/pt-br/practice/algorithms/graphs/strongly-connected-components/tutorial/
 */

#include <bits/stdc++.h>
#define SIZE 20

using namespace std;

int n;
vector<int> grafo[SIZE];
vector<int> reverso[SIZE];
list<int> pilha;
bool visto[SIZE];

void dfs(int v) {
    visto[v] = true;

    for (int u : grafo[v]) {
        if (!visto[u]) {
            dfs(u);
        }
    }

    pilha.push_back(v);
}

// os vértices que cada uma dessas buscas visitar, resulta em um componente
// retorna a quantidade de vértices no componente desse vértice
int dfs2(int v) {
    int c = 1;

    visto[v] = true;

    for (int u : reverso[v]) {
        if (!visto[u]) {
            c += dfs2(u);
        }
    }

    return c;
}

int main() {
    int m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        reverso[b].push_back(a);
    }

    for (int v = 1; v <= n; v++)
        if (!visto[v])
            dfs(v);
    
    memset(visto, false, sizeof(visto));

    int par = 0, impar = 0;

    while (!pilha.empty()) {
        int v = pilha.back();
        pilha.pop_back();

        if (!visto[v]) {
            int c = dfs2(v);

            if (c & 1)
                impar += c;
            else
                par += c;
        }
    }

    cout << impar - par << endl;

    return 0;
}