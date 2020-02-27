/**
 * Disjoint Sets (Union Find)
 * 
 * Testado em: https://www.hackerearth.com/pt-br/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/count-friends/
 */

#include <iostream>
#define MAX_SIZE 100100

using namespace std;

int set[MAX_SIZE];
int size[MAX_SIZE];

/**
 * Retorna o inteiro que representa o conjunto
 * do elemento "e". Path compression para complexidade O(1)
 * nas próximas chamadas
 */
int find(int e) {
    if (e == set[e])
        return e;
    
    return set[e] = find(set[e]);
}

/**
 * Une os elementos "a" e "b" para o mesmo conjunto
 */ 
void join(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;
    
    set[b] = a;
    size[a] += size[b];
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        set[i] = i;
        size[i] = 1;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        join(a, b);
    }

    for (int i = 1; i <= n; i++) {
        cout << (size[find(i)] - 1) << (i == n ? '\n' : ' ');
    }

    return 0;
}