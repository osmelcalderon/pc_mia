#include <stdio.h>
int main(){
    int k;
    scanf("%d",&k);
    printf("%lld\n%lld\n%lld",(long long)k*k*k,(long long)k*k-(k-1),(long long)k*k+(k-1));
}