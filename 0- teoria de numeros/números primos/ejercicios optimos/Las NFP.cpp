#include<bits/stdc++.h>
using namespace std;
#define LG int main
int xmax=0,xmin=0;
void BitCoin(int n,int m) {



    char aux;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> aux;
            if(xmin==0){
           if(aux=='#')xmin=i;
        }
        if(aux=='#')xmax=i;
        }
    }
}

LG()
{
ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t,n,m;
    cin >> t >> n >> m;
    for (int i=0; i<t; i++) {
        BitCoin(n,m);
        cout << abs(xmax-xmin) << endl;
        xmax=0;
        xmin=0;
    }
    return 0;
}