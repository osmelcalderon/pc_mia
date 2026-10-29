#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i=a; i<=b; i++)

vector <pair<int, int> > vp;
int n, a, b, arr[101], sol[101], solq=0;

int main(){
     cin>>n;
     rep(i, 1, n)
     {
       cin>>a>>b;
       vp.push_back({a, b});
    }
    sort(vp.begin(), vp.end());
    rep(i, 0, n-1)
    {
     arr[i]=1;
     sol[i]=1;
    }


      rep(i, 1, n-1)
      for (int k=i-1; k>=0; k--)
      {

        if (vp[i].first>vp[k].first && vp[i].second>vp[k].second && arr[i]+sol[k]>sol[i]) sol[i]=arr[i]+sol[k];
        if (sol[i]>solq) solq=sol[i];
      }
      cout<<solq<<"\n";
return 0;
}