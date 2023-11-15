#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int temp;
    int swapped;

    do {
        swapped = 0;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    FILE *file;
    file = fopen("base-de-dados/100k/Decrescente/dtdecre100kuni9.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int arr[100000];
    int n = 0;

    while (fscanf(file, "%d", &arr[n]) != EOF) {
        n++;
    }

    fclose(file);

    clock_t start_time, end_time;
    double total_time;

    start_time = clock();

    bubbleSort(arr, n);

    end_time = clock();

    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Bubble, Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    printf("Tempo de execução: %f segundos\n", total_time);

    return 0;
}