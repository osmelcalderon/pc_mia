#include<iostream>
#pragma GCC optimize("Ofast")
int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.precision(0);
    std::cout.precision(0);
    std::cin.setf(std::ios::fixed);
    std::cout.setf(std::ios::fixed);
    int N,M,aux;
    std::cin>>N>>M;
    int P[N],V[N],DP[M+1]={};
    for(int i=0;i<N;++i){
        std::cin>>P[i];
    }
    for(int i=0;i<N;++i){
        std::cin>>V[i];
    }
    for(int i=0;i<N;++i){
        for(int j=M;P[i]<=j;--j){
            aux=V[i]+DP[j-P[i]];
            DP[j]=(aux>DP[j])?aux:DP[j];
        }
    }
    std::cout<<DP[M];
    return 0;
}