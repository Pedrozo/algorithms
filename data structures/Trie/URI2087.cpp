#include <bits/stdc++.h>

#define MAXCHAR 26

using namespace std;

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

int main()
{
    string str;
    int n;

    while (scanf(" %d", &n) && n)
    {
        Trie *root = new Trie();

        bool res = true;
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            if (res && search(root, str))
                res = false;

            if (res)
                insert(root, str);
        }

        if (res)
            printf("Conjunto Bom\n");
        else
            printf("Conjunto Ruim\n");
    }

    return 0;
}