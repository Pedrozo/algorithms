#include <bits/stdc++.h>
#define pii pair<int, int>
#define SIZE 100100

using namespace std;

int n; // quantidade de vértices
vector<pii> grafo[SIZE];

/*
height = altura de cada nó
euler  = ordem em que os nós são visitados durante a busca em profundidade, com repetições
first  = indice que o nó parece pela primeira vez em 'euler' (f[i] = primeira ocorrencia do nó i em euler)
*/
vector<int> height, euler, first, segtree;
vector<bool> visited;

void init();
void dfs(int v, int h);
void build(int node, int start, int end);
int query(int node, int start, int end, int l, int r);
int lca(int u, int v);

void init() {
    height.resize(n);
    first.resize(n);
    euler.resize(n * 2);
    visited.assign(n, false);

    dfs(1, 0);

    int m = euler.size();
    segtree.resize(m * 4); // sei la por que vezes 4...

    build(1, 0, m - 1);
}

void dfs(int v, int h) {
    visited[v] = true;
    height[v] = h;
    first[v] = euler.size(); // ultima posição de euler

    for (pii p : grafo[v]) {
        int u = p.second;
        int d = p.first;

        if (!visited[u]) {
            dfs(u, h + 1);
            euler.push_back(v);
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

        int l = segtree[node * 2];
        int r = segtree[node * 2 + 1];

        segtree[node] = (height[l] < height[r]) ? l : r;
    }
}

int query(int node, int start, int end, int l, int r) {
    // os intervalos estão totalmente fora um do outro
    if (r < start || l > end) {
        return -1;
    }

    // o intervalo start-end esta totalmente dentro do intervalo l-r
    if (l <= start && r >= end) {
        return segtree[node];
    }

    // os intervalos estão parcialmente dentro um do outro
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
    
    return query(1, 0, euler.size() - 1, left, right);
}

int main() {
    n = 11;

    grafo[1].push_back(make_pair(1, 2));
    grafo[1].push_back(make_pair(1, 3));

    grafo[2].push_back(make_pair(1, 1));
    grafo[2].push_back(make_pair(1, 4));
    grafo[2].push_back(make_pair(1, 5));

    grafo[3].push_back(make_pair(1, 1));
    grafo[3].push_back(make_pair(1, 6));
    grafo[3].push_back(make_pair(1, 7));

    grafo[4].push_back(make_pair(1, 2));

    grafo[5].push_back(make_pair(1, 2));
    grafo[5].push_back(make_pair(1, 8));
    grafo[5].push_back(make_pair(1, 9));
    grafo[5].push_back(make_pair(1, 10));

    grafo[6].push_back(make_pair(1, 3));
    grafo[6].push_back(make_pair(1, 11));

    grafo[7].push_back(make_pair(1, 3));

    grafo[8].push_back(make_pair(1, 5));

    grafo[9].push_back(make_pair(1, 5));

    grafo[10].push_back(make_pair(1, 5));

    grafo[11].push_back(make_pair(1, 6));

    init();
    
    return 0;
}