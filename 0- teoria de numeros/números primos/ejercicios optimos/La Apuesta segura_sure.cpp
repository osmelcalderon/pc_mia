#include<bits/stdc++.h>
#define mod 1e9+7
#define maxn 100001

using namespace std;

int N;
double A[maxn];
double B[maxn];
double suma, sumb, ret;

bool cmp(double a, double b) {
    return a > b;
}

int main (void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(4);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i] >> B[i];
        A[i] --, B[i] --;
    }

    sort(A, A+N, cmp);
    sort(B, B+N, cmp);

    int i=0, j=0;
    for (; i<N;) {
        suma += A[i];
        i++;
        for (; j<N && min(suma - j, sumb - i) < min(suma - (j+1), sumb+B[j] - i);) {
            sumb += B[j];
            j++;
        }
        ret = max(ret, min(suma - j, sumb - i));
    }

    cout << ret;

    return 0;
}
