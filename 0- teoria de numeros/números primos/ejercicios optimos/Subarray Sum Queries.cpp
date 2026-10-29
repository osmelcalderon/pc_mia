#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define ve vector
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define vec vector
 
int n,q;
const int N=400005;
 
struct st{
	int pre;
	int suf;
	int sum;
	int sub;	
};
 
vector<int>a(N);
vec<st>tree(2*N);
 
void up(int i,int v,int nod,int l,int r){
	if(r<i||i<l)return;
	if(l==r){
		tree[nod].pre=max(0LL,v);
		tree[nod].suf=max(0LL,v);
		tree[nod].sum=v;
		tree[nod].sub=max(0LL,v);
		return;
	}
	int m=(l+r)/2;
	
	up(i,v,2*nod,l,m);
	up(i,v,2*nod+1,m+1,r);
	
	tree[nod].pre=max(0LL,max(0LL,max(tree[2*nod].pre,tree[2*nod].sum+tree[2*nod+1].pre)));
	tree[nod].suf=max(0LL,max(0LL,max(tree[2*nod+1].suf,tree[2*nod+1].sum+tree[2*nod].suf)));
	tree[nod].sum=tree[2*nod].sum+tree[2*nod+1].sum;
	tree[nod].sub=max(max(0LL,0LL),max(
		tree[2*nod].suf+tree[2*nod+1].pre,max(
		max(tree[2*nod].sub,tree[2*nod+1].sub),
		tree[2*nod].sum+tree[2*nod+1].sum)
	));
}
 
int32_t main(){
	
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		up(i,a[i],1,1,n);
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		up(x,y,1,1,n);
		cout<<tree[1].sub<<"\n";
	}
	
	return 0;
}