#include <iostream>
#include <map>
using namespace std;
int main(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.setf(ios::fixed);
    map<pair<int,int>,int>tab;
    int x=0,y=0,q,t=1,X=-1;
    tab[{x,y}]=1;
    cin>>q;
    while(q--){
        char c;
        int n;
        cin>>c>>n;
        while(n--){
            t++;
            if(c=='N')y++;
            if(c=='S')y--;
            if(c=='E')x++;
            if(c=='W')x--;
            if(tab[{x,y}]!=0){
                if(X==-1)X=t-tab[{x,y}];
                else X=min(X,t-tab[{x,y}]);
            }
            tab[{x,y}]=t;
        }
    }
    cout<<X;
}