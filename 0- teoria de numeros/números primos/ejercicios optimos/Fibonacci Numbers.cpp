#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define vvll vector<vll>
const vvll uno={{1,0},{0,1}};
const ll mod=1000000007;
vvll mult(vvll x, vvll y){
    vvll z(x.size(),vll(y[0].size(),0));
    for(int i=0;i<x.size();i++){
        for(int j=0;j<y[0].size();j++){
            for(int k=0;k<y.size();k++){
                z[i][j]=(((x[i][k]*y[k][j])%mod)+z[i][j])%mod;
            }
        }
    }
return z;
}
vvll qpow(vvll a,ll b){
    if(b==0)return uno;
    if(b%2==0)return qpow(mult(a,a),b/2);
return mult(qpow(mult(a,a),b/2),a);
}
int main(){
    ll t1;
    cin>>t1;
    vvll fiv={{1,1},{1,0}};
 
    fiv=qpow(fiv,t1+1);
   // fiv=mult(fiv,uno);
    cout<<fiv[1][1];
return 0;
}