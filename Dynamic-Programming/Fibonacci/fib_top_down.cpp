/**
 * Problema de fibonacci utilizando memoization top down
 * 
 * Tempo: O(2^n)
 * Espaço: O(n)
 */

#include <iostream>
#define SIZE 10000

using namespace std;

int dp[SIZE];

int fib(int n) {
    if (n < 2) {
        return n;
    }

    if (dp[n])
        return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    cin >> n;
    cout << fib(n);

    return 0;
}