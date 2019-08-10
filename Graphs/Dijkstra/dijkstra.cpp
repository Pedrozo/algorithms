/**
 * Dijkstra
 *
 * Menor distância entre um vértice e todos os outros
 * Testado em: https://www.hackerrank.com/challenges/dijkstrashortreach/problem
 */
#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF (int) 1e9
#define SIZE 10100

using namespace std;

int n;
int dist[SIZE];  // distância para o vértice
bool proc[SIZE]; // se o vértice já foi processado
vector<pii> adj[SIZE]; // lista de adjacência

/* Menor distância entre s e todos os outros vértices */
void dijkstra(int s) {
    // no pair o primeiro valor é a distância e o segundo o vértice
    priority_queue<pii, vector<pii>, greater<pii>> fila;

    fila.push(make_pair(0, s));

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        proc[i] = false;
    }

    dist[s] = 0;

    while (!fila.empty()) {
        int v = fila.top().second;
        fila.pop();

        if (proc[v]) {
            continue;
        }

        // todos os vizinhos de v
        for (pii p : adj[v]) {
            int u = p.second; // vértice
            int d = p.first;  // distância de v até u

            if (d + dist[v] < dist[u]) {
                proc[v] = true;
                fila.push(make_pair(d + dist[v], u));
                dist[u] = d + dist[v];
            }
        }
    }
}

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int e, s, i;
        cin >> n >> e;

        for (i = 0; i < e; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            adj[u].push_back(make_pair(d, v));
            adj[v].push_back(make_pair(d, u));
        }

        cin >> s;
        dijkstra(s);
        
        i = 1;

        if (dist[i] == 0)
            i++;
        
        cout << (dist[i] == INF ? -1 : dist[i]);
        i++;

        for (; i <= n; i++) {
            if (dist[i])
                cout << " " << (dist[i] == INF ? -1 : dist[i]);
        }

        cout << endl;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }

    return 0;
}