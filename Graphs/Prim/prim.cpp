/**
 * Árvore geradora de custo mínimo
 * 
 * Testado em: https://www.hackerearth.com/pt-br/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
 */

#include <bits/stdc++.h>
#define pii pair<int, int>
#define SIZE 10100

using namespace std;

int n;
bool proc[SIZE];
vector<pii> adj[SIZE];

int prim(int s) {
    int cost = 0;
    priority_queue<pii, vector<pii>, greater<pii>> fila;

    for (int i = 0; i < n; i++)
        proc[i] = false;

    fila.push(make_pair(0, s));

    while (!fila.empty()) {
        int v, c;

        c = fila.top().first;
        v = fila.top().second;
        fila.pop();

        if (proc[v])
            continue;

        proc[v] = true;
        cost += c;

        for (pii p : adj[v]) {
            int u = p.second;

            if (!proc[u])
                fila.push(p);
        }
    }

    return cost;
}

int main() {
    int m;
    
    cin >> n >> m;

    while (m--) {
        int u, v, h;
        cin >> u >> v >> h;

        adj[u].push_back(make_pair(h, v));
        adj[v].push_back(make_pair(h, u));
    }

    cout << prim(1) << endl;

    return 0;
}