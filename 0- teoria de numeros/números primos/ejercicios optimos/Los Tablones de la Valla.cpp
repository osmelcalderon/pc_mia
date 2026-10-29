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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define u_m unordered_map
int32_t fonsi(){
    ios;
    int n, k; cin>>n>>k;
    vi v(n);
    int s1 = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        if(i < k){
            s1 += v[i]; 
        }
    }
    int s2 = s1, fin = 0;
    for(int i = k; i < n; i++){
        s2 = s2 - v[i - k] + v[i];
        if(s2 < s1){
            s1 = s2;
            fin = i - k + 1;
        }
    }
    cout<<fin + 1;
}