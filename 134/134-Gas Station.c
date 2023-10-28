#include <stdio.h>

int canCompleteCircuit(int gas[], int gasSize, int cost[], int costSize) {
    int g = 0; // Soma total de gasolina
    int c = 0; // Soma total de custo

    // Calcula o total de gasolina e custo
    for (int i = 0; i < gasSize; i++) {
        g += gas[i];
        c += cost[i];
    }

    // Se o custo for maior que a gasolina disponível, não é possível
    if (c > g) {
        return -1;
    }

    int start = 0; // Início da rota
    int total = 0; // Total de gasolina disponível

    for (int i = 0; i < gasSize; i++) {
        total += (gas[i] - cost[i]);

        if (total < 0) {
            // Se o total for negativo, avançar a partir desse índice não é possível
            start = i + 1; // Marque um novo ponto de partida como o próximo índice 'i+1'
            total = 0; // Redefine o total para a nova situação
        }
    }

    return start; // Retorna o índice de partida para completar o circuito
}