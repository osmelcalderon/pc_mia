#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

struct nodo{
    int max;
    int min;
};

int datos[200005];
nodo seg[900000];

void built(int n, int inf, int sup){
    if(inf == sup){
        seg[n].min = datos[inf];
        seg[n].max = datos[inf];
    }else{
        int mid = (sup+inf)/2;
        built(2*n, inf, mid);
        built(2*n+1, mid+1, sup);
        seg[n].max = max(seg[2*n].max, seg[2*n+1].max);
        seg[n].min = min(seg[2*n].min, seg[2*n+1].min);
    }
}

int query(int n, int inf, int sup, int i, int j, bool op){
    if(i>sup || j<inf){
        return op==0 ? 2000000 : 0;
    }else if(i<=inf && j>=sup){
        return op==0 ? seg[n].min : seg[n].max;
    }else{
        int mid = (sup+inf)/2;
        int izq = query(n*2, inf, mid, i, j, op);
        int der = query(n*2+1, mid+1, sup, i, j, op);
        return op==0 ? min(izq, der) : max(izq, der);
    }
}

int main()
{
    int q;
    int n;
    scanf("%d%d", &n, &q);
    for(int i = 1; i<=n; i++){
        scanf("%d", &datos[i]);
    }

    int i;
    int j;
    built(1, 1, n);

    while(q--){
        scanf("%d%d", &i, &j);
        int a = query(1, 1, n, i, j, 0);
        int b = query(1, 1, n, i, j, 1);
        printf("%d\n", b-a);
    }

    return 0;
}