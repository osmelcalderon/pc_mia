#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[1<<n];
    for(int i=1; i<(1<<n); i++){
        cin>>arr[i];
    }
    int i=(1<<n)/2,p=0,cont=0;
    queue<int> q;
    q.push(i);
    while(!q.empty()&&i!=1){
        int x=q.front();
        cout<<arr[x]<<" ";
        q.pop();
        cont++;
        if(x-(i/2)>0)q.push(x-(i/2));
        if(x+(i/2)<(1<<n))q.push(x+(i/2));
        if(cont==(1<<p)){
            cout<<"\n";
            p++;
            cont=0;
            i/=2;
        }
    }
    while(!q.empty()){
        cout<<arr[q.front()]<<" ";
        q.pop();
    }
    return 0;
}