#include <bits/stdc++.h>

using namespace std;
int t,numerador[1000001],cant[26];
vector<int>primes;
bool p[1000001];
void sieve(){
for(int i=4;i<=1000000;i+=2)
        p[i]=1;
primes.push_back(2);
for(long long i=3;i<=1000000;i+=2)
    if(p[i]==0){
        for(long long j=i*i;j<=1000000;j+=2*i)
            p[j]=1;
        primes.push_back(i);
}
}
int modpow(int val,int exp){
    int ans=val%10;
    for(int i=1;i<exp;i++)
    ans=(ans%10*val%10)%10;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    sieve();
    while(t--){
        string s;
    cin>>s;
    long long n=s.size();
    for(int i=0;i<n;i++)
        cant[s[i]-'a']++;
    for(int i=0;i<primes.size();i++){
            if(primes[i]>n)
            break;
            long long primo=primes[i],exponente=0;
        while(primo<=n){
            exponente+=n/primo;
            primo*=primes[i];
        }
        numerador[primes[i]]=exponente;
    }
    for(int i=0;i<26;i++){
        if(cant[i]==0)
            continue;
        long long total=cant[i];
        for(int i=0;i<primes.size();i++){
            if(primes[i]>total)
            break;
            long long primo=primes[i],exponente=0;
        while(primo<=total){
            exponente+=total/primo;
            primo*=primes[i];
        }
        numerador[primes[i]]-=exponente;
    }
    cant[i]=0;
    }
    int ans=1;
    int temp=numerador[2];
    numerador[2]-=min(numerador[5],numerador[2]);
    numerador[5]-=min(numerador[5],temp);
    for(int i=2;i<=n;i++){
        if(numerador[i])
        ans=ans*modpow(i,numerador[i])%10;
        numerador[i]=0;
    }
    cout<<ans;
        cout<<"\n";
    }
    return 0;
}