/*
    Da a menor distancia entre um set de pontos no plano
    Codigo testado em: https://www.urionlinejudge.com.br/judge/en/runs/code/15575668
*/
#include <bits/stdc++.h>

#define MAX 10001

using namespace std;
vector<pair<double, double> > vet;

double min(double a, double b){
    if(a > b)
        return b;
    
    return a;
}

double dist(pair<double, double> a, pair<double, double> b){
    double abf = a.first - b.first, abs = a.second - b.second;
    return sqrt(abf * abf + abs * abs);
}

double calc(int n, double mem){
    if(n < 0)
        return MAX;
    
    for(int i = n - 1; i >= 0 && vet[n].first - vet[i].first < mem; i--){
        mem = min(mem, dist(vet[i], vet[n]));
    }

    mem = min(mem, calc(n-1, mem));

    return min(mem, MAX);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        for(int i = 0; i < n; i++){
            double x, y;
            scanf("%lf %lf", &x, &y);
            vet.push_back(make_pair(x, y));
        }
        
        sort(vet.begin(), vet.end());

        double res = calc(n - 1, MAX);
        if(res > 10000)
            cout << "INFINITY\n";
        else
            printf("%.4f\n", res);
        
        vet.clear();
    }
    return 0;
}