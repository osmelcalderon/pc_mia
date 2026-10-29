#include<bits/stdc++.h>
#define int long long
#define vma 1e9
#define vmi -1e9
#define F first
#define S second
#define pb push_back
#define ull unsigned long long

using namespace std;

const int MAX = 2e3 + 3;
const int mand = 5e5 + 5;
const int mod = 1e8;
const int base = 23;

int A[MAX][MAX] , p[MAX] , n , t , k , a , b , cont , di , tr , sum , tp;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>t>>k;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=t ; j++){
            cin>>a;
            if(!a)p[j]++;
            else{
                cont++;
                A[i][cont] = j;
            }
        }
        cont = 0;
    }
    cont = 1;
    for(int i=1 ; i<=t ; i++){
        if(A[k][i] != 0){
           di += p[A[k][i]];
        }
        else{
           tr = i-1;
           break;
        }
    }
    for(int i=1 ; i<=n ; i++){
        if(i == k)continue;
        for(int j=1 ; j<=t ; j++){
            if(A[i][j] != 0){
                sum += p[A[i][j]];
            }
            else{
                tp = j-1;
                break;
            }
        }
        if(sum > di)cont++;
        if(sum == di){
            if(tp > tr)cont++;
            if(tp == tr){
                if(i < k)cont++;
            }
        }
        sum = 0;
    }
    cout<<di<<" "<<cont;



    return 0;
}
/**

6 7
1
5
3
3
5
1


**/