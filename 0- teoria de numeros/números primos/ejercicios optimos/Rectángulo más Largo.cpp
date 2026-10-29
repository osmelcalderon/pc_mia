/*
linkyless
--Copyright DMOJ
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, arr[100005];
ll s[100005], p = 1;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (ll i = 1; i <= n; i++ ) 
        cin >> arr[i];

    ll final = 0;

    for ( ll i = 0; i < n + 2; i++ ) {
        while ( arr[i] < arr[s[p - 1]] ) {
            ll y = arr[s[p - 1]];
            p--; //p--
            final = max(final, (i - s[p - 1] - 1) * y);
        }

        s[p++] = i;
    }

    cout << final;

    return 0;
}