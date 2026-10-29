#include <bits/stdc++.h>
#define p_b push_back
#define F first
#define S second
#define ll long long
#define int long long
using namespace std ;

const int MOD = 1e9 + 7 ;
const int INF = 2e9 ;

int n , m , k ;

vector <int> a ;

void input (){
	cin >> n ;
	a.resize (n) ;
	for (auto &i : a)
		cin >> i ;
}

void solve (){
	vector <int> ans (n , 0) ;
	stack <pair <int , int>> s ;
	for (int i = n - 1 ; i >= 0 ; i--){
		while (!s.empty () && s.top ().F <= a [i]){
			s.pop () ;
		}
		if (!s.empty ()){
			ans [i] = s.top ().S + 1 ;
		}
		s.push ({a [i] , i}) ;
	}
	for (auto &i : ans)
		cout << i << '\n' ;
}

int32_t main (){
	ios_base::sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;
	int t = 1 ;
	//cin >> t ;
	while (t--){
		input () ;
		solve () ;
		cout << '\n' ;
	}
	return 0 ;
}