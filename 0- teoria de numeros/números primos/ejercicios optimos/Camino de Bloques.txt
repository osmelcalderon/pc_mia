#include<bits/stdc++.h>
using namespace std;

class object{
public:
    int ended, cost;
object(){};
object(int e, int c){
    ended = e;
    cost = c;
}
bool operator > (const object& a) const{
return cost>a.cost;
}
};

int n, m;
int dist[105];
vector <object> vec[104];
vector <int> tp;
int prv[103];
int inf = 100000000;
int visit[103];

void init(){
    for(int i=1; i<=n; i++){
        dist[i] = inf;
        visit[i] = 0;
    }
}

void pr(int d){
    tp.push_back(d);
    if(prv[d] != -1){
        pr(prv[d]);
    }

}

void dijkstra(int start){
    init();
    prv[start] = -1;
    priority_queue<object, vector<object>, greater<object> > tail;
    object u, v, f;
    int act, ady, m;
    int pso;

    tail.push(object(start, 0));
    dist[start] = 0;
    for(int nsaw=0; nsaw<n; nsaw++){
        do{
            if(tail.empty()) return;
            u = tail.top(); tail.pop();
            act = u.ended;

        }while(visit[act] == 1);

        visit[act] = 1;
        m = vec[act].size();
        for(int i=0; i<m; i++){
            v = vec[act][i];
            ady = v.ended;
            pso = v.cost;
            if(dist[ady] > dist[act] + pso){
                dist[ady] = dist[act] + pso;
                tail.push(object(ady, dist[ady]));
                prv[ady] = act;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int r=0, d;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back(object(b, c));
        vec[b].push_back(object(a, c));
    }
    dijkstra(1);
    pr(n);
    d = dist[n];
 
    reverse(tp.begin(), tp.end());
    for(int i=0; i<tp.size()-1; i++){
        int q = tp[i+1];
        int p = tp[i];
        for(int j=0; j<vec[p].size(); j++){
            if(vec[p][j].ended == q){
                vec[p][j].cost*=2;
                dijkstra(1);
                vec[p][j].cost/=2;
                r = max(dist[n] - d, r);
                break;
            }
        }
    }
    cout << r << "\n";
    return 0;
}