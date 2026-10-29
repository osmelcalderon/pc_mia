#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#define rbtree tree<int,null_type,less<>,rb_tree_tag,tree_order_statistics_node_update>
#define opt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rall(v) v.rbegin(),v.rend()
#define all(v) v.end(),v.begin()
#define ppf pop_front()
#define ppb pop_back()
#define int long long
#define pf push_front
#define pb push_back
#define fr front()
#define bk back()
#define s second
#define pp pop()
#define ph push
#define f second

using namespace std;

const int my[]={0,0,1,-1,1,1,-1,-1};
const int mx[]={1,-1,0,0,1,-1,-1,1};
const int md=1e9+7;
const int oo=1e18;

int32_t main(){opt
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];   
    }
    
    int minn=oo;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(j<i){
                sum+=a[j]*(j+(n-i));
            }else{
                sum+=a[j]*(j-i);
            }
        }
        minn=min(minn,sum);
    }
    cout<<minn;
}
