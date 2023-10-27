#include <stdio.h>
#include <string.h>

int main() {
    int quantidadeDigitos;
    int quantidadeDigitosApagados;

    while (1) {
        scanf("%d %d", &quantidadeDigitos, &quantidadeDigitosApagados);
        if (quantidadeDigitos == 0 && quantidadeDigitosApagados == 0) {
            break;
        }

        char numero[100005];
        scanf("%s", numero);

        char pilha[100005];
        int topo = -1;

        for (int i = 0; i < quantidadeDigitos; i++) {
            while (topo >= 0 && quantidadeDigitosApagados > 0 && numero[i] > pilha[topo]) {
                topo--;
                quantidadeDigitosApagados--;
            }
            pilha[++topo] = numero[i];
        }

        while (quantidadeDigitosApagados > 0) {
            topo--;
            quantidadeDigitosApagados--;
        }

        pilha[topo + 1] = '\0';
        printf("%s\n", pilha);
    }

    return 0;
}