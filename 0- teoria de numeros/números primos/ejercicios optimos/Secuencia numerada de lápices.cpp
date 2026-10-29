#include <bits/stdc++.h>
using namespace std;

long long fib_m(int n, int m){
    if(n<=0)  return 0;
    long long i = n-1;
    long long a = 1;
    long long b = 0;
    long long c = 0;
    long long d = 1;
    long long tmp;
    while(i>0){
        if(i%2 == 1){
            tmp = a;
            a = (d*b + c*a) % m;
            b = (d*(b+tmp) + c*b) % m;
        }
        tmp = c;
        c = (tmp*tmp + d*d) % m;
        d = (d*(2*tmp + d)) % m;
        i = i/2;
    }
    return (a+b)% m;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        cout << fib_m(q+1, 100000007) << " ";
    }
    return 0;
}