#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort.
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função principal.
int numRescueBoats(int *people, int n, int limit) {
    int numBoats = 0; // Número mínimo de barcos necessários.
    qsort(people, n, sizeof(int), compare); // Ordena o people em ordem crescente com base no peso.

    int left = 0; // Índice da pessoa mais leve.
    int right = n - 1; // Índice da pessoa mais pesada.

    // Loop para acomodar as pessoas nos barcos.
    while (left <= right) {
        // Verifica se as duas extremidades podem ser acomodadas em um barco.
        if (people[left] + people[right] <= limit) {
            left++; // Move a pessoa mais leve para a direita.
            right--; // Move a pessoa mais pesada para a esquerda.
        } else {
            right--; // Move apenas a pessoa mais pesada para a esquerda.
        }
        numBoats++; // Incrementa o número de barcos usados.
    }

    return numBoats; // Retorna o número mínimo de barcos necessários.
}
