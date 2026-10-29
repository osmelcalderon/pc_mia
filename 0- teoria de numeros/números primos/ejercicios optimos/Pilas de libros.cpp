#include<stdio.h>
int main(){
    int N,res=0;
    bool VL=1,VR=1,VU=1,VD=1;
    scanf("%d",&N);
    int P[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            scanf("%d",&P[i][j]);
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(P[i][j]){
                if(i==0||i==N-1||j==0||j==N-1){
                    ++res;
                }
                else{
                    for(int PosY=i-1;PosY>=0;--PosY){
                        if(P[PosY][j]>=P[i][j]){VU=0; break;}
                    }
                    for(int PosY=i+1;PosY<N;++PosY){
                        if(P[PosY][j]>=P[i][j]){VD=0; break;}
                    }
                    for(int PosX=j-1;PosX>=0;--PosX){
                        if(P[i][PosX]>=P[i][j]){VL=0; break;}
                    }
                    for(int PosX=j+1;PosX<N;++PosX){
                        if(P[i][PosX]>=P[i][j]){VR=0; break;}
                    }
                    if(VL||VR||VU||VD){++res;}
                    VL=VR=VU=VD=1;
                }
            }
        }
    }
    printf("%d",res);
    return 0;
}