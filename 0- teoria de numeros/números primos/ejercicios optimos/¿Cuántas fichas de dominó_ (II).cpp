// @_@    Smile :)

#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define pop pop_back

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int N;
    cin >> N;

    ll A[N];

    for(int i = 0;i < N;i++){
        cin >> A[i];
    }


    for(int i = 0;i < N;i++){
        ll  UwU = (A[i] * (A[i] + 1)) / 2;
        UwU += A[i] + 1;

        cout << UwU << '\n';
    }


    return 0;
}

/* (N * (N + 1)) / 2 */