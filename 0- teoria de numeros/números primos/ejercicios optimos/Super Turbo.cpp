#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second

using namespace std;
const int nmax=1e5+2;
int abi1[nmax],abi2[nmax],cad[nmax];
void add(int pos,int val,int mark){
     if(pos==0)return;
     while(pos<=nmax){
        if(mark==1)abi1[pos]+=val;
        else abi2[pos]+=val;
        pos+=(pos&-pos);
     }
}
int query(int pos,int mark){
   int suma=0;
   while(pos>0){
    if(mark==1)suma+=abi1[pos];
    else suma+=abi2[pos];
    pos-=(pos&-pos);
   }
   return suma;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        cad[a]=i;
    }

    int inc=1,fin=n;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
           int aux=cad[inc];
           int aux1=query(n,1)-query(aux,1);
           int aux2=query(aux-1,2);
           add(aux,1,1);
           cout<<(aux+(aux1-aux2))-inc<<"\n";
           inc++;
        }
        else{
           int aux=cad[fin];
           int aux1=query(n,1)-query(aux,1);
           int aux2=query(aux-1,2);
           add(aux,1,2);
           cout<<fin-(aux+(aux1-aux2))<<"\n";
           fin--;
        }
    }



    return 0;
}