#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, x, y, m = 1e18;
	cin >> n;
	pair<long long, int> a[n], b[n];
	
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		a[i].first = x;
		a[i].second = i;
		b[i].first = y;
		b[i].second = i;
	}
	sort(a, a+n);
	sort(b, b+n);
	
	x = a[n-1].first-a[1].first;
	if(b[0].second == a[0].second) y = b[n-1].first-b[1].first;
	else if(b[n-1].second == a[0].second) y = b[n-2].first-b[0].first;
	else y = b[n-1].first-b[0].first;
	m = min(m, x*y);
	
	x = a[n-2].first-a[0].first;
	if(b[0].second == a[n-1].second) y = b[n-1].first-b[1].first;
	else if(b[n-1].second == a[n-1].second) y = b[n-2].first-b[0].first;
	else y = b[n-1].first-b[0].first;
	m = min(m, x*y);
	
	x = b[n-1].first-b[1].first;
	if(a[0].second == b[0].second) y = a[n-1].first-a[1].first;
	else if(a[n-1].second == b[0].second) y = a[n-2].first-a[0].first;
	else y = a[n-1].first-a[0].first;
	m = min(m, x*y);
	
	x = b[n-2].first-b[0].first;
	if(a[0].second == b[n-1].second) y = a[n-1].first-a[1].first;
	else if(a[n-1].second == b[n-1].second) y = a[n-2].first-a[0].first;
	else y = a[n-1].first-a[0].first;
	m = min(m, x*y);
	
	cout << m;
	
	return 0;
}