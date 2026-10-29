#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    if((n>999) || (n<100)){
        printf("-1");
    }
    else{
        int i = n/100;
        i*=111;
        if(i>=n){
            printf("%d\n", i);
        }
        else{
            i+=111;
            printf("%d\n", i);
        }
    }
    return 0;
}