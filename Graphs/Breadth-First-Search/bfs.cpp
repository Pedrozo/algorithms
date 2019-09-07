/*
 * Busca em Largura
 * 
 * Testado: https://www.hackerearth.com/pt-br/practice/algorithms/graphs/breadth-first-search/tutorial/
 */

#include <bits/stdc++.h>
#define SIZE 100100

using namespace std;

int n; // quantidade de vértices
int nivel[SIZE]; // nível de cada nó (também pode ser usado para saber a menor distância de um nó até o raiz)
int quant[SIZE]; // quantidade de nos em cada nivel
vector<int> grafo[SIZE];

void bfs(int s) {
    nivel[s] = 1;
    quant[1] = 1;
    
    list<int> fila;
    fila.push_back(s);

    while (!fila.empty()) {
        int v = fila.front();
        fila.pop_front();

        for (int u : grafo[v]) {
            if (!nivel[u]) {
                nivel[u] = nivel[v] + 1;
                quant[nivel[u]]++;
                fila.push_back(u);
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    bfs(1);

    int x;
    cin >> x;

    cout << quant[x] << endl;

    return 0;
}