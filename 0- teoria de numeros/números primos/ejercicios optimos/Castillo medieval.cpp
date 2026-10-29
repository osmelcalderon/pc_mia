// DMOJ - Castle.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> M;
vector<vector<bool>> visited;
//NESW
int dx[] = { 0, 1,0, -1 };
int dy[] = { -1, 0, 1, 0 };

// Directions: 0 = North, 1 = East, 2 = South, 3 = West
//map of first 16 numbers to binary representations
map<int, string> binaryMap = {
	{0, "0000"}, {1, "0001"}, {2, "0010"}, {3, "0011"},
	{4, "0100"}, {5, "0101"}, {6, "0110"}, {7, "0111"},
	{8, "1000"}, {9, "1001"}, {10, "1010"}, {11, "1011"},
	{12, "1100"}, {13, "1101"}, {14, "1110"}, {15, "1111"}
};

bool isValid(int x, int y, int n)
{
	return (x >= 0 && x < n && y >= 0 && y < n);
}
int maxAns = 0;
pii leftTop = { 0,0 };
pii rightBottom = { 0,0 };


vector<pii> ValidMovesFromBinary(int x) {
	vector<pii> validMoves;
	string binary = binaryMap[x];
	for (int i = 0; i < 4; i++)
	{
		if (binary[i] == '0')
		{
			validMoves.push_back({ dx[i], dy[i] });
		}
	}
	return validMoves;
}
void BFS(int x, int y, bool first)
{
	queue<pii> q;
	q.push({ x,y });
	visited[x][y] = true;
	int n = M.size();
	int count = 0;
	//cout << "BFS" << "\n";
	pii currentL;
	pii currentR;
	while (!q.empty())
	{

		pii current = q.front();
		q.pop();
		int i = current.first;
		int j = current.second;
		int Mi = M[i][j];
		if (!first) {
			if (Mi == 9 || Mi == 13 || Mi == 11 || Mi == 15) currentL = { i,j };
			if (Mi == 6 || Mi == 7 || Mi == 14 || Mi == 15) currentR = { i,j };
		}

		auto validMoves = ValidMovesFromBinary(Mi);
		count++;
		for (const pii& move : validMoves)
		{
			int newX = i + move.second;
			int newY = j + move.first;
			if (isValid(newX, newY, n) && !visited[newX][newY])
			{
				q.push({ newX, newY });
				visited[newX][newY] = true;
			}
		}
	}
	if (!first) {
		if (count > maxAns) {
			leftTop = currentL;
			rightBottom = currentR;
			maxAns = max(maxAns, count);
		}
	}

}
int main()
{
	//auto f = ValidMovesFromBinary(4);

	int q, n, a;
	cin >> q >> n;
	M.assign(n, vector<int>(n, 0));
	visited.assign(n, vector<bool>(n, false));
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> M[i][j];
		}
	}
	bool first = true;
	int total = -1;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (!visited[i][j]) {
				BFS(i, j, first);
				total++;
			}
			first = false;
		}
	}
	if (q == 1)  cout << total << "\n";
	else if (q == 2) cout << maxAns << "\n";
	else cout << leftTop.first + 1 << " " << leftTop.second + 1 << " " << rightBottom.first + 1 << " " << rightBottom.second + 1 << "\n";
}