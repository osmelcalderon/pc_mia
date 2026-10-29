#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool esPalindromo(char str[], int l, int r){
    bool res = 1;
    while (l<r && res){
        if (str[l++]!=str[r--]) res = 0;
    };
    return res;
}

bool esBiPalindromo(char str[], int TL){
    int mid;
    bool res = 0;
    for (mid = 1; mid<TL && !res;mid++){
        if (esPalindromo(str, 0, mid-1) && esPalindromo(str, mid, TL-1)) res = 1;
    };
    return res;
}

int main(void){
    int T;
    scanf("%d", &T);
    while (T--){
        char str[1000];
        scanf("%s", str);
        bool pal = esPalindromo(str, 0, strlen(str)-1);
        bool biPal = esBiPalindromo(str, strlen(str));
        if (pal){
            printf("palindrome\n");
        }
        else if (biPal) printf("bi-palindrome\n");
        else printf("non-palindrome\n");
    };

    return 0;
}