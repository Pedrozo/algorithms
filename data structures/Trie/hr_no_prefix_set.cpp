// LINK PROBLEMA https://www.hackerrank.com/challenges/no-prefix-set/problem

#include <bits/stdc++.h>

using namespace std;

class Trie
{
public:
    bool end_word;

public:
    Trie *adj[10];

    Trie()
    {
        (end_word) = false;
        for (int i = 0; i < 10; i++)
            (adj[i]) = NULL;
    }
};

bool insert(Trie *root, string str)
{
    Trie *p = root;
    int i = 0;
    for (char a : str)
    {
        int b = a - 'a';

        if (i == (str.size() - 1) && p->adj[b] != NULL)
            return false;

        //cout << b <<endl;
        if (!p->adj[b])
            p->adj[b] = new Trie();

        p = p->adj[b];

        if (p->end_word)
            return false;

        i++;
    }

    p->end_word = true;

    return true;
}

int main()
{
    int n;
    cin >> n;
    Trie *root = new Trie();

    while (n--)
    {
        string str;
        cin >> str;
        if (!insert(root, str))
        {
            cout << "BAD SET\n"
                 << str << endl;
            return 0;
        }
    }

    printf("GOOD SET\n");
    return 0;
}
