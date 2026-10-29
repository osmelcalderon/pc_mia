#include<stdio.h>
int main(){
    long long a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(a==b&&c==d||a==d&&c==b){
        printf("YES\n%lld",a*c);
    }
    else if(a==c&&d==b||a==c&&b==d){
        printf("YES\n%lld",a*b);
    }
    else{
        printf("NO\n%lld",a+b+c+d);
    }
    return 0;
}