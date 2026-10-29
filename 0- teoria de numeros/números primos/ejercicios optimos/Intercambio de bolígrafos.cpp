#include<bits/stdc++.h>
    using namespace std;

    int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen("a.txt","w",stdout);

    int T;

    cin>>T;

    for(int i = 1; i <= T; i++){
        int K , A , B;
        cin >> K >> A >> B;
        if( B > A ){
            B = B + A;
            A = B - A;
            B = B - A;
        }
        if( A - K < B ){
            cout << 1 << '\n';
        }
        else
            cout << A - B - K << '\n';
    }

    return 0;
    }