// CSES - Trailing Zeros
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    long long zeros = 0;
    for (long long five = 5; five <= n; five *= 5) {
        zeros += n / five;
    }
    
    cout << zeros;
    
    return 0;
}