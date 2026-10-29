#include <stdio.h>
#include <stdint.h>

int main() {
    int16_t n;
    scanf("%hi", &n);

    for (int i = 0; i < n; i++) {
        char name[110];
        scanf("%s%s", name, name);

        printf("Hola, ");
        int j = 0;
        while (name[j] != '\0') {
            printf("%c", name[j]);
            j++;
        }
        printf(".\n");
    }
}