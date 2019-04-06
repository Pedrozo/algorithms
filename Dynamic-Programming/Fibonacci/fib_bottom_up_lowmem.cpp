/**
 * Problema de fibonacci utilizando memoization bottom up
 * 
 * Tempo: O(n)
 * Espaço: O(1)
 */

#include <iostream>

using namespace std;

int fib(int n) {
    int p = 0;
    int q = 1;

    for (int i = 2; i <= n; i++) {
        int t = q;
        q = q + p;
        p = t;
    }

    return n ? q : 0; // para o caso base funcionar
}

int main() {
    int n;

    cin >> n;
    cout << fib(n);

    return 0;
}