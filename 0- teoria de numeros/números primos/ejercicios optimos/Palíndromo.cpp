#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    if (t < 1 || t > 100) {
        return 1;
    }

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        if (n < 1 || n > 1000) {
            return 1;
        }

        char s[n+1];
        scanf("%s", s);

        int count[26] = {0};

        for (int j = 0; j < n; j++) {
            count[s[j] - 'A']++;
        }

        char left[(n/2)+1];
        int leftLen = 0;

        for (int j = 0; j < 26; j++) {
            while (count[j] > 1) {
                left[leftLen++] = 'A' + j;
                count[j] -= 2;
            }
        }

        char center = '\0';
        for (int j = 0; j < 26; j++) {
            if (count[j] == 1) {
                center = 'A' + j;
                break;
            }
        }

        left[leftLen] = '\0';

        char right[leftLen+1];
        int rightLen = 0;

        for (int j = leftLen-1; j >= 0; j--) {
            right[rightLen++] = left[j];
        }

        right[rightLen] = '\0';

        printf("%s%c%s\n", left, center, right);
    }

    return 0;
}