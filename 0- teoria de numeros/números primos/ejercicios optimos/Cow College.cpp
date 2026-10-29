#include<stdio.h>
#include<algorithm>

int main(){
    int i=0,n,d=0;
    long long mx=0;
    scanf("%d",&n);
    int arr[n];
    for(;i<n;i++) scanf("%d",&arr[i]);
    std::sort(arr,arr+n);
    for(i=0;i<n;i++) if((long long)arr[i]*(n-i)>mx) mx=arr[i]*(n-i),d=arr[i];
    printf("%lld %d",mx,d);
    return 0;
}