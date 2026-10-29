#include <bits/stdc++.h>
using namespace std;

long long vec[200004];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<long long, int> mapp;
    mapp[0] = 1;
    int n;
    vec[0] = 1;
    long long ac=0, c=0;
    cin >> n;
    for(int i=0; i<n; i++){
        int q;
        cin >> q;
        ac+=q;
        vec[(ac % n + n) % n]++;
    }
    for(int i=0; i<n; i++){
        int q=vec[i];
        c+= (vec[i]*(vec[i]-1)) /2;
    }
    cout << c;
    return 0;
}