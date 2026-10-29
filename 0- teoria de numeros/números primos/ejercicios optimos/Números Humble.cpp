/*
linkyless
--Copyright DMOJ
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long primos[105], nums[100005], princip[1005];
    int n, k, m;

    cin >> n >> k;
    for ( int i = 0; i < n; i++ ){

        cin >> primos[i];
        princip[i] = 0;
    }

    nums[0] = 1;
    m = 0;

    sort ( primos, primos + n); //orden

    while  (m < k ){

        long long menor = 100000000000000000LL; //min

        for ( int i = 0; i < n; i++ ){

            while  (primos[i] * nums[princip[i]] <= nums[m])
                princip[i]++;

            menor = min (menor, primos[i] * nums[princip[i]]);
        }

        nums[++m] = menor;
    }

    cout << nums[k] << "\n";

    return 0;
}