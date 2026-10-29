#include<bits/stdc++.h>
using namespace std; 

vector<int> v[51]; 
bool vis[51]; 
int prof[51]; 

void bfs(int n) { 
	queue<int> cola; 
	cola.push(n); 
	
	vis[n]=1; prof[n]=1; 
	
	while(!cola.empty()) { 
		int nod=cola.front(); 
		cola.pop(); 
		
		for(auto i: v[nod]) { 
			if(!vis[i]) { 
				vis[i]=1; 
				prof[i]=prof[nod]+1; 
				cola.push(i); 	
			}
		}
	}	 
}

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin>>t; 
	while(t--) {
		int n; //numero de pag web
		int l; //la cantidad de enlaces 
		int q; //la cantidad de pruebas
		cin>>n>>l>>q; 
		
		for(int i=1; i<=n; i++) { 
			vis[i]=false; 
			v[i].clear(); 
  		}
		
		while(l--) {
			int s; //la fuente del enlace
			int d; //el destino.
			cin>>s>>d; 
			v[s].push_back(d);
		}
		bfs(1); 
		while(q--) { 
			int p; //pag web seleccionada para la prueba. 
			cin>>p; 
			if(!vis[p]) { 
				vis[p]=1;
				prof[p]=-1; 
			}
			cout<<prof[p]<<"\n"; 
		}
	}
}