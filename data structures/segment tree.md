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
**Importante:** A função *combine*, o tipo *data_t* e a constante *NEUTRAL* variam para diferentes comportamentos da árvore de segmentos

Macros:
```c++
#define MAX_N 100100
#define left(x) ((x) * 2)
#define right(x) ((x) * 2 + 1)
```
Estrutura: (permite que o código fique mais limpo, a um pequeno custo de desempenho)
```c++
struct Segment {
    int lower;
    int upper;

    int mid() {
        return (lower + upper) / 2;
    }

    // se os extremos de s estão "dentro" deste segmento
    bool contains(Segment s) {
        return lower <= s.lower && upper >= s.upper;
    }

    // se os segmentos possuem algum ponto em comum
    bool intersect(Segment s) {
        return lower <= s.upper && upper >= s.lower;
    }
};
```

Variáveis Globais:
```c++
int n; // quantidade de elementos em arr
data_t arr[MAX_N];
data_t tree[MAX_N * 4];
```

Inicializar a árvore de segmentos:
```c++
void build(int node, Segment bounds) {
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
data_t query(int node, Segment bounds, Segment query_bounds) {
    if (query_bounds.contains(bounds))
        return tree[node];

    if (!query_bounds.intersect(bounds))
        return NEUTRAL; // no fim da página existem possíveis valores para esta constante

    int q1 = query(left(node), {bounds.lower, bounds.mid()}, query_bounds);
    int q2 = query(right(node), {bounds.mid() + 1, bounds.upper}, query_bounds);

    return combine(q1, q2);
}
```

Point Update:
```c++
void update(int node, Segment bounds, int idx, int val) {
    if (bounds.lower == bounds.upper) {
        tree[node] = val;
        arr[bounds.lower] = val;
        return;
    }

    if (idx <= bounds.mid())
        update(left(node), {bounds.lower, bounds.mid()}, idx, val);
    else
        update(right(node), {bounds.mid() + 1, bounds.upper}, idx, val);

    tree[node] = combine(tree[left(node)], tree[right(node)]);
}
```

Como as funções *build*, *query* e *update* possuem valores padrões para os argumentos *node* e *bounds*, é possível sobrecarregar essas funções a fim de facilitar sua utilização.
```c++
void build() {
    build(1, {1, n});
}

int query(int l, int u) {
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
#define NEUTRAL 1e9 // assumindo que nenhum elemento será maior que isso
typedef int data_t;

data_t combine(data_t a, data_t b) {
    return min(a, b);
}
```

Range Sum Query - Soma de elementos em um intervalo:
```c++
#define NEUTRAL 0
typedef int data_t;

data_t combine(data_t a, data_t b) {
    return a + b;
}
```

O maior elemento, e a quantidade vezes que aparece:
```c++
/* o primeiro elemento do pair é o valor do elemento; o segundo, quantas vezes aparece */
#define NEUTRAL {(int) -1e9, 0}
typedef pair<int, int> data_t

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
#define NEUTRAL 0
typedef int data_t

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
#define NEUTRAL 0
typedef int data_t

data_t combine(data_t a, data_t b) {
    return a + b;
}

/* 
 * retorna o índice do k-ésimo 0 
 * retorna -1 caso não seja possível 
 */
int find_kth(int node, Segment bounds, int k) {
    if (k > tree[node])
        return -1;
    
    if (bounds.lower == bounds.upper)
        return bounds.lower;

    if (k <= tree[left(node)])
        return find_kth(left(node), {bounds.lower, bounds.mid()}, k);
    else
        return find_kth(right(node), {bounds.mid() + 1, bounds.upper}, k - tree[left(node)]);
}
```