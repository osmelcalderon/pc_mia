#include <bits/stdc++.h>
using namespace std;
#define vc vector
#define po Point
#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define le(i,n) for(int i=0;i<(n);i++)
const int mod = 1e9+7;
#define endl '\n'
#define P pair<int, int>
#define X first
#define Y second
#define pb push_back

int32_t main(){
    int n;
    cin>>n;
    string s;
    if((2*n)%3==0){
        s=string((n*2/3),'7');
    } else if((2*n) % 3==1)
    {
        s="1"+string(floor((n*2)/3),'7');
    }
    else
    {
        s="3"+string(floor((n*2)/3),'7');
    }
    cout<<s;
   return 0;
}