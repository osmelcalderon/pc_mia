#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mdl (l+r)/2
#define ft first
#define sd second
#define lft 2*p
#define rgt 2*p+1
#define pb push_back
#define all(x) (x).begin(), (x).end()
const int MAX=1e2;
const int oo=1e6;
int movx[4]={1, -1, 0, 0};
int movy[4]={0, 0, 1, -1};

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int mt[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mt[i][j];
        }
    }

	int r=0, c=0;
	for(int i=0; i<n; i++){
		int sum[2]{};
		for(int j=0; j<n; j++) sum[j%2]+=mt[i][j];
		r+=max(sum[0], sum[1]);
	}

	for(int i=0; i<n; i++){
		int sum[2]{};
		for(int j=0; j<n; j++) sum[j%2]+=mt[j][i];
		c+=max(sum[0], sum[1]);
	}

	cout << max(r, c) << "\n";

    return 0;
}