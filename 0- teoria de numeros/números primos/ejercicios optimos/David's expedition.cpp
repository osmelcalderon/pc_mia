#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio (0);cin.tie (0);cout.tie (0);

    int n;cin>>n;
    n/=52;
    bool a=1;
    for(int k=1;k<=100;k++){
        for(int x=1;x<=100&&a;x++){
            if(n==((7*x)+(21*k))){
                cout<<x<<"\n"<<k;
                a=0;
            }
        }
    }
}