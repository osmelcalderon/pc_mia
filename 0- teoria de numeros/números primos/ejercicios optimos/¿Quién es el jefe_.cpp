#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vpi vector<pii>
#define MOD 1000000007
#define INF (int)2e18
#define mod(x) (((x)%MOD+MOD)%MOD)
#define MAX 200005

vi pad(MAX), cost(MAX);

int dfs(vector<vi> &G, int pos, int pa){
    pad[pos] = pa;
    int sum = 0;
    for(auto &i : G[pos]){
        if(i != pa){
            sum += dfs(G, i, pos);
        }
    }
    cost[pos] = sum;
    return sum+1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);
    int T;
    cin >> T;
    
    while(T--){
        int n, q, x, y, z;
        cin >> n >> q;

        map<int,int> id, pr, id2;
        set<int> hi;
        int cont = 1;

        vector<vi> G(n+1);

        vector<pair<pii,int>> val;

        for(int i = 1; i <= n; i++){
            cin >> x >> y >> z;
            if(!id.count(x)){
                id2[cont] = x;
                id[x] = cont++;
            }
            val.push_back({{z, y}, id[x]});
        }

        sort(val.rbegin(), val.rend());

        int in;

        for(auto &[i,j] : val){
            if(hi.empty()){
                hi.insert(i.second);
                pr[i.second] = j;
                in = j;
                continue;
            }
            int aux = *hi.upper_bound(i.second);
            G[pr[aux]].push_back(j);
            hi.insert(i.second);
            pr[i.second] = j;
        }

        dfs(G, in, 0);

        while(q--){
            cin >> x;
            cout << id2[pad[id[x]]] << " " << cost[id[x]] << "\n";
        }
        
    }
    
    return 0;
}