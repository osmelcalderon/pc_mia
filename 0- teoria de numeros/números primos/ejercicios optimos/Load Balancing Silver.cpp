#include<bits/stdc++.h>
using namespace std;
#define int long long
#define md (l+r)/2
#define lf 2*p
#define rg 2*p+1
#define pb push_back
#define all(x) (x).begin(), (x).end()
const int MAX=1e6+1;
const int oo=1e18;
const int mod=1e9+7;
int movx[4]={1, -1, 0, 0};
int movy[4]={0, 0, 1, -1};

struct cow{
	int x, y;
};

int mini(int x_line, const vector<cow>&cows){
	vector<cow>left;
	vector<cow>right;
	for(const cow &c: cows){
		if(c.x<x_line) left.push_back(c);
		else if(c.x>x_line) right.push_back(c);
	}

	int bal=MAX, lft=0, rgt=0;
	while(lft+rgt<cows.size()){
		int yl=cows[lft+rgt].y+1;
		while(lft<left.size() and yl>left[lft].y) lft++;
		while(rgt<right.size() and yl>right[rgt].y) rgt++;
		int bmax=max(lft, rgt), amax=max(left.size()-lft, right.size()-rgt);
		bal=min(bal, max(bmax, amax));
	}

	return bal;
}

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;
	vector<cow> bx(n);
	for(cow &c: bx) cin >> c.x >> c.y;
	sort(all(bx), [&](const cow &p1, const cow &p2) {return p1.x<p2.x;});
	vector<cow>by(bx);
    sort(all(by), [&](const cow &p1, const cow &p2) {return p1.y<p2.y;});

	int bal=MAX, xl=0;
	while(xl<bx.size()){
		int xli=bx[xl].x+1;
		bal=min(bal, mini(xli, by));
		while (xl<n and xli>bx[xl].x) xl++;
	}

	cout << bal << "\n";

    return 0;
}