#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define MAX_N 1010
#define ENDL '\n'
const int mov_r[]={ 0, 0,-1, 1};
const int mov_c[]={ 1,-1, 0, 0};
struct Cell{
    int r,c;
    Cell(int _r=0,int _c=0){
    r=_r;
    c=_c;
    }
};
int nrows,ncolumns;
char maps[MAX_N][MAX_N];
Cell tmp;

bool validCell(int _r, int _c){
    return (0<=_r && _r<nrows && 0<=_c && _c<ncolumns);
}

void bfs(Cell _start){
    queue<Cell> visit;
    Cell current,next;
    maps[_start.r][_start.c]='#';
    visit.push(_start);
    while(!visit.empty()){
        current=visit.front();
        visit.pop();
            for(int i=0;i<4;i++){
                next.c=current.c+mov_c[i];
                next.r=current.r+mov_r[i];
                if(validCell(next.r,next.c) && maps[next.r][next.c]=='.'){
                    maps[next.r][next.c]= '#';
                    visit.push(next);
                }
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);   
    cin>>nrows>>ncolumns;
    
    for(int i=0;i<nrows;i++)
    {
        string line;
        cin>>line;
        for(int j=0;j<ncolumns;j++)
        {
            maps[i][j] = line[j];
        }
    }

    int rooms = 0;
    for(int i=0;i<nrows;i++)
    {
        for(int j=0;j<ncolumns;j++)
        {
            if(maps[i][j]=='.'){
                rooms++;
                bfs(Cell(i,j));
            }
        }
    }
    cout<<rooms<<ENDL;

}