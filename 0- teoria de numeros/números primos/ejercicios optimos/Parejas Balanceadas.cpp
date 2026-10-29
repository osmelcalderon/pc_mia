#include <bits/stdc++.h>

using namespace std;

int main()
{   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int a,b;
    cin >>a;
    while(a--){
        cin >>b;
        int c=0;
        string cad; cin>>cad;

        if(b%2!=0){
            cout <<"No Balanceada\n";
            continue;
        }

        for(int i=0;i<b;i++){
            if(cad[i]=='>')c++;
            else c--;
                if(c<0){ cout <<"No Balanceada\n";  break;}
    }

        if(c==0)cout<<"Balanceada\n";

    }


    return 0;
}