#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std; 

#define db double
#define fs first 
#define sd second

const db Inf = 1e9 + 7; 

vector <vector<db>> conected;
vector <pair<db, db>> coordinate;  

vector <double> point; 
vector <bool> pass; 

double positive(double x)
{
	if (x < 0) return (x * db(-1.0));
	return x; 
}

double distance(db x1, db y1, db x2, db y2)
{
	db X = x1 - x2; X = positive(X); 
	db Y = y1 - y2; Y = positive(Y); 

	double ans = sqrt(pow(X, 2) + pow(Y, 2)); 

	return ans; 
}

int main()
{
	int N, W; db M;  cin >> N >> W >> M;

	coordinate.assign(N + 1, { 0, 0 }); 
	point.assign(N + 1, Inf);  
	pass.assign(N + 1, false); 

	for (int i = 1; i <= N; i++)
	{
		cin >> coordinate[i].first
			>> coordinate[i].second; 
	}

	conected.assign(N + 1, vector<db>()); 

	for (int i = 1; i <= W; i++)
	{
		db a, b; cin >> a >> b; 

		conected[a].push_back(b); 
		conected[b].push_back(a); 
	}

	priority_queue <pair<db, db>> pq; pq.push({ 0, 1 }); 

	point[1] = 0; 

	while (!pq.empty())
	{
		db a = pq.top().second; pq.pop();

		if (pass[a]) continue; 
		pass[a] = true; 

		for (auto u : conected[a])
		{ 
			if (point[a] < point[u])
			{
				point[u] = point[a]; 
				pq.push({ -point[u], u }); 
			}
		}

		for (int i = 1; i <= N; i++)
		{
			if (pass[i]) continue; 

			db w = distance(coordinate[a].fs, coordinate[a].sd,
			             	coordinate[i].fs, coordinate[i].sd);

			if (w > M) continue; 

			if (point[a] + w < point[i])
			{
				point[i] = point[a] + w; 
				pq.push({ -point[i], i }); 
			}
		}
	}

	long long ans = (point[N] * 1000);

	cout << (ans != Inf * 1000 ? ans : -1) << endl; 

	return 0; 
}