#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// ALGORITMOS

// Busca Sequencial: percorre o vetor um por um [1, 2]
int buscaSequencial(int vetor[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (vetor[i] == chave) return i;
    }
    return -1;
}

// Busca Binária: vetor deve estar ordenado [1, 2]
int buscaBinaria(int vetor[], int n, int chave) {
    int esquerda = 0, direita = n - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (vetor[meio] == chave) return meio;
        else if (vetor[meio] < chave) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return -1;
}
// Bubble Sort: ordena o vetor [1, 2]
bubbleSort(int vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}