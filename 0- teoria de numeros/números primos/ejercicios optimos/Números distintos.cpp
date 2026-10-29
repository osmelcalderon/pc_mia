#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define s second
#define f first

using namespace std;
const int nmax=1e5+9;
const int nmax1=1e6+2;

int n, q, ar[nmax], abi[nmax], last[nmax1],solucion[nmax];

vector<pair<int, pair<int,int > > > qr;

bool cmp(pair<int, pair<int,int > > a, pair<int, pair<int,int > > b){
    if(a.second.first == b.second.first) return a.second.second < b.second.second;
    return a.second.first < b.second.first;
}
void add(int k,int v){
    if(k <= 0) return;
    while(k<nmax){
     abi[k]+=v;
     k+=k&(-k);
   }
}
int query(int k){
   int sol=0;
  while(k>=1){
    sol+=abi[k];
    k-=k&(-k);
  }
   return sol;
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        qr.push_back({i, {a,b} });
    }
    sort(qr.begin(),qr.end(),cmp);
    for(int i = n; i >= 1; i--){
             add(i,1);
             add(last[ar[i]],-1);
             last[ar[i]]=i;
             int inc=0;
             if(!qr.empty()) inc=qr.back().s.f;

             while(!qr.empty() && inc==i ){
                int fin=qr.back().s.s;
                int pos=qr.back().f;
                int suma=query(fin);
                solucion[pos]=suma;

                qr.pop_back();
                if(!qr.empty())inc=qr.back().s.f;
             }
    }
    for(int i=1;i<=q;i++)cout<<solucion[i]<<"\n";
    fflush(stdin);
	fflush(stdout);
}