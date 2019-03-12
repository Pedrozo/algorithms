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

Apesar de ambos aparentemente surtirem o mesmo efeito, `scanf` é bem mais rápido que `cin`. Mas, existe uma forma de deixar `cin` tão rápido quanto `scanf`.

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

Se for necessário ainda mais performance, é possível utilizar o `getchar()`, que pega o próximo caracter do buffer de entrada. Existem também o `getchar_unlocked()`, que é ainda mais rápido por que não é Thread-Safe.

```c++
char a,b;

// Rápido
a = getchar();

// Ainda mais rápido
b = getchar_unlocked();
```