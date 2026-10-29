#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

int main() {
    int * input_list = (int *)malloc(200001 * 4);

    int n;
    scanf("%i", &n);

    for (int i = 0; i < n; i++) {
        scanf("%i", &input_list[i]);
    }

    int result = 0;
    int actual = 0;

    std::sort(input_list, input_list + n);

    for (int i = 0; i < n; i++) {
        if (input_list[i] > actual) {
            actual = input_list[i];
            result++;
        }
    }
    free(input_list);
    printf("%i", result);
}