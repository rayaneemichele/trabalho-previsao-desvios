#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//tamanho do vetor (32.768 números)
#define ARRAY_SIZE 32768
//quantas vezes vamos repetir o teste para dar tempo do processador trabalhar
#define ITERATIONS 100000

//ordena o vetor do menor para o maior
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main(int argc, char **argv)
{
    int data[ARRAY_SIZE];

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    //Preenche o vetor com números aleatórios de 0 a 255
    for (int c = 0; c < ARRAY_SIZE; ++c)
    {
        data[c] = rand() % 256;
    }

    // Verifica se foi digitado "sort" no terminal
    // Se foi, ele ordena o vetor. Se não, deixa bagunçado.
    if (argc > 1 && strcmp(argv[1], "sort") == 0)
    {
        qsort(data, ARRAY_SIZE, sizeof(int), compare);
        printf("Executando com vetor ORDENADO...\n");
    }

    else
    {
        printf("Executando com vetor ALEATÓRIO DESORDENADO...\n");
    }

    //teste de desempenho
    long long sum = 0;
    clock_t start = clock(); // Começa a cronometrar o tempo

    //roda o teste 100 mil vezes para o computador ter bastante trabalho
    for (int i = 0; i < ITERATIONS; ++i)
    {
        //passa por cada um dos 32 mil números do vetor
        for (int c = 0; c < ARRAY_SIZE; ++c)
    {

            // Este 'if' é o desvio (branch). O processador precisa prever se o número 
            // atual é maior ou igual a 128 antes mesmo de fazer a conta.
            if (data[c] >= 128)
            {
                sum += data[c]; // Se for verdadeiro, soma
            }
     }
    }

    clock_t end = clock(); // Para o cronômetro

    // Calcula quantos segundos se passaram
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Mostra os resultados na tela
    printf("Tempo de execucao: %f segundos\n", time_spent);
    printf("Soma total (apenas para evitar otimizacao): %lld\n", sum);

    return 0;
}
