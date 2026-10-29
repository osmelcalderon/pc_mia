#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
const int N=1e6+5;
long long ans=1;
int n,col[N];
struct node{
	int l,r;
	bool operator < (const node &rhs) const {
		return l<rhs.l;
	}
}rec[N];
set<pair<int,int> > s1,s2;
vector<int> g[N];
inline void dfs(int pos){
	for(int i:g[pos]){
		if(!col[i]) col[i]=(col[pos]==1? 2:1),dfs(i);
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>rec[i].l>>rec[i].r;
	sort(rec+1,rec+n+1);
	for(int i=1;i<=n;i++){
		while(s1.size()&&(*s1.begin()).first<rec[i].l){
			if((*s1.begin()).first<(*s2.begin()).first) s1.insert(*s2.begin()),s2.erase(s2.begin());
			s1.erase(s1.begin());
		}
		while(s1.size()&&(*s1.begin()).first<rec[i].r){
			g[i].push_back((*s1.begin()).second),g[(*s1.begin()).second].push_back(i);
			s2.insert(*s1.begin()),s1.erase(s1.begin());
		}
		if(s2.size()&&(*s2.begin()).first<rec[i].r) s1.insert(*s2.begin()),s2.erase(s2.begin());
		s1.insert({rec[i].r,i});
	}
	for(int i=1;i<=n;i++){
		if(!col[i]) dfs(i),ans=ans*2%mod;
	}
	for(int i=1;i<=n;i++){
		for(int j:g[i]){
			if(col[i]==col[j]) ans=0;
		}
	}
	cout<<ans%mod<<"\n";
	return 0;
}
