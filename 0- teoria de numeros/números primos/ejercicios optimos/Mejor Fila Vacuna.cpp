#include <bits/stdc++.h>
#define f first
#define s second
//#define int long long
#define ull unsigned long long
#define par pair<int,int>

using namespace std;

ull Hash[200005],pot[200005],Hash2[200005],pot2[200005],n;
string cad1,cad2;
const int p=31;

ull get_hash(int a, int b){
    return Hash[b]-Hash[a-1]*pot[b-a+1];
}

ull get_hash2(int a, int b){
    return Hash2[b]-Hash2[a-1]*pot2[b-a+1];
}

bool f(int l1,int l2){
    if(cad1[l1]!=cad2[l2]) return cad1[l1]<cad2[l2];
    int r=n-max(l1,l2)-1,l=0;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(get_hash(l1+1,l1+mid+1)==get_hash2(l2+1,l2+mid+1)) l=mid;
        else r=mid;
    }
    int aux;
    if(get_hash(l1+1,l1+r+1)==get_hash2(l2+1,l2+r+1)) aux=r+1;
    else aux=l+1;
    return cad1[l1+aux]<cad2[l2+aux];
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    char a;
    for(int i=0;i<n;i++) cin>>a,cad2+=a;
    cad1=cad2,reverse(cad2.begin(),cad2.end());
    pot[0]=pot2[0]=1;
    for(int i=1;i<=cad1.size();i++) Hash[i]=Hash[i-1]*p+(cad1[i-1]-'0'),pot[i]=pot[i-1]*p;
    for(int i=1;i<=cad2.size();i++) Hash2[i]=Hash2[i-1]*p+(cad2[i-1]-'0'),pot2[i]=pot2[i-1]*p;
    int it1=0,it2=0;
    string solve;
    while(solve.size()<n){
        if(f(it1,it2)) solve+=cad1[it1++];
        else solve+=cad2[it2++];
    }
    for(int i=0;i<solve.size();i++){
        cout<<solve[i];
        if((i+1)%80==0) cout<<"\n";
    }


    return 0;
}