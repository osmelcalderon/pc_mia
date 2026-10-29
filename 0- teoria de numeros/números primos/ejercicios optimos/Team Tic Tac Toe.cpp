#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
  fast
    char b[3][3];
    for (int i=0;i<3;i++)
      for (int j=0;j<3;j++)
            cin>>b[i][j];

    set<char>sng;
    set<pair<char, char>>tm;

    auto chk =[&](char x, char y, char z) {
        if (x==y&&y==z) {
            sng.insert(x);
        } else {
            char c[3] = {x,y,z};
            sort(c,c+3);
            if (c[0]!=c[2]) {
                if (c[0]==c[1]||c[1]==c[2]) {
                    char a=c[0],b=c[2];
                    if (a>b) swap(a,b);
                    tm.insert({a,b});
                }
            }
        }
    };

    chk(b[0][0],b[0][1],b[0][2]);
    chk(b[1][0],b[1][1],b[1][2]);
    chk(b[2][0],b[2][1],b[2][2]);
    chk(b[0][0],b[1][0],b[2][0]);
    chk(b[0][1],b[1][1],b[2][1]);
    chk(b[0][2],b[1][2],b[2][2]);
    chk(b[0][0],b[1][1],b[2][2]);
    chk(b[0][2],b[1][1],b[2][0]);

    cout <<sng.size()<<endl;
    cout <<tm.size();

    return 0;
}