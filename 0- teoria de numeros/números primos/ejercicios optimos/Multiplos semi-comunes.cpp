#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define repa(i,a,b) for (int i = (a); i >= (b); i--)
#define debug(a) cout << #a << " = " << a << endl
#define debugsl(a) cout << #a << " = " << a << ", "

#define MAX 31622

lli n,m,a,res,b,c,mult,signi;
lli criba[MAX+2];
vector<lli> primos;
vector<lli> mcm(MAX + 1, 0);
map<lli, lli> grandes, procesado;

void factoriza(lli num) {

    if (procesado.count(num)) return;
    else procesado[num] = 1;

    if (mult > m) return;

    lli cant, dif;
    for (auto p : primos) {

        if (num == 1) break;
        if (num%p != 0) continue;

        cant = 0;
        while (num%p == 0) {
            num /= p;
            cant++;
        }

        dif = cant - mcm[p];
        if (dif > 0) {
            rep(i, 1, dif) mult *= p;
            mcm[p] += dif;
            if (mult > m) return;
        }
    }

    if (num > 1) {
        //if (mcm[num] == 0) primos.push_back(num);
        dif = 1 - grandes[num];
        if (dif){
            mult *= num;
            grandes[num] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    rep(i,2,180) {
        if (criba[i] == 0) {
            primos.push_back(i);
            for (lli j = i*i; j <= MAX; j+=i) criba[j] = 1;
        }
    }
    rep(i,181,MAX) if (criba[i] == 0) primos.push_back(i);

    mult = 1;
    rep(i,1,n) {
        cin >> a;
        if (i == 1) signi = a&(-a);
        else {
            b = a&(-a);
            if (b != signi) {
                cout << 0;
                return 0;
            }
        }

        a /= 2;
        factoriza(a);
    }

    if (mult > m) cout << 0;
    else {

        a = m/mult;
        res = a >> 1;
        if (a & 1) res++;
        cout << res;
    }
}