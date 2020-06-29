/**
 * Range Sum Query
 * 
 * Cada query retorna a soma em um determinado intervalo
 */
#include <iostream>

using namespace std;

int n;
int A[100];
int tree[1000];

/**
 * Cria a arvore de segmentos
 * 
 * node - nó atual da arvore
 * start - posição inicial do intervalo do vetor
 * end - posição final do intervalo do vetor
 */
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = A[start];
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void build() {
    build(1, 1, n);
}

/**
 * Atualiza o valor de um dos nós
 * 
 * Complexidade: O(log n)
 * 
 * node - nó atual da arvore
 * start - posição inicial atual do intervalo no vetor
 * end - posição final atual do intervalo no vetor
 * index - indice do elemento a ser atualizado no vetor
 * value - valor do elemento a ser atualizado no vetor
 */
void update(int node, int start, int end, int index, int value) {
    if (start == end) {
        A[index] = value;
        tree[node] = value;
    } else {
        int mid = (start + end) / 2;
        
        if (index >= start && index <= mid) {
            update(node * 2, start, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, end, index, value);
        }
        
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(int index, int value) {
    update(1, 1, n, index, value);
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
int query(int node, int start, int end, int l, int r) {
    // os intervalos estão totalmente fora um do outro
    if (r < start || l > end) {
        return 0;
    }

    // o intervalo start-end esta totalmente dentro do intervalo l-r
    if (l <= start && r >= end) {
        return tree[node];
    }

    // os intervalos estão parcialmente dentro um do outro
    int mid = (start + end) / 2;
    int p1 = query(node * 2, start, mid, l, r);
    int p2 = query(node * 2 + 1, mid + 1, end, l, r);
    return p1 + p2;
}

int query(int l, int r) {
    return query(1, 1, n, l, r);
}

int main() {
    char op;
    int a, b;
    
    cin >> n;

    // A[0] não é utilizado
    // elementos vão de A[1] até A[n]
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    build();

    // até EOF
    while (cin >> op >> a >> b) {
        switch (op) {

            // update
            // elemento na posição a é alterado para o valor b
            case 'u':
            case 'U':
                update(a,b);
                break;

            // query
            // soma dos elementos da posição a até b
            case 'q':
            case 'Q':
                cout << query(a,b) << endl;
                break;
        }
    }
    
    return 0;
}