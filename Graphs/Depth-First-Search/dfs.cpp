/**
 * Busca em profundidade para numerar os componentes conexos do grafo
 * 
 * Testado em: https://www.urionlinejudge.com.br/judge/pt/problems/view/1082
 */
#include <bits/stdc++.h>
#define SIZE 26

using namespace std;

int comp[SIZE];
vector<int> grafo[SIZE];

// apenas para converter um char para um indice do grafo
int vert(char c) {
    return (int) (c - 'a');
}

void dfs(int v) {
    for (int u : grafo[v]) {
        if (!comp[u]) {
            comp[u] = comp[v];
            dfs(u);
        }
    }
}

int main() {
    int tests;
    cin >> tests;

    for (int t = 1; t <= tests; t++) {
        int n, m;
        cin >> n >> m;

        // zera os componentes e o grafo
        for (int i = 0; i < n; i++) {
            comp[i] = 0;
            grafo[i].clear();
        }

        // preenche o grafo
        for (int i = 0; i < m; i++) {
            char a, b;
            cin >> a >> b;

            grafo[vert(a)].push_back(vert(b));
            grafo[vert(b)].push_back(vert(a));
        }

        // preenche os componentes
        int comps = 0;
        for (int i = 0; i < n; i++) {
            if (!comp[i]) {
                comp[i] = ++comps;
                dfs(i);
            }
        }

        printf("Case #%d:\n", t);
        
        for (int c = 1; c <= comps; c++) {
            for (int i = 0; i < n; i++) {
                if (comp[i] == c)
                    cout << (char) (i + 'a') << ',';
                
            }

            cout << endl;
        }
        
        printf("%d connected components\n\n", comps);
    }

    return 0;
}