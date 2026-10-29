#include<stdio.h>
#include<cstdint>
#define int long long
int32_t main()
{int T;
scanf("%lld",&T);
while(T--){
	int c,o;
	scanf("%lld%lld",&c,&o);
	o--;
	if(o>c||(c-o)%2==1||o==-1||((o==0)&&(c!=0))){
	    printf("NO\n");
	    continue;
	    }
	    
printf("YES\n");
	   
	
	   
	    
	    
}
return 0;	
}