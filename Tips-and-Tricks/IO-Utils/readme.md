# IO Utils
Essa é uma comparação da utilidade de alguns metodos de entrada de multiplos caracteres.

Quando fazemos a leitura de uma linha inteira, ou sequência de caractéres que possívelmente contém espaços, temos 4 opções, sendo elas o `scanf` com truques para ignorar os espaços

```c++
    scanf("%[^/n]", char *ptr);
```

o simples `gets` (mas bastante perigoso)

```c++
    char *ptr = gets();
```

ou os mais indicado o `fgets`

```c++
    fgets(char *ptr, int n, FILE *iostream);
```
e o `getline` que tem 3 formas diferentes de implementação, as duas primeiras apresentadas são exclusivas do c++ e a ultima também pode ser utilizada em c, mas ela tem o mesmo efeito do `fgets`

```c++
    getline(FILE *iostream, string str, char delimiter);
    getline(FILE *iostream, string str);

    getline(char *ptr, int n, FILE *iostream);
```
Na primeira apresentação do `getline` o buffer é lido até que `'/n'`, `EOF` ou  o delimiter seja encontrado, em qualquer um dos casos o caractere é removido do buffer e não é adicionado à palavra.

O `fgets` se tornou o mais indicado pois ele dificilmente fará uma escrita ilegal, pois é possível definir a quantidade máxima de caractéres lidos, já nos outros dois modos essa definição não é possivel, assim temos que escolher o tamanho do espaço alocado cuidadosamente.

Cuidados que devemos tomar, no `getline` a entrada dele é um objeto do tipo `string` e o`scanf` não lê o `'/n'` e o deixa no buffer de entrada, sendo assim, devemos retira-lo com um `getchar` ou adicionando um espaço antes do `" %[^\n]"`, já o `fgets` e `gets` o limpam da entrada e é descartado. No entanto, todos os metodos colocam um `'/0'` no final da palavra na memória e o conteúdo antigo da variável é descartado.