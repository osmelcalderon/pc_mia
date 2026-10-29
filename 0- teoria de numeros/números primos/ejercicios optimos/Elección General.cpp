#include <stdio.h>

int determine_winner(int n, int m) {
    int candidatos[4];

    for (int i = 0; i < n; i++) candidatos[i] = 0;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int votes;
            scanf("%i", &votes);
            candidatos[j] += votes;
        }
    }

    int major = 0;
    for (int i = 1; i < n; i++) {
        if (candidatos[major] < candidatos[i]) {
            major = i;
        }
    }
    return major + 1;
}

int main() {
    int t;
    scanf("%i", &t);

    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%i%i", &n, &m);
        int result = determine_winner(n, m);
        printf("%i\n", result);
    }
}