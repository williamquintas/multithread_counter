# Contando letras A usando multiprocessos

Esta tarefa consiste em receber um texto na entrada e contar quantas letras `a`
ou `A` (o sistema é case-insensitive!) existem nessa entrada. Porém, trata-se de
um exercício de programação, e não somente de uma solução com algoritmo.

**O objetivo desta tarefa é fazer o sistema operar como multi-thread,
usando a biblioteca `lpthread`.**

As soluções deverão ser estruturadas de forma que:

1. cada linha seja analisada por
uma thread independente.
1. As threads deverão (ao menos potencialmente) poder
executar em paralelo.
1. O programa deverá assumir um **número máximo de threads paralelas** igual a
`4`.

Soluções que não contemplem esses três requisitos não serão aceitas. Eles serão
verificados manualmente, caso a caso.

## Exemplos

Entrada | Saida
------- | -----
`Teste\n` | `0\n`
`a\n` | `1\n`
`a\nA\n` | `2\n` (operando em duas threads)
`a\nA\nTeste\n` | `2\n` (operando em três threads)


## Instruções adicionais

1. Vá diretamente ao conjunto de testes para verificar como tratar casos
   limítrofes ou mal-definidos.
1. Lembre-se de seguir as [instruções de submissão](docs/instrucoes.md).
1. Se desejar, proponha novos casos de teste.
