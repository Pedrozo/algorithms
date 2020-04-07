#include <bits/stdc++.h>
#define SIZE 100100
#define DEBUG(t) cout << #t << ": " << t << endl

using namespace std;

int n, c, t;
int pipocas[SIZE];

bool possivel(int segundos) {
    int sum = 0;
    int comp = 0;
    long long int capacidade = (long long int) t * segundos; // capacidade de pipocas que cada competidor pode comer

    for (int s = 0; s < n; s++) {
        if (pipocas[s] > capacidade)
            return false;

        if (sum + pipocas[s] > capacidade) {
            comp++;
            sum = pipocas[s];
        } else {
            sum += pipocas[s];
        }
    }

    return comp < c;
}

int busca(int inicio, int fim) {
    if (inicio == fim) {
        return inicio;
    }

    int meio = (inicio + fim) / 2;

    if (possivel(meio)) {
        return busca(inicio, meio);
    } else {
        return busca(meio + 1, fim);
    }
}

int main() {
    cin >> n >> c >> t;

    for (int i = 0; i < n; i++) {
        cin >> pipocas[i];
    }

    cout << busca(1, (int) 1e9) << endl;

    return 0;
}