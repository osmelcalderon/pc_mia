#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%i%i%i", &n, &a, &b);

    char input[100001];
    scanf("%s", input);
    printf("%c", (input[a - 1] == input[b - 1]) ? '0' : '1');
}