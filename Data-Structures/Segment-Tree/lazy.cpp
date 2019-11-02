/**
 * Range Sum Query com Lazy Propragation
 * 
 * Cada query retorna a soma em um determinado intervalo
 * Os updates são feitos em intervalos
 * 
 * Testado em: https://www.urionlinejudge.com.br/judge/pt/problems/view/1500
 */

#include <bits/stdc++.h>
#define SIZE 100100

using namespace std;

int n;
long long int tree[4 * SIZE];
long long int lazy[4 * SIZE];

/**
 * Soma um valor em todos os nós de um intervalo
 * 
 * Complexidade: O(log n)
 * 
 * node - nó atual da arvore
 * start - posição inicial atual do intervalo no vetor
 * end - posição final atual do intervalo no vetor
 * l - indice inicial do intervalo que sera somado
 * r - indice final do intervalo que sera somado
 * value - valor do elemento a ser atualizado no vetor
 */
void update(int node, int start, int end, int l, int r, int value) {
    long long int len = (end - start + 1);
    int mid = (start + end) / 2;

    int left_node = 2 * node;
    int right_node = 2 * node + 1;

    if (lazy[node]) {
        tree[node] += lazy[node] * len;

        if (start != end) {
            lazy[left_node] += lazy[node];
            lazy[right_node] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (l > end || r < start) {
        return;
    }

    if (l <= start && end <= r) {
        tree[node] += value * len;

        if (start != end) {
            lazy[left_node] += value;
            lazy[right_node] += value;
        }
    } else {
        update(left_node, start, mid, l, r, value);
        update(right_node, mid + 1, end, l, r, value);

        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update(int a, int b, int value) {
    update(1, 1, n, a, b, value);
}

/**
 * Retorna o menor dos elementos no intervalo de l até r
 * 
 * Complexidade: O(log n)
 *
 * node - nó atual da arvore
 * start - posição inicial atual do intervalo no vetor
 * end - posição final atual do intervalo no vetor
 * l - posição inicial do intervalo que será somado
 * r - posição final do intevalo que será somado
 */
long long int query(int node, int start, int end, int l, int r) {
    long long int len = (end - start + 1);
    int mid = (start + end) / 2;

    int left_node = 2 * node;
    int right_node = 2 * node + 1;

    if (lazy[node]) {
        tree[node] += lazy[node] * len;

        if (start != end) {
            lazy[left_node] += lazy[node];
            lazy[right_node] += lazy[node];
        }

        lazy[node] = 0;
    }

    // os intervalos estão totalmente fora um do outro
    if (r < start || l > end) {
        return 0;
    }

    // o intervalo start-end esta totalmente dentro do intervalo l-r
    if (l <= start && r >= end) {
        return tree[node];
    }

    // os intervalos estão parcialmente dentro um do outro
    long long int p1 = query(left_node, start, mid, l, r);
    long long int p2 = query(right_node, mid + 1, end, l, r);

    return p1 + p2;
}

long long int query(int l, int r) {
    return query(1, 1, n, l, r);
}

int main() {
    int tests;
    scanf("%d", &tests);

    while (tests--) {
        int c;
        scanf("%d %d", &n, &c);

        memset(tree, 0, sizeof(long long int) * (n + 1) * 4);
        memset(lazy, 0, sizeof(long long int) * (n + 1) * 4);

        while (c--) {
            int op;
            int p, q, v;
            scanf("%d", &op);

            switch (op) {
                case 0:
                    scanf("%d %d %d", &p, &q, &v);

                    if (p > q)
                        swap(p, q);

                    update(p, q, v);
                    break;
                
                case 1:
                    scanf("%d %d", &p, &q);

                    if (p > q)
                        swap(p, q);
                    
                    printf("%lli\n", query(p, q));
                    break;
            }
        }
    }
    
    return 0;
}