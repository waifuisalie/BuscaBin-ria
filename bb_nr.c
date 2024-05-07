#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Função para gerar um vetor de valores inteiros
void gerarVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        vetor[i] = i; // limitando os números entre 0 e 999
    }
    printf("[ + ] Done generating vector with %d\n", tamanho);
}

// Função de busca binária não recursiva
int buscaBinaria(int arr[], int tamanho, int chave) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        // Se a chave estiver no meio, retornar o índice
        if (arr[meio] == chave)
            return meio;
        // Se a chave for menor, descartar a metade superior
        else if (arr[meio] > chave)
            fim = meio - 1;
        // Se a chave for maior, descartar a metade inferior
        else
            inicio = meio + 1;
    }

    // Se a chave não estiver presente, retornar -1
    return -1;
}

int main() {
    // Defina os tamanhos do vetor
    int tamanhos[] = {10000, 20000, 40000, 80000, 160000, 320000, 640000, 1280000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Variáveis para medir o tempo de execução
    clock_t inicio, fim;
    double tempo;

    // Loop para testar cada tamanho do vetor
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        int vetor[tamanho];

        // Gerar vetor 
        gerarVetor(vetor, tamanho);

        // Realizar a busca binária em um elemento
        int chave = vetor[rand() % tamanho]; // Escolhe um elemento do vetor
        inicio = clock();
        int indice = buscaBinaria(vetor, tamanho, chave);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        // Imprimir resultados
        printf("Tamanho do vetor: %d\n", tamanho);
        printf("Chave: %d\n", chave);
        if (indice != -1)
            printf("Elemento encontrado no índice: %d\n", indice);
        else
            printf("Elemento não encontrado.\n");
        printf("Tempo de execução : %lf segundos\n\n", tempo);

    }

    return 0;
}
