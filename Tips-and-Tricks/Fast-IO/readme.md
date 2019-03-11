# Fast IO
Muitos exercícios nas competições exigem uma quantidade muito grande entrada e saída de dados. Essas operações geralmente são muito custosas e por isso é muito interessante que sejam o mais otimizadas possível.

## C++
Para entrada de dados podemos utilizar tanto o *cin* quanto o *scanf*. Por exemplo:

```c++
int x;
cin >> x;
```

é o mesmo que:

```c++
int x;
scanf("%d", &x);
```

Apesar de ambos aparentemente surtirem o mesmo efeito, *scanf* é bem mais rápido que *cin*. Mas, existe uma forma de deixar *cin* tão rápido quanto *scanf*.

```c++
// Isso desabilita a sincronização no IO,
// o que faz com que as chamadas a *cin* e *cout* não sejam thread-safe
ios_base::sync_with_stdio(false);

// Garante que o flush do *cout* aconteça antes de *cin* aceitar um entrada
cin.tie(NULL);
```