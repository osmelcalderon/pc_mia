//Leandro Eliecer Vazquez Rivero    IPU: Ramon Infante Garcia    G: 12mo
//Teléfonos móviles
#pragma GCC optimize("Ofast")
#include<iostream>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(0); //srand(time(NULL));
#define all(x) (x).begin(), (x).end()
#define db(it,ar) for(auto &it: ar)
#define sz(x) (int)(x).size()
#define pb push_back
#define int long long
#define fs first
#define sd second
#define rsz resize
#define en '\n'

const int maxn = 1051;
int t[maxn][maxn], n;

void update(int x1, int x2, int v)
{
    for(int i = x1; i <= n; i += i&-i)
    {
        for(int j = x2; j <= n; j += j&-j)
        {
            t[i][j] += v;
        }
    }
}

int query(int x1, int x2)
{
    int ans = 0;
    for(int i = x1; i; i -= i&-i)
    {
        for(int j = x2; j; j -= j&-j)
        {
            ans += t[i][j];
        }
    }
return ans;
}

int query(int x1, int x2, int y1, int y2)
{
    return query(y1, y2) - query(x1-1, y2) - query(y1, x2-1) + query(x1-1, x2-1);
}

int32_t main(){
    fast
    int o, l, r, l1, r1, v;
    cin >> n >> n;

    while(cin >> o and o != 3)
    {
        if(o == 1)
        {
            cin >> l >> r >> v;
            l++; r++;
            update(l, r, v);
        }
        else
        {
            cin >> l >> r >> l1 >> r1;
            l++; r++; l1++; r1++;
            cout << query(l, r, l1, r1) << en;
        }
    }
return 0;
}