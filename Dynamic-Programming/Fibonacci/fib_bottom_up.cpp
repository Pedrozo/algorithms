/**
 * Problema de fibonacci utilizando memoization bottom up
 * 
 * Tempo: O(n)
 * Espaço: O(n)
 */

#include <iostream>
#define SIZE 10000

using namespace std;

int dp[SIZE];

int fib(int n) {
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;

    cin >> n;
    cout << fib(n);

    return 0;
}