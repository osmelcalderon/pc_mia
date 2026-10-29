#include<bits/stdc++.h>
//Problem dmoj.uclv.edu.cu/problem/onlinegcd
//User Hd(Derek Naharai Herrera Domínguez)  
using namespace std;
#define Hd main(void)

long long read_long_long() {
    long long num = 0;
    int c = getchar_unlocked();
    int sign = 1;

    while (c < '0' || c > '9') {
        if (c == '-') {
            sign = -1;
        }
        c = getchar_unlocked();
    }

    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar_unlocked();
    }

    return num * sign;
}
Hd
{
    long long a=read_long_long(),b=read_long_long();
    long long ar[100001];
    ar[0]=read_long_long();
    long long gc=ar[0];
    for(long long i=1; i<a; i++) {
        ar[i]=read_long_long();
        gc=__gcd(gc,ar[i]);
    }
    while(b--) {
        long long an=read_long_long(),div=read_long_long();
        ar[an-1]/=div;
        long long aux=ar[an-1];
        gc=__gcd(gc,aux);
        printf("%lld\n",gc);
    }
}