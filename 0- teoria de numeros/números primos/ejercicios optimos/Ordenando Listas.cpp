//Leandro Eliecer Vazquez Rivero    IPU:Ramon Infante Garcia    G:12mo
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(0); //srand(time(NULL));
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define int long long
#define fs first
#define sd second
#define rsz resize
#define en '\n'

int f(int *arr, int n){
    int i, j, c = 0;
    bool p = 0;
    for(i = 0; i < n - 1; i++){
        p = 0;
        for(j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
                p = 1; c++;
            }
        }
        if (p == 0) break;
    }
return c;
}

int32_t main(){
    fast
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n ; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    cout << min(f(a, n), f(b, m));
return 0;
}