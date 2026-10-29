#include<stdio.h>
#include<cstring>
int main(){
    char N[2000001];
    scanf("%2000000s",N);
    int X=strlen(N);
    printf("%c",N[X-1]);
    return 0;
}