#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, mi = 1e9, mit = -1, mat = -1, ma = -1, cont = 1, ll = 1e9;
    cin >> n;
    vector<long long> k (n);
    for(int i = 0; i < n; i++){
        cin >> k[i];
        if(k[i] < mi){
            mi = k[i];
        }
         if(k[i] > ma){
            ma = k[i];
        }
    }
    
       for(int i = 0; i < n; i++){
        if(k[i] == mi){
            mit = i;
            if(mat != -1){
                ll = min(ll, i - mat + 1);
            }
        }
        if(k[i] == ma){
            mat = i;
            if(mit != -1){
                ll = min(ll, i - mit + 1);
            }
        }
    }
    cout << ll << '\n';
    return 0;
}