/*
 * Lowest Common Ancestor
 *
 * Encontra o ancestral comum mais próximo utilizando tour de euler e arvore de segmentos
 *
 * Testado: https://www.urionlinejudge.com.br/judge/pt/problems/view/1135
 * Para melhor entendimento: https://www.hackerrank.com/topics/lowest-common-ancestor e  https://cp-algorithms.com/graph/lca.html
 */

#include <bits/stdc++.h>
#define DEBUG(t) cout << #t << " " << t << endl
#define pii pair<int, int>
#define SIZE 100100

using namespace std;

int n; // quantidade de vértices
int e; // tamanho de euler
vector<pii> grafo[SIZE];

/*
height = altura de cada nó
euler  = ordem em que os nós são visitados durante a busca em profundidade, com repetições
first  = indice que o nó parece pela primeira vez em 'euler' (f[i] = primeira ocorrencia do nó i em euler)
*/
int segtree[SIZE * 8];
long long int dist[SIZE];
int euler[SIZE * 2];
int height[SIZE];
int first[SIZE];

void init();
void dfs(int v, int h);
void build(int node, int start, int end);
int query(int node, int start, int end, int l, int r);
int lca(int u, int v);

void init() {
    memset(dist, -1, n * sizeof(long long int));

    e = 1;
    euler[0] = 0;
    dist[0] = 0;

    dfs(0, 0);

    build(1, 0, e - 1);
}

void dfs(int v, int h) {
    height[v] = h;
    first[v] = e - 1; // ultima posição de euler

    for (pii p : grafo[v]) {
        int u = p.second;
        int d = p.first;

        if (dist[u] == -1) {
            dist[u] = dist[v] + d;
            euler[e++] = u;
            dfs(u, h + 1);
            euler[e++] = v;
        }
    }
}

void build(int node, int start, int end) {
    if (start == end) {
        segtree[node] = euler[start];
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);

        int left = segtree[node * 2];
        int right = segtree[node * 2 + 1];

        segtree[node] = (height[left] < height[right]) ? left : right;
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || l > end) {
        return -1;
    }

    if (l <= start && r >= end) {
        return segtree[node];
    }

    int mid = (start + end) / 2;
    int left = query(node * 2, start, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, end, l, r);
    
    if (left == -1)
        return right;
    
    if (right == -1)
        return left;
    
    return (height[left] < height[right]) ? left : right;
}

int lca(int u, int v) {
    int left = first[u];
    int right = first[v];

    if (left > right)
        swap(left, right);
    
    return query(1, 0, e - 1, left, right);
}

int main() {
    while (true) {
        cin >> n;

        if (!n)
            break;

        for (int i = 0; i < n; i++) {
            grafo[i].clear();
        }

        for (int v = 1; v <= n - 1; v++) {
            int u, d;
            scanf("%d %d", &u, &d);

            grafo[u].push_back(make_pair(d, v));
            grafo[v].push_back(make_pair(d, u));
        }

        init();

        int q;
        scanf("%d", &q);

        for (int i = 0; i < q; i++) {
            int u, v, a;
            scanf("%d %d", &u, &v);

            a = lca(u, v);

            if (i) {
                printf(" ");
            }

            cout << (dist[u] - dist[a]) + (dist[v] - dist[a]);
        }

        cout << endl;
    }
    
    return 0;
}