#include<bits/stdc++.h>
using namespace std;
//\\ PRINCIPAL \\//
 
#define oo 1e18
#define endl "\n"
#define mod N007
#define int long long
#define tle while(1){;}
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)
 
//\\ BITS \\//
 
#define bits_1 __builtin_popcount 
 
//\\ STL \\//
 
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lb(x,y) lower_bound(x.begin(),x.end(),y)-x.begin()
#define ub(x,y) upper_bound(x.begin(),x.end(),y)-x.begin()
 
int n;
string s;
 
int dp[19][2][2][11];
int sol(int i,int pl,int pl2,int dig) {
   if(i == n)return 1;
   if(dp[i][pl][pl2][dig] != -1)return dp[i][pl][pl2][dig]; 
   
   int ans = 0,aux = (s[i] - '0'),li;
 
   li = pl == 0? aux : 9;
 
 
   for(int j = 0; j <= li; j++)
   {
      if(dig == j && pl2 == 1)continue;
      int npl = (pl == 1 || j < li)? 1 : 0;
      int npl2 = (pl2 == 1 || j != 0)? 1 : 0;
      ans += sol(i + 1,npl,npl2,j);
   }
 
   return dp[i][pl][pl2][dig] = ans;
}
 
int solve(int x) {
   s = to_string(x);
   n = s.size();
 
   for(int i = 0; i < 19; i++)
   {
      for(int j = 0; j < 2; j++)
      {
         for(int k = 0; k < 2; k++)
         {
            for(int l = 0; l < 11; l++)
            {
               dp[i][j][k][l] = -1;
            }
         }
      }
   }
   return sol(0,0,0,10);
}
 
 
int32_t main() {
 
   int a,b;
   cin >> a >> b;
    
   b = solve(b);
   a = solve(a - 1);
 
   
   cout << b - a << endl;
 
   return 0;
}