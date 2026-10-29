#include <bits/stdc++.h>
    #define int long long

    using namespace std;
    const int nmax=1e5+2;
    int abi[nmax],aux[nmax];
    void add(int k,int v){
       if(k==0)return ;
       while(k<=nmax){
           abi[k]+=v;
           k+=(k&-k);
       }
    }
    int query(int k){
       int suma=0;
       while(k>0){
            //cout<<k<<endl;
          suma+=abi[k];
          k-=(k&-k);
       }
       return suma;
    }

    int32_t main()
    {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
       int n;
       cin>>n;
       int sol=0;
       for(int i=1;i<=n;i++){
          int l,r;
          cin>>l>>r;
          int vl=query(l);
          int vr=query(r);
         

    //      add(l,vl);
    //      add(l+1,-vl);
    //      add(r,vr);
    //      add(r+1,-vr);
          add(l+1,1);
          add(r,-1);
          sol=vr+vl;
         if(vr!=0)sol-=(aux[r]);
         if(vl!=0)sol-=aux[l];
          cout<<sol<<"\n";
          aux[l]+=vl-aux[l];
          aux[r]+=vr-aux[r];
       }
        return 0;
    }