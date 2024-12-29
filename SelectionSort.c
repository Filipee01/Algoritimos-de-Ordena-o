#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int vetor[], int n) {
    int i, j, min_idx, aux;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        aux = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = aux;
    }
}

void printVetor(int v[], int n) {
    printf("\nIniciando Vetor!\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("Vetor: [%d] = %d\n", i + 1, v[i]);
    }
    printf("\nVetor finalizado!\n");
}

int main() {
    FILE *file;
    int tam = 1000; // Tamanho do vetor
    int *vetor = (int *)malloc(tam * sizeof(int));
    int n = 0;
    clock_t start, end;
    double cpu_time_used;

    if (vetor == NULL) {
        printf("\nErro ao alocar memória!\n");
        return 1;
    }

    file = fopen("C:\\Program Files\\ed\\instancias-numericas\\instancias-num\\num.1000.1.in", "r");
    if (file == NULL) {
        printf("\nErro ao ler o arquivo!\n");
        free(vetor);
        return 1;
    }

    while (fscanf(file, "%d", &vetor[n]) != EOF && n < tam) {
        n++;
    }

    fclose(file);

    printVetor(vetor, n);

    // Medir tempo de execução do SelectionSort
    start = clock();
    selectionSort(vetor, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printVetor(vetor, n);

    // Mostrar tempo de execução no final
    printf("Tempo de execucao do SelectionSort: %f segundos\n", cpu_time_used);

    // Pausar o sistema para permitir visualização do resultado
    system("pause");

    free(vetor);
    return 0;
}