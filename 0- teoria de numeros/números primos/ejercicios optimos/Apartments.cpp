#include <bits/stdc++.h>

using namespace std;

int main()
{
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      long long n, m, k, c = 0;
      
      cin >> n >> m >> k;
      vector<long long> sol(n), ap(m);
      for(int i = 0; i < n; i++){
           cin >> sol[i];
      }
      
      for(int i = 0; i < m; i++){
          cin >> ap[i];
      }
      sort(sol.begin(),sol.end());
      sort(ap.begin(),ap.end());
      int i = 0, j = 0;
      while(j < m and i < n){
          if(abs(sol[i] - ap[j]) <= k){
             c++;
             i++;
             j++;
          }
          else if(ap[j] < sol[i]) j++;
          else i++;
      }
      cout << c;
      return 0;
}