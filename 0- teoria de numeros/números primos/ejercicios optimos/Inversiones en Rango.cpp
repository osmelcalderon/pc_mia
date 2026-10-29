#include <bits/stdc++.h>

using namespace std;

int arr[6001], tabl[6001][6001];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        for(int j = 1; j < i; ++j){
            tabl[i][j] = tabl[i][j-1] + tabl[i-1][j] - tabl[i-1][j-1] + (arr[j]>arr[i]);
        }
    }



    int q;
    cin >> q;

    for (int i = 1; i <= q; ++i) {

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << tabl[d][b] - tabl[d][a-1] - tabl[c-1][b] + tabl[c-1][a-1] << "\n";
    }

    return 0;

}