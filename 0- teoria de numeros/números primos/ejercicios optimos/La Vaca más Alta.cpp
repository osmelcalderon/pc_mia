#include <bits/stdc++.h>

using namespace std;

int n, id, h, r;
int linea[10005];
int cows[10005];
set<pair<int, int>> see;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, izq, der;

    cin >> n >> id >> h >> r;
    for(int i=0; i<r; i++){
        cin >> a >> b;
        izq = min(a, b);
        der = max(a, b);
        if(see.find(make_pair(izq, der)) == see.end()){
            linea[izq+1]--;
            linea[der]++;
            see.insert(make_pair(izq, der));
        }
    }

    for(int i=1; i<=n; i++){
        cows[i] = cows[i-1]+linea[i];
    }
    for(int i=1; i<=n; i++){
        cout << (h+cows[i]) << "\n";
    }

    return 0;
}