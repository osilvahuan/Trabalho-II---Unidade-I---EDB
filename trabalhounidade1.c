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

// Busca Binária: divide o espaço de busca ao meio (requer vetor ordenado) [3]
int buscaBinaria(int vetor[], int n, int chave) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == chave) return meio;
        else if (vetor[meio] < chave) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// Bubble sort: troca pares adjacentes até o maior "flutuar" para o fim [4, 5]
void bubbleSort(int vetor[], int n) {
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

// Selection sort: seleciona o menor e coloca na posição correta [6]
void selectionSort(int vetor[], int n){
    for (int i = 0; i < n -1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[min_idx]) min_idx = j;
        }
        if (min_idx != i) { // Prestar atenção nesse ponto.
            int temp = vetor[i];
            vetor[i] = vetor[min_idx];
            vetor[min_idx] = temp;
        }
    }
}

int main() {
    int n = 10000;
    int *vetor = (int *) malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 10000; // Números aleatórios
    }

    printf("Vetor de tamanho %d criado.\n", n);

    free(vetor); // Liberar memória alocada

    clock_t inicio, fim;
    double tempo_total = 0;
    int repeticoes = 30;

    int tamanhos[] = {1000, 5000, 10000, 20000, 50000};
    int num_testes = 5;

    printf("n;tempo_medio\n");

    for (int t = 0; t < num_testes; t++) {
        int n = tamanhos[t];
        tempo_total = 0;

        for (int r = 0; r < repeticoes; r++) {

            // Cria e preenche o vetor
            int *vetor = (int *) malloc(n * sizeof(int));
            for (int i = 0; i < n; i++) vetor[i] = rand();

            // Mede apenas o algoritimo
            inicio = clock();
            bubbleSort(vetor, n);
            fim = clock();

            // Somar o tempo gasto (em segundos)
            tempo_total += ((double)(fim - inicio)) / CLOCKS_PER_SEC;

            free(vetor); // Liberar memória alocada
        }

        // Imprime o tempo médio
        printf("%d;%.6f\n", n, tempo_total / repeticoes);
    }


    return 0;
}