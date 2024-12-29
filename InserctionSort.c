#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int vetor[], int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        aux = vetor[i];
        for (j = i - 1; j >= 0 && vetor[j] > aux; j--) {
            vetor[j + 1] = vetor[j];
        }
        vetor[j + 1] = aux;
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
    int tam = 1000;
    int vetor[tam], n = 0;
    clock_t start, end;
    double cpu_time_used;
    int num_iterations = 1000; // Número de iterações 

    file = fopen("C:\\Program Files\\ed\\instancias-numericas\\instancias-num\\num.1000.1.in", "r");
    if (file == NULL) {
        printf("\nErro ao ler o arquivo!\n");
        return 1;
    }

    while (fscanf(file, "%d", &vetor[n]) != EOF && n < tam) {
        n++;
    }

    fclose(file);

    printVetor(vetor, n);

    // Medir tempo de execução do InsertionSort
    start = clock();
    for (int i = 0; i < num_iterations; i++) {
        insertionSort(vetor, n);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC / num_iterations;

    printVetor(vetor, n);

    // Mostrar tempo de execução no final
    printf("Tempo de execucao do InsertionSort: %f segundos\n", cpu_time_used);

    // Pausar o sistema para permitir visualização do resultado
    system("pause");

    return 0;
}