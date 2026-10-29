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
#define int long long 
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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define u_m unordered_map
const int maxn = 1e5 * 5 + 1;
int arr[maxn];
int tree[maxn * 4];
void build(int u, int l, int r){
	if(l == r){
		tree[u] = arr[l];
		return;
	}
	int mid = (l + r)/2;
	build(2 * u, l, mid);
	build(2 * u + 1, mid + 1, r);
	tree[u] = tree[u * 2] + tree[u * 2 + 1];
}
int query(int u, int l, int r, int ql, int qr){
	if(ql <= l and qr >= r){
		return tree[u];
	}
	int mid = (l + r)/2;
	int fin = 0;
	if(ql <= mid){
		fin += query(u * 2, l, mid, ql, qr);
	}
	if(qr >= mid + 1){
		fin += query(u * 2 + 1, mid + 1, r, ql, qr);
	}
	return fin;
}
void update(int u, int start, int end, int idx, int v){
    if(start == end){ 
        tree[u] += v;
        return;
    }
    int mid = (start + end)/2;
    if(idx <= mid){
        update(2 * u, start, mid, idx, v);
    }else{
        update(2 * u + 1, mid + 1, end, idx, v); 
    }
    tree[u] = tree[2 * u] + tree[2 * u + 1];
}
int32_t fonsi(){
    ios;
    int n; cin>>n;
    for(int i = 0; i < n; i++){
    	cin>>arr[i];
    }
    build(1, 0, n - 1);
    int t; cin>>t;
    while(t--){
    	char c;
    	int n1, n2;
    	cin>>c>>n1>>n2;
    	if(c == 'R'){
    		cout<<query(1, 0, n - 1, n1 - 1, n2 - 1)<<endl;
    	}else{
    		update(1, 0, n - 1, n1 - 1, n2);
    	}
    }
}