#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

/*1
4 3
2 2 2 2 2 1 1 1 1 1 1 1*/

const int movf[]={1,-1,0,0};
const int movc[]={0,0,1,-1};

struct graph{
    struct node{
        ll f,c,val=0;
    };
    vector<vector<node>> nod;
    vector<vll> vis;
    
    inline void assign(ll n,ll m){
        nod.assign(n+1,vector<node>(m+1,node()));
        vis.assign(n+1,vll(m+1,0));
    }
    
    inline void bfs(node init,ll ride=1){
        queue<tuple<node,bool>> q;
        q.push({init,0});
        node next;
        
        while(!q.empty()){
            node act;
            bool band;
            tie(act,band)=q.front();
            q.pop();
            //cout<<ride;
            if(vis[act.f][act.c]==ride){
                continue;
            }
            //cout<<act.f<<" "<<act.c<<" ";
            
            for(int i=0;i<4;i++){
                next.f=act.f+movf[i];
                next.c=act.c+movc[i];
                //cout<<9;
                if(ride!=vis[next.f][next.c]){
                    //cout<<9;
                    q.push({next,!band});
                }
            }
            //cout<<ans<<endl;
        }
    }
    
}g;

inline void solve(int t){
    
    ll n;
    cin>>n;
    
    ll ans=0;
    for(ll i=1;i*i*i<=n;i++){
        for(ll j=i;j*j<=n;j++){
            if(i*j>n)break;
            for(ll k=j;k<=n;k++){
                if(i*j*k<=n){
                    if(i==j){
                        if(k==i)ans+=1;
                        else ans+=3;
                    }
                    else{
                        if(k==i||k==j){
                            ans+=3;
                        }
                        else{
                            ans+=6;
                        }
                    }
                }
                else break;
            }
        }
    }
    
    cout<<ans;
   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t=1;
    //cin>>t;
    
    while(t--)solve(t+1);
    
    
    return 0;
}