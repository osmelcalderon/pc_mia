#include<bits/stdc++.h>
using namespace std;
#define int long long

int mtz[10][10];

int funcion(int a, int b){

    for(int i=a; i>=0; i--){
        for(int j=b; j>=0; j--){
            if(mtz[i][j]==1)
                mtz[i][j]=0;
            else
                mtz[i][j]=1;
        }
    }
    return 1;
}


int32_t main(){
    int n, cnt=0;
    string s;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<n; j++){
            mtz[i][j]=s[j];
            mtz[i][j]-=48;
        }
    }

    for(int i=n-1; i>=0; i--){
        for(int j=i; j>=0; j--){
            if(mtz[i][j]==1){
                cnt+=funcion(i,j);
            }
            if(mtz[j][i]==1){
                cnt+=funcion(j,i);
            }
        }
    }

    cout<<cnt;

    return 0;
}