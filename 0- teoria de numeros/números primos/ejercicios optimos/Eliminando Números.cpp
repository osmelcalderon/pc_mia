#include <bits/stdc++.h>

using namespace std;

bitset<5000000> primos;
int v[11];

void criba(int a){
    primos.set();
    primos[0] = primos[1] = 0;
    for(int i=4; i<=a; i+=2)  primos[i]=0;

    for(int i=3; i*i<=a; i+=2){
        if(primos[i]){
             for(int j=i*i; j<=a; j+=2*i) primos[j]=0;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int cont=0,n;
    int maximo=0;

    for(int x=0;x<10;x++){
        cin>>v[x];
        maximo=max(maximo,v[x]);
    }

    criba(maximo);

    for(int x=0;x<10;x++){
        cont=1;
        for(int i=3; i<=v[x]; i+=2){
            if(primos[i]) cont++;
        }
        cout<<cont<<"\n";
    }

    return 0;
}