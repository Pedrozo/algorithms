# Disjoint Set / Union Find

## Objetivo

* Realizar, em tempo eficiente, as seguintes operações:
  * **Union(x, y)**: Une os conjuntos que contém os elementos x e y.
  * **Find(x)**: Retorna a representação do conjunto que x pertence. Ou seja, se Find(x) == Find(y) então x e y pertencem ao mesmo conjunto.
* Pode ser utilizdado para determinar as componentes conexas de um grafo.

## Compexidade
* **Point Update**: O(log n)
* **Range Query**: O(log n)

## Referências

* [Hacker Earth](https://www.hackerearth.com/pt-br/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/)
* [Geeks for Geeks](https://www.geeksforgeeks.org/binary-search/)
* [Wikipedia](https://en.wikipedia.org/wiki/Fenwick_tree)
* [Top Coder](https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/)
* [Quora - Range Updates](https://www.quora.com/q/uvelcqdfekuuogmt/Tutorial-Range-Updates-in-Fenwick-Tree)

## Implementação

Váriaveis globais:
```c++
int n; // tamanho do vetor e, consequentemente, da árvore
int tree[MAX_N]; // BIT, índices vão de 1 até n
```

Point Update:s
```c++
void update(int idx, int val) {
    while (idx <= n) {
        tree[idx] += val;
        idx += idx & -idx;
    }
}
```

Range Query:
```c++
int query(int idx) {
    int sum = 0;

    while (idx >= 1) {
        sum += tree[idx];
        idx -= idx & -idx;
    }

    return sum;
}
```

## Problemas
**TODO**