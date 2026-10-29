#include <stdio.h>
#include <algorithm>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    std::sort(a,a+n);
    int x=a[0],d=1,mx=0;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1])d++;
        else if(d>mx){
            x=a[i-1];
            mx=d;
            d=1;
        }
    }
    if(d>mx)x=a[n-1];
    printf("%d",x);
}