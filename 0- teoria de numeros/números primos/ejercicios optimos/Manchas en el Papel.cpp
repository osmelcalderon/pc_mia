#include <bits/stdc++.h>
#define fast_in ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
using namespace std;
class par{
public:
    int x;
    int y;
    par(int xx,int yy){
        x=xx;
        y=yy;
    }
};
vector<vector<char>>V;
queue<par>cola;
int ady_x[]={1,0,-1,0};
int ady_y[]={0,1,0,-1};

int BFS(int R,int C){
    int I=1;
    while(!cola.empty()){
        par N=cola.front(); cola.pop();
        int a=N.x;
        int b=N.y;
        for(int i=0;i<4;i++){
            int xx=a+ady_x[i];
            int yy=b+ady_y[i];
            if(xx>=0&&xx<R&&yy>=0&&yy<C){
                if(V[xx][yy]!='0'){
                    I+=1;
                    V[xx][yy]='0';
                    cola.push(par(xx,yy));
                }
            }
        }
    }
    return I;
}

int main()
{
    fast_in
   
    int R,C,I,M=0,I1=0;

    cin >> R >> C;

    V.resize(R);

    for(int i=0;i<R;i++){
        V[i].resize(C);
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> V[i][j];
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(V[i][j]=='1'){
                cola.push(par(i,j));
                V[i][j]='0';
                I=BFS(R,C);
                if(M<I)M=I;
                I1++;
            }
        }
    }
    cout << I1 << " " << M;
     /*for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << V[i][j];
        }
        cout << "\n";
    }*/
    return 0;
}