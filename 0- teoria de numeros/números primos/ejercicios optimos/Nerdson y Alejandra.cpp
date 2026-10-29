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
	int n;
    string s;
    cin>>n>>s;
    int d0=1, d1=0, d2=0, d3=0, d4=0;
    for(int i=0; i<n; i++){
        if(s[i]=='p'){
            d1+=d0;
            d3+=d2;
        } 
		else if(s[i]=='a'){
            d2+=d1;
			d4+=d3;
        }
    }
    cout<<d4;
    
    return 0;
}