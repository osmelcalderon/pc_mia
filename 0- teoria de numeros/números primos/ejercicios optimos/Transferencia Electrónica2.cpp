#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 12
#define Node pair<int, float>
#define INF 1<<30

struct cmp{
	bool operator()(const Node &a, const Node &b){
		return a.second > b.second;
	}
};

vector <Node> ady[MAX];
float distancia[MAX];
bool visitado[MAX];
priority_queue <Node, vector <Node>, cmp> Q;
int v;

void init(){
	for(int i = 0; i <= v; ++i){
		distancia[i] = INF;
		visitado[i] = false;
	}
}

void relajacion(int actual, int adyacente, float peso){
	if(distancia[actual] + peso < distancia[adyacente]){
		distancia[adyacente] = distancia[actual] + peso;
		Q.push(Node(adyacente, distancia[adyacente]));
	}
}

void dijkstra(int inicial){
	init();
	Q.push(Node(inicial, 0));
	distancia[inicial] = 0;
	int actual, adyacente;
	float peso;
	while(!Q.empty()){
		actual = Q.top().first;
		Q.pop();
		if(visitado[actual]) continue;
		visitado[actual] = true;
		
		for(int i = 0; i < (int) ady[actual].size(); ++i){
			adyacente = ady[actual][i].first;
			peso = ady[actual][i].second;
			if(!visitado[adyacente]){
				relajacion(actual, adyacente, peso);
			}
		}
	}
}

int main(){
	int e, t, n, inicio, final, origen, destino;
	vector <Node> id;
	id.resize(MAX);
	float peso;
	
	scanf("%d %d %d %d %d", &v, &e, &t, &inicio, &final);
	while(e--){
		scanf("%d %d %d %f", &n, &origen, &destino, &peso);
		id[n].first = origen;
		id[n].second = destino;
		ady[origen].push_back(Node(destino, peso));
		ady[destino].push_back(Node(origen, peso));
	}
	
	for(int i = 0; i < t; i++){
		scanf("%d", &n);
		int primero, segundo;
		primero = id[n].first;
		segundo = id[n].second;
		ady[primero][segundo].second = INF;
		ady[segundo][primero].second = INF;
	}
	
	dijkstra(inicio);
	
	printf("%.2f", distancia[final]);
	
	return 0;
}