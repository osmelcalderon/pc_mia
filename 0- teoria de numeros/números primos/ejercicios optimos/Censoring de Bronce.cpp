#include<bits/stdc++.h>
using namespace std;

//\\ PRINCIPAL \\//

#define oo 1e18
#define endl "\n"
#define int long long
#define mod 1000000007
#define tle while(1){;}
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)

//\\ STL \\//

#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define all(x) x.begin(), x.end()

//\\ FAST OPERATIONS \\//

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

int32_t main(){
    ios;
    string s,x;
    cin >> s >> x;

    string aux;
    for(int i = 0;i < s.size();i++){
        aux+=s[i];
        if(aux.size() > x.size() && aux.substr(aux.size() - x.size()) == x){
			aux.resize(aux.size() - x.size());
		}
    }

    cout << aux << endl;

    return 0;
}