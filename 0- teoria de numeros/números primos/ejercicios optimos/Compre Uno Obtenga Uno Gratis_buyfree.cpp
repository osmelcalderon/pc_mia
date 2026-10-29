#include<stdio.h>
#include<algorithm>
int main(){
    int n,m,c=0,mi=0;
    scanf("%d%d",&n,&m);
    int A[n],B[m];
    for(int i=0;i<n;++i){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&B[i]);
    }
    std::sort(A,A+n);
    std::sort(B,B+m);
    for(int i=0;i<n;++i){
        if(A[i]>B[mi]&&mi<m){
            ++mi;
            c+=2;
        }
        else{++c;}
    }
    printf("%d",c);
    return 0;
}
