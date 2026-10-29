//Heno para la Venta
#include<iostream>
#define int long long
using namespace std;

int f_max(int a, int b){
    return a > b ? a : b;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c, h, s = 0, solve = 0;
    cin >> c >> h;
    int v[h];

    for(int i = 0; i < h; i++){
        cin >> v[i];
    }

    for(int i = 0; i < h; i++){
        for(int j = i; j < h; j++){
            if(s + v[j] < c)
                s += v[j];
            else if(s + v[j] == c){
                s += v[j]; break;
            }
            else continue;
        }
        solve = f_max(s, solve); s = 0;
    }
    cout << solve;
return 0;
}
