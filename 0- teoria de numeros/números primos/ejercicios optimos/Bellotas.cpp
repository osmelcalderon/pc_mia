#include <stdio.h>
#include <string.h>

int main() {
    int N;
    int contador=0;
    int total=0;
    scanf("%d", &N);
    while (contador < N) {
        int A;
        scanf ("%d", &A);
        contador ++;

        if (A>10) {
            int resultado = A-10;
            total+=resultado;
        }
    }
 printf("%d", total);
   // printf("%d\n", a+b);

    return 0;
}