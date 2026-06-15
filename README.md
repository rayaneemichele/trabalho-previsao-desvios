# Trabalho: Desmistificando Previsão de Desvios
Este repositório contém o microbenchmark em C e os testes de desempenho realizados utilizando a ferramenta `perf` no Linux para a matéria de Arquitetura de Computadores (UFPR).

## Como rodar os testes:
1. Compilar: `gcc -O2 main.c -o teste_desvio`
2. Rodar desordenado: `perf stat -e branch-misses,branches ./teste_desvio`
3. Rodar ordenado: `perf stat -e branch-misses,branches ./teste_desvio sort`
