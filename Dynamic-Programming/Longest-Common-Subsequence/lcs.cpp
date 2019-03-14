#include <iostream>
#include <string.h>

#define SIZE 1010

using namespace std;

string s1, s2;
int dp[SIZE][SIZE];

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
    memset(dp, -1, sizeof dp);

    cin >> s1 >> s2;
    cout << lcs(0,0) << endl;

    return 0;
}