#include<stdio.h>
#include<array>
std::array<int,256>D{};
int main(){
    int N,M,res=0,posx,posy;
    D['E']=-1;
    D['W']=-2;
    D['N']=-3;
    D['S']=-4;
    scanf("%d%d",&N,&M);
    char CD[M+1];
    int C[N][M];
    for(int i=0;i<N;++i){
        scanf("%1000s",CD);
        for(int j=0;j<M;++j){
            C[i][j]=D[CD[j]];
        }
    }
    for(int i=0,c=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(C[i][j]<0){
                posy=i;
                posx=j;
                while(1){
                    if(C[posy][posx]==-1){
                        C[posy][posx]=c;
                        if(posx==M-1){
                            posx=0;
                        }
                        else{++posx;}
                    }
                    else if(C[posy][posx]==-2){
                        C[posy][posx]=c;
                        if(posx==0){
                            posx=M-1;
                        }
                        else{--posx;}
                    }
                    else if(C[posy][posx]==-3){
                        C[posy][posx]=c;
                        if(posy==0){
                            posy=N-1;
                        }
                        else{--posy;}
                    }
                    else if(C[posy][posx]==-4){
                        C[posy][posx]=c;
                        if(posy==N-1){
                            posy=0;
                        }
                        else{++posy;}
                    }
                    else if(C[posy][posx]>=0){
                        ++c;
                        if(C[posy][posx]==C[i][j]){
                            ++res;
                        }
                        break;
                    }
                }
            }
        }
    }
    printf("%d",res);
    return 0;
}