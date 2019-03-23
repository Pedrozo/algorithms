#include <iostream>

#define SIZE 1000

using namespace std;

int A[SIZE];
int tree[SIZE * 4];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = A[start] == 0;
        return;
    }

    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int index, int value) {
    if (start == end) {
        A[start] = value;
        tree[node] = value == 0;
        return;
    }

    int mid = (start + end) / 2;

    if (index <= mid) {
        update(node * 2, start, mid, index, value);
    } else {
        update(node * 2 + 1, mid + 1, end, index, value);
    }

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int count_zeros(int node, int start, int end, int l, int r) {
    if (l > end || r < start) {
        return 0;
    }

    if (l <= start && r >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int a = count_zeros(node * 2, start, mid, l, r);
    int b = count_zeros(node * 2 + 1, mid + 1, end, l, r);
    return a + b;
}

int search(int node, int start, int end, int k) {
    if (start == end) {
        return start;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (start + end) / 2;
    
    if (k <= tree[left]) {
        return search(left, start, mid, k);
    } else {
        return search(right, mid + 1, end, k - tree[left]);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    build(1, 1, n);

    char op;
    int a, b;

    while (true) {
        cin >> op >> a;

        if (op != 's' && op != 'S') {
            cin >> b;
        }

        switch (op) {
            case 'U':
            case 'u':
                update(1, 1, n, a, b);
                break;
            
            case 'q':
            case 'Q':
                cout << count_zeros(1, 1, n, a, b) << endl;
                break;
            
            case 's':
            case 'S':
                cout << search(1, 1, n, a) << endl;
                break;
        }
    }
    
    return 0;
}