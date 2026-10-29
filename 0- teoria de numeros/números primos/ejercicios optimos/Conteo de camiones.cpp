#include<bits/stdc++.h>
#define int long long
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

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
	int n, l, cont=0;
	cin>>n>>l;
	for(int lo=1; lo<8; lo++){
		for(int i=1; i<=9; i++){
			if(i==l)continue;
			if(lo==1)cont++;
			if(cont==n){
				cout<<i;
				return 0;							
			}
			if(lo==1)continue;
			for(int i1=0; i1<=9; i1++){
				if(i1==l)continue;
				if(lo==2)cont++;
				if(cont==n){
					cout<<i1+(i*10);
					return 0;							
				}
				if(lo==2)continue;
				for(int j=0; j<=9; j++){
					if(j==l)continue;
					if(lo==3)cont++;
					if(cont==n){
						cout<<j+(i1*10)+(i*100);
						return 0;							
					}
					if(lo==3)continue;
					for(int k=0; k<=9; k++){
						if(k==l)continue;
						if(lo==4)cont++;
						if(cont==n){
							cout<<k+(j*10)+(i1*100)+(i*1000);
							return 0;							
						}
						if(lo==4)continue;
						for(int m=0; m<=9; m++){
							if(m==l)continue;
							if(lo==5)cont++;
							if(cont==n){
								cout<<m+(k*10)+(j*100)+(i1*1000)+(i*10000);
								return 0;							
							}
							if(lo==5)continue;
							for(int ll=0; ll<=9; ll++){
								if(ll==l)continue;
								if(lo==6)cont++;
								if(cont==n){
									cout<<ll+(m*10)+(k*100)+(j*1000)+(i1*10000)+(i*100000);
									return 0;							
								}
								if(lo==6)continue;
								for(int fi=0; fi<=9; fi++){
									if(fi==l)continue;
									cont++;
									if(cont==n){
										cout<<fi+(ll*10)+(m*100)+(k*1000)+(j*10000)+(i1*100000)+(i*1000000);
										return 0;							
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}