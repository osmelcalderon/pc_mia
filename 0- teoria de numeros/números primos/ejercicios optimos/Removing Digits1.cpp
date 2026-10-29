#include <bits/stdc++.h>
#define int long long
#define ENDL '\n'
#define fila first
#define colum second

using namespace std;

signed main(){

    int n; cin>>n;

    int cont = 0;

    while(n>0){
        string num = to_string(n);
        sort(num.rbegin(),num.rend());
        int res = num[0] - '0';
        n-=res;
        cont++;
    }
    cout<<cont<<ENDL;



    return 0;
}