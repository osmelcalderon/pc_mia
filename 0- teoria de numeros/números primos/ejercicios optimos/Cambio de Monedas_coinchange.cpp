/*  
    Maded by Juan_alejandro 
    at (UTC-05:00) 15:33
    6/8/2025
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <memory>
#define endl '\n'
//#define int __int128
#define srt(x) sort(x.begin(),x.end())

using namespace std;
using namespace __gnu_pbds;
struct com{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)const{
        if(a.first==b.first)return a.second<b.second;
        return a.first<b.first;
    }
};

const int MOD=1e9+7;
string tostring128(int n)
{
    
    string res="";
    bool p=false;
    if(n<0)
    {n*=-1;p=true;}
    if(n<0)
    {cout<<"no"<<endl;}
    while(n>=10)
    {
        res.push_back(n%10+'0');
        n/=10;
    }
    res.push_back(n+'0');
    if(p)
    res.push_back('-');
    reverse(res.begin(),res.end());
    
    return res;
}
//no me lo creo :|
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(0);
    cout<<fixed;
    //cout<<tostring128(-1)<<endl;
    vector<int> c={5,10,25,50};
    vector<int> dp(7489 +1,1);
        int sz=0;
        
        for (int i = 1; i <= 7489 ; i++)
        {
            if(i-5>=0)
            dp[i]+=dp[i-5];
        }
        for (int i = 1; i <= 7489 ; i++)
        {
            if(i-10>=0)
            dp[i]+=dp[i-10];
        }
        for (int i = 1; i <= 7489 ; i++)
        {
            if(i-25>=0)
            dp[i]+=dp[i-25];
        }
        for (int i = 1; i <= 7489 ; i++)
        {
            if(i-50>=0)
            dp[i]+=dp[i-50];
        }
    int32_t n;
    while(cin>>n)
    {
        cout<<dp[n]<<endl;
    }
    
    return 0;
}
// Finished at 16:02
