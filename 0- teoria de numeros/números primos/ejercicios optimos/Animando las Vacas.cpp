#include<assert.h>
#include<stdio.h>
#include<limits.h>
#include<algorithm>
 
const int MAXV = 10000+5;
const int MAXE = 100000+5;
 
int v,e;
int cost[MAXV];

struct edge {
    int a,b;
    int l;
    bool operator<(const edge& e) const { return l < e.l; }
};
edge edges[MAXE];
 
int uf_rank[MAXV];
int uf_parent[MAXV];


void uf_init(int v) {
    for (int i=0;i<v;i++)
        uf_parent[i] = i;
}


int uf_find(int v) {
    if (v == uf_parent[v]) return v;
    return (uf_parent[v] = uf_find(uf_parent[v]));
}


void uf_union(int a, int b) {
    a = uf_find(a); b = uf_find(b);
    
    if (uf_rank[a] > uf_rank[b]){
        uf_parent[b] = a;
    } 
	else{
        uf_parent[a] = b;
        if (uf_rank[a] == uf_rank[b]){
        	uf_rank[b]++;
		}
    }
}
 
int main() {

    int ans = INT_MAX;
    
    scanf("%d %d", &v, &e);
    
    for(int i=0;i<v;i++){
        scanf("%d", cost+i);
        
        ans = std::min(ans, cost[i]);
    }
    for(int i=0;i<e;i++){
        scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].l);
        edges[i].a--; edges[i].b--;
        
        edges[i].l *= 2; edges[i].l += cost[edges[i].a]; edges[i].l += cost[edges[i].b];
    }
    std::sort(edges, edges+e); uf_init(v);
    
    for(int i=0;i<e;i++){
        if (uf_find(edges[i].a) == uf_find(edges[i].b)) continue;
        
        ans += edges[i].l; uf_union(edges[i].a, edges[i].b);
    }
 
    printf("%d\n", ans);
 
    return 0;
}