#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%i%i%i%i", &a, &b, &c, &d);

    printf("%i", (((d * c) + b) / a));
}