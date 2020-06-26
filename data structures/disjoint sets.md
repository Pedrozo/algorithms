# Disjoint Set / Union Find

## Objetivos

* Realizar, em tempo eficiente, as seguintes operações:
  * **Union(x, y)**: Une os conjuntos que contém os elementos x e y.
  * **Find(x)**: Retorna a representação do conjunto que x pertence. Ou seja, se Find(x) == Find(y) então x e y pertencem ao mesmo conjunto.
* Pode ser utilizado para determinar as componentes conexas de um grafo.

## Compexidade
* *O(1)* amortizado em ambas as operações (union e find).

## Referências

* [Hacker Earth](https://www.hackerearth.com/pt-br/practice/notes/disjoint-set-union-union-find/)
* [Geeks for Geeks](https://www.geeksforgeeks.org/disjoint-set-data-structures/)
* [CP Algorithms](https://cp-algorithms.com/data_structures/disjoint_set_union.html)

## Implementação

```c++
int set[MAX_SIZE];
int size[MAX_SIZE];

/*
a princípio, todo elemento é seu conjunto
*/
void make_set(int e) {
    set[e] = e;
    size[e] = 1;
}

/*
retorna o conjunto que e pertence
com path compression
*/
int find(int e) {
    if (e == set[e])
        return e;
    
    return set[e] = find(set[e]);
}

/*
une os elementos a e b em um mesmo conjunto
com union by size
*/
void join(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (size[a] < size[b])
        swap(a, b);

    set[b] = a;
    size[a] += size[b];
}
```

## Problemas
**TODO**