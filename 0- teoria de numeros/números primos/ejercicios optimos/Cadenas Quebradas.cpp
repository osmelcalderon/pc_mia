#include<stdio.h>
#include<cstring>
int main(){
    int T,N,B=0,R=0,O=0,K=0,E=0,M=0;
    scanf("%d",&T);
    char P[101];
    while(T--){
        scanf("%100s",P);
        N=strlen(P);
        for(int i=0;i<N;++i){
            if(P[i]=='B'){
                ++B;
            }
            else if(P[i]=='R'){
                ++R;
            }
            else if(P[i]=='O'){
                ++O;
            }
            else if(P[i]=='K'){
                ++K;
            }
            else if(P[i]=='E'){
                ++E;
            }
            else if(P[i]=='N'){
                ++M;
            }
        }
        N=(((((B&R)&O)&K)&E)&M) ;
        if(N==B&&N==R&&N==O&&N==K&&N==E&&N==M){
            printf("No Secure\n");
        }
        else{printf("Secure\n");}
        B=0;R=0;O=0;K=0;E=0;M=0;
    }
    return 0;
}