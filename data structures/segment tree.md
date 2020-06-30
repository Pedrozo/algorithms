# Segment Tree

## Objetivo

* Realizar em tempo eficiente (logarítmico) as seguintes operações:
  * **Point Update**: atualizar o valor de um único elemento.
  * **Range Query**: buscar o valor de um prefixo qualquer de elementos. (soma dos elementos do prefixo, por exemplo)

## Compexidade
* **Point Update**: *O(log n)*
* **Range Query**: *O(log n)*

## Referências

* [CP Algorithms](https://cp-algorithms.com/data_structures/segment_tree.html)

## Implementação
**Importante:** A função *combine*, *make_data* e o tipo *data_t* podem ter diferentes implementações para levar a diferentes comportamentos da árvore de segmentos

Macros:
```c++
#define MAX_N 100100
#define left(x) ((x) * 2)
#define right(x) ((x) * 2 + 1)
```
Estrutura: (permite que o código fique mais limpo, a um pequeno custo de desempenho)
```c++
struct range_t {
    int lower;
    int upper;

    int mid() {
        return (lower + upper) / 2;
    }

    // se os extremos de s estão "dentro" deste segmento
    bool contains(range_t s) {
        return lower <= s.lower && upper >= s.upper;
    }
};
```

Variáveis Globais:
```c++
int n; // quantidade de elementos em arr
int arr[MAX_N];
data_t tree[MAX_N * 4];
```

Inicializar a árvore de segmentos:
```c++
void build(int node, range_t bounds) {
    if (bounds.lower == bounds.upper) {
        tree[node] = arr[bounds.lower];
        return;
    }

    build(left(node), {bounds.lower, bounds.mid()});
    build(right(node), {bounds.mid() + 1, bounds.upper});

    tree[node] = combine(tree[left(node)], tree[right(node)]);
}
```

Range Query:
```c++
data_t query(int node, range_t range, range_t query_range) {
    if (query_range.contains(range))
        return tree[node];

    data_t lq, rq;
    bool cl = query_range.lower <= range.mid();
    bool cr = query_range.upper > range.mid();

    if (cl)
        lq = query(left(node), {range.lower, range.mid()}, query_range);

    if (cr)
        rq = query(right(node), {range.mid() + 1, range.upper}, query_range);

    if (cl && cr)
        return combine(lq, rq);
    else if (cl)
        return lq;
    else
        return rq;
}
```

Point Update:
```c++
void update(int node, range_t range, int idx, int val) {
    if (range.lower == range.upper) {
        tree[node] = val;
        arr[range.lower] = val;
        return;
    }

    if (idx <= range.mid())
        update(left(node), {range.lower, range.mid()}, idx, val);
    else
        update(right(node), {range.mid() + 1, range.upper}, idx, val);

    tree[node] = combine(tree[left(node)], tree[right(node)]);
}
```

Como as funções *build*, *query* e *update* possuem valores padrões para os argumentos *node* e *range* na primeira chamada, é possível sobrecarregar essas funções a fim de facilitar sua utilização.
```c++
void build() {
    build(1, {1, n});
}

data_t query(int l, int u) {
    return query(1, {1, n}, {l, u});
}

void update(int idx, int val) {
    update(1, {1, n}, idx, val);
}
```

### Variações:
O grosso do algoritmo da árvore de segmentos é igual em suas variações. Abaixo estão possíveis comportamentos a partir de variações em *data_t*, *NEUTRAL* e *combine*.

Range Minimum Query - Menor elemento em um intervalo
```c++
typedef int data_t;

data_t make_data(int val) {
    return val;
}

data_t combine(data_t a, data_t b) {
    return min(a, b);
}
```

Range Sum Query - Soma de elementos em um intervalo:
```c++
typedef int data_t;

data_t make_data(int val) {
    return val;
}

data_t combine(data_t a, data_t b) {
    return a + b;
}

/*
 * retorna o míndice que define o menor prefixo em que a soma 
 * de seus elementos é igual ou maior que val
 */
int pref_sum(int node, range_t bnds, int val) {
    if (val > tree[node])
        return -1;
    
    if (bnds.lower == bnds.upper)
        return bnds.lower;
    
    if (val <= tree[left(node)])
        return pref_sum(left(node), {bnds.lower, bnds.mid()}, val);
    else
        return pref_sum(right(node), {bnds.mid() + 1, bnds.upper}, val - tree[left(node)]);
}

/* sobrecarga para utilização mais simples */
int pref_sum(int val) {
    return pref_sum(1, {1, n}, val);
}
```

O maior elemento, e a quantidade vezes que aparece:
```c++
/* o primeiro elemento do pair é o valor do elemento; o segundo, quantas vezes aparece */
typedef pair<int, int> data_t

data_t make_data(int val) {
    return {val, 1};
}

data_t combine(data_t a, data_t b) {
    if (a.first > b.first)
        return a;
    
    if (b.first > a.first)
        return b;
    
    return {a.first, a.second + b.second};
}
```

GCD - Maior divisor comum em um intervalo:
```c++
typedef int data_t

data_t make_data(int val) {
    return val;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

data_t combine(data_t a, data_t b) {
    if (a == 0)
        return b;
    
    if (b == 0)
        return a;
    
    return gcd(a, b);
}
```
Quantidade de zeros, e encontrar o k-ésimo zero:
```c++
typedef int data_t

data_t make_data(int val) {
    return val == 1;
}

data_t combine(data_t a, data_t b) {
    return a + b;
}

/* 
 * retorna o índice do k-ésimo 0 
 * retorna -1 caso não seja possível 
 */
int find_kth(int node, range_t range, int k) {
    if (k > tree[node])
        return -1;
    
    if (range.lower == range.upper)
        return range.lower;

    if (k <= tree[left(node)])
        return find_kth(left(node), {range.lower, range.mid()}, k);
    else
        return find_kth(right(node), {range.mid() + 1, range.upper}, k - tree[left(node)]);
}
```