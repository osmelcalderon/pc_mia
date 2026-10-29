#pragma GCC optimize(O4)
#include <bits/stdc++.h>

using namespace std;
const int nmax=3e5+4;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    long long suma=0,suma1=0;
    for(int i=1;i<=n;i++){
         int aux;
         cin>>aux;
         suma+=(aux*aux);
         suma1+=aux;
    }
    cout<<(suma*n)-(suma1*suma1);


    return 0;
}