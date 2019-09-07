/**
 * Algoritmo KMP para buscar padrões em strings
 *
 * Testado: https://www.hackerearth.com/pt-br/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/problem-to-be-linked-with-kmp-tutorial-1/
 */

#include <bits/stdc++.h>
#define SIZE 100100

using namespace std;

void setLPS(string pat, int lps[]) {
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
            i++;
        }
    }
}

int kmp(string pat, string txt) {
    int count = 0;
    int lps[SIZE];

    setLPS(pat, lps);

    int i = 0, j = 0;
    while (i < txt.length()) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == pat.length()) {
            count++;
            j = lps[j - 1];
        } else if (i < txt.length() && txt[i] != pat[j]) {
            if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return count;
}


int main() {
    string txt;
    string pat;
    
    cin >> pat >> txt;

    cout << kmp(pat, txt) << endl;

    return 0;
}