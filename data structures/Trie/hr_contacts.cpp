// LINK PROBLEMA https://www.hackerrank.com/challenges/contacts/problem

#include <bits/stdc++.h>

using namespace std;

class Trie
{
public:
    Trie *adj[26];

public:
    int passes;

    Trie()
    {
        (passes) = 0;
        for (int i = 0; i < 26; i++)
            (adj[i]) = NULL;
    }
};

void insert(Trie *root, string str)
{
    Trie *p = root;
    int sz = str.size();

    for (int i = 0; i < sz; i++)
    {
        int ind = str[i] - 'a';
        if (!p->adj[ind])
        {
            p->adj[ind] = new Trie();
        }

        p->passes++;
        p = p->adj[ind];
    }

    p->passes++;
}

int count(Trie *root, string str)
{
    Trie *p = root;
    int res = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (!p->adj[str[i] - 'a'])
            return 0;

        p = p->adj[str[i] - 'a'];
    }

    return p->passes;
}

/*
 * Complete the contacts function below.
 */
vector<int> contacts(vector<vector<string>> queries)
{
    /*
     * Write your code here.
     */

    Trie *root = new Trie();
    vector<int> res;
    for (vector<string> a : queries)
    {
        if (a[0] == "add")
            insert(root, a[1]);
        if (a[0] == "find")
            res.push_back(count(root, a[1]));
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++)
    {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++)
        {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++)
    {
        fout << result[result_itr];

        if (result_itr != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
