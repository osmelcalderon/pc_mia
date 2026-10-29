#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int cas;
    cin>>cas;

    for(int i=0; i<cas; i++){
        int n, adl, atr, pos, fin;
        cin>>n>>adl>>atr>>pos>>fin;
        int arr[n+1], cnt=0, a=0;

        for(int j=0; j<=n; j++)
            arr[j]=1;
        arr[pos]=0;

        while(pos!=fin){
            int t=0;

            if(pos<fin && pos+adl<=n && arr[pos+adl]==1){
                pos+=adl;
                arr[pos]=0;
                cnt++;
                t=1;
            }
            else
                if(pos-atr<1 && pos+adl<=n && arr[pos+adl]==1){
                    pos+=adl;
                    arr[pos]=0;
                    cnt++;
                    t=1;
                }
            else if(pos>fin && pos-atr>=1 && arr[pos-atr]==1){
                pos-=atr;
                arr[pos]=0;
                cnt++;
                t=1;
            }
            else
                if(pos+adl>n && pos-atr>=1 && arr[pos-atr]==1){
                    pos-=atr;
                    arr[pos]=0;
                    cnt++;
                    t=1;
                }
            if(t==0){
                a=1;
                pos=fin;
            }
        }
        if(a==0) cout<<cnt<<endl;
        else cout<<"NUNCA"<<endl;
    }


    return 0;
}