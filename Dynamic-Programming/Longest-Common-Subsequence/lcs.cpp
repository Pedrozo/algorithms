/**
 * Longest Common Subsequence
 * 
 * Testado: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
 */
#include <iostream>
#include <string.h>

#define SIZE 101

using namespace std;

string s1, s2;
int dp[SIZE][SIZE];

/**
 * Maior subsequência comum das strings s1 e s2,
 * a partir dos indices i e j, respectivamente.
 */
int lcs(int i, int j) {
    if (i == s1.length() || j == s2.length())
        return 0;
    
    if (dp[i][j] != - 1)
        return dp[i][j];
    
    if (s1[i] == s2[j])
        return lcs(i + 1, j + 1) + 1;
    
    int a = lcs(i + 1, j);
    int b = lcs(i, j + 1);

    return dp[i][j] = max(a,b);
}

int main() {
    int quant, n, m;

    cin >> quant;
    memset(dp, -1, sizeof dp);

    while (quant--) {
        cin >> n >> m >> s1 >> s2;
        cout << lcs(0,0) << endl;
        memset(dp, -1, sizeof dp);
    }
    
    return 0;
}