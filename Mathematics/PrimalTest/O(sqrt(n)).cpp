/*
     Teste de primo em O(sqrt(n)) e memoria O(1)
     Codigo testado em: https://www.urionlinejudge.com.br/judge/pt/problems/view/1221
*/
#include <bits/stdc++.h>

using namespace std;


int isPrime(int n){
    for(int i = 2; i * i <= n; i++)
            if(n % i == 0)
                return 0;
    
    return 1;
}

int main(){
    int n, k;
    cin >> k;
    while(k--){
        cin >> n;
        if(isPrime(n))
            cout  << "Prime\n";
        else
            cout << "Not Prime\n";
        
    }
    return 0;
}