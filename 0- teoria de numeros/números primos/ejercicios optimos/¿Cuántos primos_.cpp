#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define qi queue<int>
#define pii pair<int,int>
#define pq priority_queue<pii,vector<pii>,greater<pii>>
#define f first
#define p_b push_back
#define vii vector<pii>
#define s second
#define double long double
using namespace std;
const int inf=1e18, cero=0;
bitset<50000001>bs;
vi p;
void criba2(){
	bs.set();
	bs[0]=bs[1]=0;
	p.p_b(2);
	p.reserve(3000000);
	int yu=sqrt(50000000);
	for(int i=4; i<=50000000; i+=2)bs[i]=0;
	for(int i=3; i<=yu; i+=2){
		if(bs[i]){
			p.p_b(i);
			for(int j=i*i; j<=50000000; j+=i*2){
				bs[j]=0;
			}
		}
	}
	if(yu%2==0)yu++;
	else yu+=2;
	for(int i=yu+2; i<=50000000; i+=2){
		if(bs[i])p.p_b(i);
	}
}

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
	criba2();
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int a, b;
		cin>>a>>b;
		int y=upper_bound(p.begin(),p.end(),b)-p.begin(), y1=lower_bound(p.begin(),p.end(),a)-p.begin();
		cout<<"Test Case #"<<i<<": "<<y-y1<<"\n";
	}

	return 0;
}