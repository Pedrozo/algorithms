/*
    Algoritimo soma maxima de elementos contiguos tempo O(n) espaço O(1)
    Codigo testado em: https://www.urionlinejudge.com.br/judge/en/problems/view/2917
*/
#include <bits/stdc++.h>

using namespace std;
int vet[1000000];

int somaMaxima(int n){
    int maximo = 0, maximo_global = 0, ini = n;
    for(int i = 0; i < n * 2 && i % n != ini; i++){
        if(maximo + vet[i % n] <= vet[i % n]){
            maximo = vet[i % n];
            ini = i;//Tomar cuidado para não somar numeros repitdos 
        }else
            maximo += vet[i % n];
        
        maximo_global = max(maximo_global, maximo);
    }

    return maximo_global;
}

int main(){
    int n;
    while(scanf(" %d", &n) != EOF){
        for(int i = 0; i < n * 10; i++)
            scanf(" %d", vet + i);

        cout << somaMaxima(n * 10) << endl;
    }
    return 0;
}
