/*
    A saida se da pela quantidade total de numeros, não é possivel pegar quais são esses numeros
    Codigo testado em: https://www.urionlinejudge.com.br/judge/en/problems/view/2919
*/
#include <bits/stdc++.h>

using namespace std;
vector<int> p;

int main() {
    int n;
    while (scanf(" %d", &n) != EOF) {
        int aux;
        for (int i = 0; i < n; i++) {
            scanf(" %d", &aux);
            
            if (!p.empty() && p.back() >  aux)
                *lower_bound(p.begin(), p.end(), aux) = aux;
            else
                if(p.empty() || p.back() < aux)
                    p.push_back(aux);
        }

        cout << p.size() << endl;
        p.clear();
    }

    return 0;
}