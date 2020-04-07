# Binary Search

## Objetivo

* Buscar elementos em um vetor **ordenado**. (uso clássico)
* Quando o tempo para verificar se uma solução com um determinado custo é viável, a busca binária pode ser utilizada para encontrar a solução com o menor, ou maior, custo.

## Complexidade

O(log n)

## Referências

* [Hacker Earth](https://www.hackerearth.com/pt-br/practice/algorithms/searching/binary-search/tutorial/)
* [Geeks for Geeks](https://www.geeksforgeeks.org/binary-search/)

## Implementação

### Recursiva
```c++
/*
 * procura pelo elemento x em a, limitado as posições low e high
 * retorna a posição do elemento ou -1 se não encontrado
 */
int bsearch(int a[], int x, int low, int high) {
    if (low > end)
        return -1;

    int mid = (low + high) / 2;

    if (x < a[mid])
        return bsearch(a, x, low, mid - 1);
    else if (x > a[mid])
        return bsearch(a, x, mid + 1, high);
    else
        return mid;
}
```

### Iterativa
```c++
/*
 * procura pelo elemento x em a, limitado as posições low e high
 * retorna a posição do elemento ou -1 se não encontrado
 */
int bsearch(int a[], int x, int low, int high) {
    do {
        int mid = (low + high) / 2;
        
        if (x < a[mid])
            high = high - 1;
        else if (x > a[mid])
            low = high + 1;
        else
            return mid;

    } while (low != high);

    return -1;
}
```

### Problemas
* [Maratona Brasileira de Comedores de Pipoca - Maratona de Programação 2019, SBC](Problems/maratona-comedores-de-pipoca.cpp)