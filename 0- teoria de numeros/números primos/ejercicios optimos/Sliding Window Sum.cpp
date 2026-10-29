#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

int32_t main(){
	
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	cout.setf(ios::fixed);cout.precision(0);

	int n, k;
	int x, a, b, c;
	int ans;
		
	cin>>n>>k;
	
	cin>>x>>a>>b>>c;
	
	n--;
	int temp = k - 1, ac = x, prev = x, num;
	
	while(temp--){
			n--;
			
			num = (prev * a + b) % c;
			ac += num;
			prev = num;
	}
	int last = x, prev2 = x;
	ans = ac;
	
	while(n--){
		
		num = (prev * a + b) % c;
		ac += num;
		
		ac -= last;
		
		last = (a * prev2 + b) % c;
		prev2 = last;
		
		prev = num;
		
		//cout<<ac<<'\n';
		ans ^= ac;
		
		prev = num;	
	}
	
	cout<<ans;
}