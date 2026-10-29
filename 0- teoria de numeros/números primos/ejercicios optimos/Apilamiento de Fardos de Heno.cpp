#include <bits/stdc++.h>

using namespace std;

vector<int>tabla;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,K,I,f;

    cin >> N >> K;

    tabla.resize(N+1);

    for(int i=0;i<K;i++){
        cin >> I >> f;
        tabla[I]+=1;
        if(f<N)tabla[f+1]+=-1;
    }
    for(int i=1;i<=N;i++){
        tabla[i]+=tabla[i-1];
    }
    sort(tabla.begin(),tabla.end());

    cout << tabla[N/2+1];

    return 0;
}