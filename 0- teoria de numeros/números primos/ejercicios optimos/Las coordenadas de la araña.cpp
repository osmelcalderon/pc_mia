#include<stdio.h>
#define Hd main()
Hd{
        long long n,d,c,k=0;
        scanf("%lld%lld%lld",&n,&d,&c);
        while(c--){
            int x,y;
            scanf("%d%d",&x,&y);
            if((x+y-d>=0) && (x-y-d)<=0 && (x+y-2*n+d)<=0 && (x-y+d)>=0){
                k++;
            }
        }
        printf("%lld\n",k);
}