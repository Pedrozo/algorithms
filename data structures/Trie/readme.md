# Trie

## Objetivo

- Trabalhar com strings em estrutura de grafo
- Agrupar strings
- Trabalhar com prefixos (ex. max prefixo em comum)

## Compexidade

- **Criação**: O(n \* |str|)
- **Inserção** O(|str|)
- **Busca** O(|m|)

## Referências

- [Hacker Earth](https://www.hackerearth.com/pt-br/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/)

## Implementação

Estrutura:

```c++
struct Trie
{
    Trie *adj[MAXCHAR];
    bool endWord;

    Trie()
    {
        (endWord) = false;
        for (int i = 0; i < MAXCHAR; i++)
        {
            (adj[i]) = NULL;
        }
    }
};
```

Inserção:

```c++
void insert(Trie *root, string str)
{
    Trie *pt = root;
    int sz = str.size();
    for (int i = 0; i < sz; i++)
    {
        int ind = str[i] - 'a';
        if (!pt->adj[ind])
            pt->adj[ind] = new Trie();

        pt = pt->adj[ind];
    }

    pt->endWord = true;
}
```

Busca prefixo em comum na trie:

```c++
bool search(Trie *root, string str)
{
    int sz = str.size();

    Trie *pt = root;
    for (int i = 0; i < sz; i++)
    {
        if (pt->endWord)
            return true;

        if (!pt->adj[str[i] - 'a'])
            return false;

        pt = pt->adj[str[i] - 'a'];
    }

    return (pt != NULL);
}
```


## Problemas

- [Hacker Rank - Contacts](https://www.hackerrank.com/challenges/contacts/problem) ([Solução](https://github.com/Pedrozo/algorithms/blob/master/data%20structures/Trie/hr_contacts.cpp))
- [Hacker Rank - No prefix set](https://www.hackerrank.com/challenges/no-prefix-set/problem) ([Solução](https://github.com/Pedrozo/algorithms/blob/master/data%20structures/Trie/hr_no_prefix_set.cpp))
- [URI - Conjuntos Bons e Ruins](https://www.urionlinejudge.com.br/judge/pt/problems/view/2087) ([Solução](https://github.com/Pedrozo/algorithms/blob/master/data%20structures/Trie/URI2087.cpp))