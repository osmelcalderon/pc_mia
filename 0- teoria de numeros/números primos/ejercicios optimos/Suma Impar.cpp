#include <bits/stdc++.h>

using namespace std;

int A[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,T=0,I=9999999;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> A[i];
        if(A[i]>0)T+=A[i];
        if(abs(A[i])<I&&A[i]%2!=0)I=abs(A[i]);
    }
    if(T%2!=0)cout << T;
    else cout << T-I;
    return 0;
}