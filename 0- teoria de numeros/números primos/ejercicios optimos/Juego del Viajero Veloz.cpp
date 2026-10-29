#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

#define int long long
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>

#define srt(v) sort(all(v))
#define rev(v) reverse(all(v))
#define all(v) (v).begin(), (v).end()
#define dbg(x) cout << #x ": " << x << endl;

#define lft 2*p
#define rgt 2*p+1
#define mdl (l+r)/2
#define p push
#define f first
#define s second
#define pb push_back
#define MAX 1000000

int jugador[20],
    casilla[150];
bool jugando[20];
vector<int> ganadores;

void print(){
    if(ganadores.size()){
        for(auto x:ganadores)cout << x << " ";
        cout << "\n";
    }
    else cout << "-1\n";
    ganadores.clear();
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;cin >> T;

    int N, C, P;
    while(T--){
        cin >> N >> C >> P;
        memset(jugando,true,sizeof(jugando));
        for(int i=1; i<=N; i++)jugador[i]=1;
        for(int i=1; i<=C; i++)cin >> casilla[i];
        int p, j=1;
        int r=N;
        while(P--){
            cin >> p;
            jugador[j]+=p;
            jugador[j]+=casilla[jugador[j]];
            if(jugador[j]==C){
                ganadores.pb(j);
                jugando[j]=false;
                r--;
            }
            if(!r)break;
            j++;
            if(j==N+1)j=1;
            while(!jugando[j]){j++;if(j==N+1)j=1;}
        }
        print();
    }
    return 0;
}