#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001
#define Node pair<int, int>
#define INF 1<<30

struct cmp{
	bool operator()(const Node &a, const Node &b){
		return a.second > b.second;
	}
};

vector <Node> ady[MAX];
int distancia[MAX];
bool visitado[MAX];
priority_queue <Node, vector <Node>, cmp> Q;
int v;

void init(){
	for(int i = 0; i <= v; ++i){
		distancia[i] = INF;
		visitado[i] = false;
	}
}

void relajacion(int actual, int adyacente, int peso){
	if(distancia[actual] + peso < distancia[adyacente]){
		distancia[adyacente] = distancia[actual] + peso;
		Q.push(Node(adyacente, distancia[adyacente]));
	}
}

void dijkstra(int inicial){
	init();
	Q.push(Node(inicial, 0));
	distancia[inicial] = 0;
	int actual, adyacente, peso;
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
	int e, origen = 0, destino, peso, demo[MAX];
	
	scanf("%d", &v);
	for(int i = 1; i <= v; i++){
		scanf("%d %d", &peso, &e);
		demo[i] = peso;
		while(e--){
			scanf("%d", &destino);
			ady[i].push_back(Node(destino, peso));
		}
	}
	
	dijkstra(1);
	
	for(int i = 1; i <= v; i++)
		if(distancia[i] + demo[i] > origen) origen = distancia[i] + demo[i];
	
	printf("%d", origen);
	
	return 0;
}