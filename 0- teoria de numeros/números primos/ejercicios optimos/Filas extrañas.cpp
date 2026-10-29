#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, b, cont = 0;
	cin >> n;
	vector<pair<int, int>> a(1, {0,0});
	
	for(int i = 0; i < n; i++){
		cin >> b; cont++;
		if(b != a[a.size()-1].first) a.push_back(pair<int, int>(b, 1));
		else{
				a[a.size()-1].second++;
				if(a[a.size()-1].second >= a[a.size()-1].first){
					cont -= a[a.size()-1].second;
					a.pop_back();
				}
		}
		cout << cont << "\n";
	}
	
	return 0;
}