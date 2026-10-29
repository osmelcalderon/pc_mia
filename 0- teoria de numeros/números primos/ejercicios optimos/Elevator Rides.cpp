#include<stdio.h>

struct val{
int v,p;
};


int main(){

int N,X;
scanf("%d%d",&N,&X);
int Arr[N];
for(int i=0;i<N;i++)scanf("%d",&Arr[i]);

val DP[(1<<N)+1];
for(int i=0;i<=(1<<N);i++){
        DP[i]={(int)2e9,0};

}
DP[0]={1,0};


for(int i=0;i<(1<<N);i++){
    for(int b=0;b<N;b++){
        if(!(i&(1<<b))){
            int act=i|(1<<b);
            if(DP[i].p+Arr[b]<=X){

            if(DP[act].v>DP[i].v||(DP[act].v==DP[i].v&&DP[act].p>DP[i].p+Arr[b]))
               DP[act]={DP[i].v,DP[i].p+Arr[b]};


          }  else{ if(DP[act].v>DP[i].v+1||(DP[act].v==DP[i].v+1&&DP[act].p>Arr[b]))
                     DP[act]={DP[i].v+1,Arr[b]};



            }
        }
    }
}



printf("%d",DP[(1<<N)-1].v);
return 0;
}