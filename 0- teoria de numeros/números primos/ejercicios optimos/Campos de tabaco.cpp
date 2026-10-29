#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
 int R,C,Q,valor,WA=0;
 int x1,x2,y1,y2;
 cin>>R>>C>>Q;
 vector<vector<int>>marlon(R+1,vector<int>(C+1,0));

for(int i=1;i<=R;i++){
    for(int j=1;j<=C;j++){
        cin>>valor;
        if(valor>0){
        marlon[i][j]=valor+marlon[i-1][j]+marlon[i][j-1]-marlon[i-1][j-1];
        }else{
        marlon[i][j]=marlon[i-1][j]+marlon[i][j-1]-marlon[i-1][j-1];}

    }}
while(Q--){
cin>>x1>>y1>>x2>>y2;
WA=marlon[x2][y2]-marlon[x1-1][y2]-marlon[x2][y1-1]+marlon[x1-1][y1-1];
cout<<WA<<"\n";
}

}