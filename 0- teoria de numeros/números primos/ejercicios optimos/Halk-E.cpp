#include <stdio.h>

int main() {
    long long n, c=0;
    scanf("%lld", &n);
    if(!(n%3))
    {
        printf("0");
        return 0;
    }
    while(n>1)
    {
        if(n&1) n-=3;
        else if(n==4)
        {
            printf("%lld", c+2);
            return 0;
        }
        else n>>=1;
        c++;
    }
    printf("%lld", c+1);
    return 0;
}