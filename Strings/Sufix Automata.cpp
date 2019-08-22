/*Sufix Automata
    * Utilizada para contagem de Substrings totais de um texto
    Codigo testado em: https://www.urionlinejudge.com.br/judge/en/problems/view/1530
*/
#include <bits/stdc++.h>

using namespace std;
struct state{// Struct que representa um estado do automato
    int len, link;
    map<int, int> next;
};

struct state st[1500000];
int last = 0;
int sz = 1;
long long int resp;

void reinit(){// Metodo de inicializacao do automato
    resp = 0;
    last = 0;
    sz = 1;
    st[0].len = 0;
    st[0].link = -1;
    st[0].next.clear();
}

void extend(int c){// Metodo de criacao do automato
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].next.clear();

    int p;
    for(p = last; p != -1 && !st[p].next.count(c); p = st[p].link){
        st[p].next[c] = cur;
    }

    if(p == -1){
        st[cur].link = 0;
    }
    else{
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len){
            st[cur].link = q;
        }else{
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for(;p != -1 &&  st[p].next[c] == q; p = st[p].link){
                st[p].next[c] = clone;
            }

            st[q].link = st[cur].link = clone;
        }
    }

    last = cur;
    resp += st[last].len - st[st[last].link].len; //Modificacao para contagem de novas substrings
}

int main(){
    char c;
    reinit();
    while((c = getchar_unlocked()) != EOF){
        if(c == '\n'){
            reinit();
            continue;
        }

        if(isalpha(c)){
            extend(c - 'a');
        }else{
            printf("%lld\n", resp);
        }
    }
}
