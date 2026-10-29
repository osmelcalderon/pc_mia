#include<stdio.h>

int main(){
long long N;
scanf("%lld",&N);
long long Arr[N+1];
long long DArr[N+1]={0};
for(long long i=0;i<N;i++){
    scanf("%lld",&Arr[i]);
}
long long sol=0;

for(long long k=0;k<N;k++){
    sol+=k-DArr[Arr[k]];
    DArr[Arr[k]]++;
    printf("%lld ",sol);
}

return 0;
}