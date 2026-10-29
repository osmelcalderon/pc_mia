#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

#define int long long
#define lft 2*p
#define rgt 2*p+1
#define pb push_back
#define mdl (l+r)/2
#define MAX 1005
#define s second

struct vaca{
    int i, f, c;
};
struct aire{
    int i, f, g, c;
};
vector<int> usados;
int res;
int resf;
vaca vacas[50];
aire ac[50];
int granero[200];
int N, M;

bool check(){

    for(int j=0; j<=100; j++){
    int aux=0;
        for(auto x:usados){
            int i=ac[x].i;int f=ac[x].f;
            int g=ac[x].g;
            if(i<=j && j<=f)aux+=g;
        }

        int aux2=0;
        for(int k=0; k<N; k++){
            int i=vacas[k].i;
            int f=vacas[k].f;
            int c=vacas[k].c;
            if(i<=j && j<=f){
                aux2=c;
                break;
            }
        }
        if(aux<aux2)return false;
    }
    return true;
}

void solve(){
    cin >> N >> M;

    int a, b, c, d;
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        vacas[i]={a,b,c};
    }
    for(int i=0; i<M; i++){
        cin >> a >> b >> c >> d;
        ac[i]={a,b,c,d};
    }


    resf=1e9;
    for(int i=0; i<(1<<M); i++){
        res=0;
        usados.clear();
        for(int j=0; j<M; j++){
            if(i&(1<<j)){
                usados.pb(j);
                res+=ac[j].c;
            }
        }
        if(check())resf=min(res,resf);
    }
    cout << resf;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;//cin >> T;

    for(int i=0;i<T;i++){
        solve();
    }

    return 0;
}