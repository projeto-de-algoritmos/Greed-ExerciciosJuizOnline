int compara(const void *a, const void *b) {
    int custoA = ((*(int **)a)[0] - (*(int **)a)[1]);
    int custoB = ((*(int **)b)[0] - (*(int **)b)[1]);
    return custoA - custoB;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    int custoTotal = 0;

    qsort(costs, costsSize, sizeof(int *), compara);
    
    for(int i = 0; i < costsSize / 2; i++) {
        custoTotal += costs[i][0];
    }

    for(int i = costsSize / 2 ; i < costsSize; i++) {
        custoTotal += costs[i][1];
    }
    
    return custoTotal;
}