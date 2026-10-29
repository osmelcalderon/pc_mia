#include<stdio.h>
#define Hd int main(void)

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

Hd {
    long long tc=read_long_long();
    long long a,b;
    while(tc--){
        a=read_long_long(),b=read_long_long();
        long long res = 1;
        while(b){
            if(b&1) res = (a*res)%1000000007;
            a = (a*a)%1000000007;
            b>>=1;
        }
        printf("%lld\n",res);
    }
}