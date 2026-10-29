#include <bits/stdc++.h>

using namespace std;

int func(int a, int b, int N){
    int res=0;
    if(abs(a-b)<=4)res=(5-abs(a-b));
    else if(abs((a+N)-b)<=4)res=(5-abs((a+N)-b));
    else if(abs((b+N)-a)<=4)res=(5-abs((b+N)-a));

    if(res>N)return N;
    return res;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, a, b, c, x, y, z, res=0, mod;
    cin>>N>>a>>b>>c>>x>>y>>z;

    if(N>=5)mod=250;
    else mod=N*N*N;

    if(N>=6){
        int ax=func(a, x, N);
        int by=func(b, y, N);
        int cz=func(c, z, N);

        res=ax;
        if(by!=0)res*=by;
        if(cz!=0)res*=cz;

        cout<<mod-res;
    }else{
        cout<<mod;
    }

    return 0;
}