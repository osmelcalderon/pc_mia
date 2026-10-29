#include<stdio.h>
#include<vector>
#include<queue>
struct node{
    int V,W;
    bool operator<(const node&N)const{return W>N.W;}
};
int main(){
    int N,M,S,u,v,w,p,c1=0,c2=0;
    scanf("%d%d%d",&N,&M,&S);
    std::vector<node>graph_1[N+1];
    std::vector<node>graph_2[N+1];
    std::vector<int>cost(N+1,-1);
    std::vector<int>cost2(N+1,-1);
    std::priority_queue<node>pq;
    std::priority_queue<node>pq2;
    while(M--){
        scanf("%d%d%d",&u,&v,&w);
        graph_1[u].push_back({v,w});
        graph_2[v].push_back({u,w});
    }
    pq.push({S,0});
    pq2.push({S,0});
    while(1){
        u=pq.top().V;
        w=pq.top().W;
        v=pq2.top().V;
        p=pq2.top().W;
        pq.pop();
        pq2.pop();
        if(cost[u]==-1){
            cost[u]=w;
            ++c1;
            for(node X:graph_1[u]){
                pq.push({X.V,X.W+w});
            }
        }
        if(cost2[v]==-1){
            cost2[v]=p;
            ++c2;
            
            for(node X:graph_2[v]){
                pq2.push({X.V,X.W+p});
            }
        }
        if(c2==N&&c1==N){break;} 
    }
    for(int i=1;i<=N;++i){
        c1=cost[i]+cost2[i];
        M=(M<c1)?c1:M;
    }
    printf("%d",M);
    return 0;
}