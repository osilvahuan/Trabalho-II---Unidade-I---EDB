#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Algoritmos de busca e ordenação

// Busca Sequencial: percorre o vetor um por um
int buscaSequencial(int vetor[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (vetor[i] == chave) return i;
    }
    return -1;
}

// Busca Binária: divide o espaço de busca ao meio (requer vetor ordenado)
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

// Bubble sort: troca pares adjacentes até o maior "flutuar" para o fim
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

// Selection sort: seleciona o menor e coloca na posição correta
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
    srand(time(NULL));
    int repeticoes = 30;
    int tamanhos[] = {1000, 5000, 10000, 20000,30000};
    int num_testes = 5;
    clock_t inicio, fim;

    // Melhora a implementação para gráficos
    printf("n;bubble(s);selection(s);buscaSequencial(s);buscaBinaria(s)\n");
    for (int t = 0; t < num_testes; t++) {
        int n = tamanhos[t];
        double total_bubble = 0, total_selection = 0, total_buscaSequencial = 0, total_buscaBinaria = 0;

        for (int r = 0; r < repeticoes; r++) {
    // Alocação dinamica para grandes volumes de dados
    int *vetor_original = (int *)malloc(n * sizeof(int));
    int *vetor_teste = (int *)malloc(n * sizeof(int));

    // preenche o vetor com números aleatórios
    for (int i = 0; i < n; i++) vetor_original[i] = rand();

    // Testa Bubble Sort
    memcpy(vetor_teste, vetor_original, n * sizeof(int));
    inicio = clock();
    bubbleSort(vetor_teste, n);
    fim = clock();
    total_bubble += (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Testa Selection Sort
    memcpy(vetor_teste, vetor_original, n * sizeof(int));
    inicio = clock();
    selectionSort(vetor_teste, n);
    fim = clock();
    total_selection += (double)(fim - inicio) / CLOCKS_PER_SEC;

    int chave = -1; // Valor que não existe no vetor para garantir o pior caso na busca
    int num_buscas = 10000; // Quantidade de vezes que vamos repetir a busca para obter uma média mais precisa

    // Teste Busca Sequencial
    inicio = clock();
    for(int b = 0; b < num_buscas; b++) {
        buscaSequencial(vetor_original, n, chave);
    }
    fim = clock();
    // Divide pelo número de buscas para obter o tempo médio por busca
    total_buscaSequencial += (((double)(fim - inicio)) / CLOCKS_PER_SEC) / num_buscas;

    // Teste Busca Binária (após ordenar o vetor)
    inicio = clock();
    for(int b = 0; b < num_buscas; b++) {
        buscaBinaria(vetor_teste, n, chave);
    }
    fim = clock();
    total_buscaBinaria += (((double)(fim - inicio)) / CLOCKS_PER_SEC) / num_buscas;

    free(vetor_original);
    free(vetor_teste);
        }
    // Imprime os resultados médios para cada teste
         printf("%d;%.6f;%.6f;%.10f;%.10f\n", 
               n, 
               total_bubble / repeticoes, 
               total_selection / repeticoes, 
               total_buscaSequencial / repeticoes, 
               total_buscaBinaria / repeticoes);
    }

    return 0;
}