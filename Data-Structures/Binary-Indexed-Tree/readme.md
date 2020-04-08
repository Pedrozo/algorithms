# Binary Indexed Tree

## Objetivo

* Realizar em tempo eficiente (logarítmico) as seguintes operações:
  * **Point Update**: atualizar o valor de um único elemento.
  * **Range Query**: buscar o valor de um prefixo qualquer de elementos. (soma dos elementos do prefixo, por exemplo)
* Apesar de mais limitado que a Árvore de Segmentos, utiliza menos espaço e possui uma implementação mais simples.

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
int n; // tamanho do vetor e consequentemente da árvore
int tree[]; // BIT (os índices vão de 1 até n)
```

Point Update:
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