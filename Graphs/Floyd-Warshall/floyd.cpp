/**
 * Menor distância entre todos os pares de vértices
 * 
 * Testado em: https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem
 */

#include <bits/stdc++.h>
#define SIZE 500
#define INF (int) 1e9

using namespace std;

int grafo[SIZE][SIZE];

int main() {
    int n, m, queries, origem, destino, distancia;

    cin >> n >> m;

    // inicializa as distâncias como infinito para os pares de vértices
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grafo[i][j] = i == j ? 0 : INF;
        }
    }

    // lê as arestas do grafo
    for (int i = 1; i <= m; i++) {
        cin >> origem >> destino >> distancia;

        grafo[origem][destino] = distancia;
    }

    // Floyd Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grafo[i][j] = min(grafo[i][j], grafo[i][k] + grafo[k][j]);
            }
        }
    }

    cin >> queries;

    while (queries--) {
        cin >> origem >> destino;
        distancia = grafo[origem][destino];

        cout << (distancia == INF ? -1 : distancia) << endl;
    }

    return 0;
}