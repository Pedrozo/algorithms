/*
    Algoritimo Convex Hull com otimização de tempo, de O(n^2) vai para O(N logN)
    O truque é a forma em que a ordenação é feita, colocando os melhores candidatos proximos
    Assim depois de ordenar fazemos uma abordagem linear sobre os pontos

    Codigo testado em: https://www.urionlinejudge.com.br/judge/en/problems/view/2541
*/
#include <bits/stdc++.h>
using namespace std;

struct Point { 
    int x, y;
};
Point vet[100100], v[100100];

double distSq(Point p1, Point p2) {
    return hypotl((p1.x - p2.x), (p1.y - p2.y));
}

double area(Point p, Point q, Point r) {
    double distpq = distSq(p, q), distpr = distSq(p, r), distqr = distSq(q, r);
    double a = (distpq + distpr + distqr) / 2;
    return sqrt(a * (a - distpq) * (a - distpr) * (a - distqr));
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return val;
}

int compare(const void *vp1, const void *vp2) {
    int o = orientation(vet[0], *((Point *)vp1), *((Point *)vp2));
    if (o == 0)
        return (distSq(vet[0], *((Point *)vp1)) <= distSq(vet[0], *((Point *)vp2)))? -1 : 1;

    return o;
}

double convexHull(int n) {
    double resp = 0;
    int ymin = vet[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        if ((vet[i].y < ymin) || (ymin == vet[i].y && vet[i].x < vet[min].x)) {
            ymin = vet[i].y;
            min = i;
        }
    }

    Point aux = vet[0];
    vet[0] = vet[min];
    vet[min] = aux;
    
    qsort(vet + 1, n - 1, sizeof(Point), compare);
    
    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(vet[0], vet[i], vet[i+1]) == 0) 
            i++;
        
        vet[m] = vet[i]; 
        m++;
    }

    v[0] = vet[0];
    v[1] = vet[1];
    v[2] = vet[2];

    int j = 2;
    for (int i = 3; i < m; i++) {
        while (orientation(v[j - 1], v[j], vet[i]) >= 0)
            j--;
        
        v[++j] = vet[i];
    }
    
    for (int i = 2; i <= j; i++) {
        resp += area(vet[0], v[i], v[i - 1]);
    }

    return resp;
}

int main() {
    int n;
    while (scanf(" %d", &n) != EOF && n) {
        for (int i = 0; i < n; i++)
            scanf(" %d %d", &vet[i].x, &vet[i].y);
        
        printf("%.2f\n", convexHull(n));
    }

    return 0;
}