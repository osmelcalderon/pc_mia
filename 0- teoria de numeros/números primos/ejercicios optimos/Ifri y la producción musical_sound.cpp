#include <bits/stdc++.h>

using namespace std;
int n,m,c,a[1000001];
bool NONE;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    deque<int>minimo,maximo;
    for(int i=1;i<=m;i++){
        if(minimo.empty())
            minimo.push_back(a[i]);
        else{
            while(!minimo.empty() && minimo.back()>a[i])
            minimo.pop_back();
            minimo.push_back(a[i]);
        }
        if(maximo.empty())
            maximo.push_back(a[i]);
        else{
            while(!maximo.empty() && maximo.back()<a[i])
                maximo.pop_back();
                maximo.push_back(a[i]);
        }
    }
    if(maximo.front()-minimo.front()<=c){
            NONE=true;
            cout<<1<<"\n";
    }
    for(int i=m+1;i<=n;i++){
        if(minimo.empty())
            minimo.push_back(a[i]);
        else{
            while(!minimo.empty() && minimo.back()>a[i])
                minimo.pop_back();
                minimo.push_back(a[i]);
            }
        if(a[i-m]==minimo.front())
            minimo.pop_front();
        if(maximo.empty())
            maximo.push_back(a[i]);
        else{
            while(!maximo.empty() && maximo.back()<a[i])
                maximo.pop_back();
                maximo.push_back(a[i]);
        }
        if(a[i-m]==maximo.front())
            maximo.pop_front();
        if(maximo.front()-minimo.front()<=c){
            cout<<i-m+1<<"\n";
            NONE=true;
        }
    }
    if(!NONE){
        cout<<"NONE";
    }
    return 0;
}
