/*
    Convex Hull, pega os pontos que tem uma orientação mais a esquerda do ponto que tem o x menor
    faz isso para os proximos pontos até voltar para o inicial
    Codigo testado em: https://www.urionlinejudge.com.br/judge/pt/problems/view/1982
*/
#include<bits/stdc++.h>

using namespace std;
struct point{
    double x, y;
};
struct point vet[2002];

double pow(double a){
	return a * a;
}

double dist(point p, point q){
    return sqrt(pow(q.x - p.x) + pow(q.y - p.y));
}

double orientation(point p, point q, point r){
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return val;
}

double convex(int n){
    int p = 0, q;
    double resp = 0;
    do{
        q = (p + 1) % n;
        for(int i = 0; i < n; i++)
            if(orientation(vet[p], vet[q], vet[i]) < 0)
                q = i;
        
        resp += dist(vet[p], vet[q]);// Soma o perimetro do poligono formado pelos pontos
        p = q;
    }while(p);

    return resp;
}

bool compare(point a, point b){
    if(a.x == b.x)
        return a.y < b.y;
    
    return a.x < b.x;
}

int main(){
    int n;
    while(scanf(" %d", &n) != EOF && n){
        for(int i = 0; i < n; i++)
            cin >> vet[i].x >> vet[i].y;
        
        sort(vet, vet + n, compare);

        printf("Tera que comprar uma fita de tamanho %.2f.\n", convex(n));
    }
    return 0;
}