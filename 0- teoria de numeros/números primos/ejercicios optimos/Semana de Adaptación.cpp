#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","O3")
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <set>
#include <cmath>
//#include <map>
//#include <algorithm>
//#include <stack>
#include <memory.h>
//#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

#define optimized ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcases int tc;cin>>tc;while(tc--)
#define Jojo_Cubano main
#define fs first
#define sc second
#define elif else if
#define pbk(a) pop_back(a)
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define sz(x) ((x).size())
#define mid (l+r)/2
#define left node*2,l,mid
#define right node*2+1,mid+1,r

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef queue<int> qi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;

const int MAXI = INT_MAX;
const int MINI = INT_MIN;
const long MAXL = LONG_MAX;
const long MINL = LONG_MIN;
const long long MAXLL = LONG_LONG_MAX;
const long long MINLL = LONG_LONG_MIN;
const int mod = 1e9 + 7;
const int nmax = 107;



//-------------------------------------------------------------------------------------------------------\\

ll merge(vector<ll> &vec, vector<ll> &temp, int l, int m, int r){
    ll res = 0, i = l, j = m, k = l;
    while ((i <= m - 1) && (j <= r)){
        if (vec[i] <= vec[j])
            temp[k++] = vec[i++];
        else{
            temp[k++] = vec[j++];
            res = res + (m - i);
        }
    }
    while (i <= m - 1)
        temp[k++] = vec[i++];
    while (j <= r)
        temp[k++] = vec[j++];
    for (i=l; i <= r; i++)
        vec[i] = temp[i];
    return res;
}

ll mergesort(vector<ll> &vec, vector<ll> &temp, int l, int r){
    ll m, res = 0;
    if(l < r){
        m = (l + r)/2;
        res  = mergesort(vec, temp, l, m);
        res += mergesort(vec, temp, m+1, r);
        res += merge(vec, temp, l, m+1, r);
    }
    return res;
}

ll answer(vector<ll> vec, int n){
    vector<ll> temp(n);
    return mergesort(vec, temp, 0, n - 1);
}

//-------------------------------------------------------------------------------------------------------\\

int Jojo_Cubano(){
    optimized;
    int n; cin>>n;
    vector<ll> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    cout<<answer(vec, n)<<"\n";
}