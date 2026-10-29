#include<stdio.h>
int main(){
    int N,L=0,R=0;
    scanf("%d",&N);
    if(N<3){
        R=N;
    }
    else{
        char A[N];
        scanf("%50s",A);
        for(int i=0;i<N;++i){
            if(A[i]=='L'){++L;}
            if(i==0||i==N-1){++R;}
            if(A[i]=='S'){++R;L=0;}
            else if(A[i]=='L'&&(L&1)&&R<=i){++R;}
        }
    }
    printf("%d",R);
    return 0;
}