# IO Utilits
Essa é uma comparação da utilidade de alguns metodos de entrada de multiplos caracteres.

Quando fazemos a leitura de uma linha inteira, ou sequência de caractéres que possívelmente contém espaços, temos 3 opções, sendo elas o `scanf` com truques para ignorar os espaços

```c++
    scanf("%[^/n]", char *ptr);
```

o simples `gets` (mas bastante perigoso)

```c++
    char *ptr = gets();
```

ou o mais indicado o `fgets`

```c++
    fgets(char *ptr, int n, FILE *iostream);
```

O `fgets` se tornou o mais indicado pois ele dificilmente fará uma escrita ilegal, pois é possivel definir a quantidade maxima de caracteres lidos, já nos outros dois modos essa definição não é possivel, assim temos que escolher o tamanho do espaço alocado cuidadosamente.

Cuidados que devemos tomar, scanf não lê o `'/n'` e o deixa no buffer de entrada, sendo assim, devemos retira-lo com um `getchar` ou adicionando um espaço antes do `" %[^\n]"`, já o fgets e gets o limpam da entrada e é descartado. No entanto, todos os metodos colocam um `'/0'` no final da palavra na memória.