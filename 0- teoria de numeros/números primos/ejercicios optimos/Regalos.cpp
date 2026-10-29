#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *cost1 = *(int **)a;
    int *cost2 = *(int **)b;

    return cost1[0] + cost1[1] - cost2[0] - cost2[1];
}

int amountGifts(int budget, int **costs, int n) {
    int gifts = 0;
    int sum = 0;

    qsort(costs, n, sizeof(int *), compare);

    for (int i = 0; i < n; i++) {
        if (sum + costs[i][0] + costs[i][1] <= budget) {
            sum += costs[i][0] + costs[i][1];
            gifts++;
        }
        else if (sum + costs[i][0] / 2 + costs[i][1] <= budget) {
            sum += costs[i][0] / 2 + costs[i][1];
            gifts++;
        }
        else {
            break;
        }
    }

    return gifts;
}

int main() {
    int n, b;
    scanf("%d%d", &n, &b);

    int **costs = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        costs[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d%d", &costs[i][0], &costs[i][1]);
    }

    printf("%d\n", amountGifts(b, costs, n));

    for (int i = 0; i < n; i++) {
        free(costs[i]);
    }
    free(costs);

    return 0;
}