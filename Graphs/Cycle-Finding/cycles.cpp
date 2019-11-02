/**
 * Cycle Finding
 *
 * Encontrar ciclos em um grafo direcionado.
 * Testado em: https://www.urionlinejudge.com.br/judge/pt/problems/view/1610
 */

#include <bits/stdc++.h>
#define MAXN 10100

using namespace std;

vector<int> graph[MAXN];
bool see[MAXN];
bool path[MAXN];

/*
 * Um grafo contém ciclos se existir uma aresta que vai do vértice atual para
 * um vértice "acima". Um vértice "acima" é um vértice que pertence ao caminho
 * formado até o momento pela busca.
 */
bool dfs(int v) {
    see[v] = true;
    path[v] = true;

    for (int u : graph[v]) {
        if (path[u])
            return true;

        if (see[u])
            continue;

        if (dfs(u))
            return true;
    }

    path[v] = false;
    return false;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        for (int i = 1; i <= n; i++) {
            path[i] = false;
            see[i] = false;
            graph[i].clear();
        }

        while (k--) {
            int a, b;
            scanf("%d %d", &a, &b);

            graph[a].push_back(b);
        }

        bool b = false;

        for (int i = 1; i <= n && !b; i++) {
            if (!see[i])
                b = dfs(i);
        }

        printf("%s\n", b ? "SIM" : "NAO");
    }

    return 0;
}