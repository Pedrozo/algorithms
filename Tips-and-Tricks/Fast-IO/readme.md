# Fast IO
Muitos exercícios nas competições exigem uma quantidade muito grande entrada e saída de dados. Essas operações geralmente são muito custosas e por isso é muito interessante que sejam o mais otimizadas possível.

## C++
Para entrada de dados podemos utilizar tanto o `cin` quanto o `scanf`. Por exemplo:

```c++
int x;
cin >> x;
```

é o mesmo que:

```c++
int x;
scanf("%d", &x);
```

Apesar de ambos aparentemente surtirem o mesmo efeito, `scanf` é bem mais rápido que `cin`. Para deixar `cin` mais rápido (mas ainda não tão rápido quanto o `scanf`) podemos utilizar as funções:

```c++
// Isso desabilita a sincronização no IO,
// o que faz com que as chamadas a cin e cout não sejam thread-safe
ios_base::sync_with_stdio(false);

// Garante que o flush do cout aconteça antes de cin aceitar uma entrada
cin.tie(NULL);
```

Outra dica interessante é a de usar o `'\n'` ao invés de `endl`. Ou seja:

```c++
int n = 10;

// Pior
cout << n << endl;

// Melhor
cout << n << '\n';
```

Se for necessário ainda mais performance, é possível utilizar o `getchar()`, que pega o próximo caracter do buffer de entrada. Existem também o `getchar_unlocked()`, que é ainda mais rápido já que não é Thread-Safe, porém funciona apenas em computadores Linux.

```c++
char a,b;

// Rápido
a = getchar();

// Ainda mais rápido
b = getchar_unlocked();
```

Abaixo temos uma função bem rápida para leitura de inteiros.

```c++
void fastscan(int &n)  { 
    register int c; 
    bool negative = false; 

    n = 0;

    c = getchar(); 
    
    if (c == '-') {
        negative = true; 
        c = getchar(); 
    }
  
    for (; (c >= '0' && c <= '9'); c = getchar())
        n = n * 10 + c - '0'; 
  
    if (negative) 
        n = -n; 
}
```