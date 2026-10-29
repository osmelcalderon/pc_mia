#include <bits/stdc++.h>
using namespace std;

#define SIZE 200000

void chmax(int &a,int b){
    if(a<b)a=b;
}

int n,ans;
vector<int>g[SIZE];
int E[SIZE],dp[SIZE];

void dfs(int v,int p){
    int sum=0,ma=0;
    for(int &i:g[v]){
        if(i==p)continue;
        dfs(i,v);
        sum+=dp[i];
        chmax(ma,dp[i]);
    }
    if(E[v]==1){
        chmax(ans,max(ma+1,sum-1));
    }else{
        chmax(ans,sum);
    }
    dp[v]=max(E[v],sum-E[v]);
}

int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='1')E[i]=1;
    }
    dfs(0,-1);
    cout<<ans<<endl;
}
