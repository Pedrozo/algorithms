/*
 * Problema da Mochila
 * 
 * Testado em: https://www.urionlinejudge.com.br/judge/pt/problems/view/1288
 */

#include <bits/stdc++.h>
#define SIZE 55
#define RESISTENCIA 10000

using namespace std;

int n;
int dano[SIZE];
int peso[SIZE];
int dp[SIZE][RESISTENCIA];
int resistencia;

int knap(int proj, int rest) {
    if (proj >= n) {
        return 0;
    }

    if (dp[proj][rest] != -1) {
        return dp[proj][rest];
    }

    int p1 = 0, p2 = 0;

    p1 = knap(proj + 1, rest);

    if (rest >= peso[proj])
        p2 = knap(proj + 1, rest - peso[proj]) + dano[proj];
    
    return dp[proj][rest] = max(p1, p2);
}

int main() {
    int quant;
    cin >> quant;

    while (quant--) {
        int capacidade;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> dano[i] >> peso[i];
        }

        cin >> capacidade >> resistencia;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= resistencia; j++) {
                dp[i][j] = -1;
            }
        }

        cout << (knap(0, capacidade) >= resistencia ? "Missao completada com sucesso" : "Falha na missao") << endl;
    }

    return 0;
}