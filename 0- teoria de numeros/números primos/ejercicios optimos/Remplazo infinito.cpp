#include<bits/stdc++.h>
using namespace std;

    vector <long long> dp (1001, -1);
    int sol (int n){
        if (n==1) return 2;
        if (dp[n] != -1) return dp[n];
        dp[n]=((sol(n-1)%1000000007)*2)%1000000007;
        return dp[n];

    }
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie (0);

    string s;
    string t;
    int q;

    cin>>q;
    for (int i=1;i<=q;i++){
        cin>>s;
        cin>>t;

        int cont=0;
        for (int j=0;j<=t.size();j++){
            if (t[j]=='a') cont++;
        }
        if (cont==1 && t.size()==1) cout<<1<<"\n";
        else if (cont>=1) cout<<-1<<"\n";
        else cout<<sol (s.size())<<"\n";

        s.clear(); t.clear();
    }

return 0;
}