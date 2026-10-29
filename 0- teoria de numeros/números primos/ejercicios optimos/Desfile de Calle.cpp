//hacer sliding window or, la locura de los monos DMOJ, alineacion balanceada
#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define p_b push_back
#define ll long long
#define S second
#define F first
#define int long long
using namespace std ;

const int MOD = 1e9 + 7 ;
const int INF = 2e9 ;

int n , m , k ;

vector <int> a ;

vector <pair <int , int>> tree ;

void input (){
	a.resize (n) ;
	for (auto &i : a)
		cin >> i ;
}

void solve (){
	stack <int> s ;
	int l = 1 ;
	for (int i = 0 ; i < n ; i++){
		if (a [i] == l){
			l++ ;
			continue ;
		}
		if (!s.empty () && s.top () == l){
			l++ ;
			s.pop () ;
			continue ;
		}
		s.push (a [i]) ;
	}
	for ( ; l <= n ; l++){
		if (!s.empty () && s.top () == l){
			s.pop () ;
		}
		else {
			break ;
		}
	}
	if (s.empty ())
		cout << "yes" ;
	else
		cout << "no" ;
}

int32_t main (){
	ios_base::sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;
	int t = 1 ;
	//cin >> t ;
	while (true){
		cin >> n ;
		if (n == 0){
			return 0 ;
		}
		input () ;
		solve () ;
		cout << '\n' ;
	}
	
	return 0 ;
}