#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
#include<climits>
#include<set>
#include<string>
#include<unordered_map>
using namespace std;
#pragma GCC optimize("Ofast")
#define fonsi main
#define ll long long 
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define ordenar(x) sort(x.begin(), x.end())
#define rordenar(x) sort(x.rbegin(), x.rend())
#define mem(arr, n) memset(arr, n, sizeof(arr))
#define pq priority_queue
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define str string
#define endl '\n'
#define all(x) x.begin(), x.end()
#define u_m unordered_map
void solve(){
	int n; cin>>n;
	vi v(n);
	for(int &i : v){
		cin>>i;
	}
	int u = *max_element(all(v));
	vi a(u + 1, 0);
	for(int i : v){
		a[i]++;
	}
	for(int i = u; i >= 1; i--){
		if(a[i] >= 2){
			cout<<i;
			break;
		}
		int cont = 0;
		for(int j = 0; j <= u; j+=i){
			if(a[j] >= 1){
				cont++;
			}
		}
		if(cont >= 2){
			cout<<i; break;
		}
	}
}
int32_t fonsi(){
    ios;
    solve();
}