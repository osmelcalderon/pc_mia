#include<stdio.h>
#include<algorithm>

const int mxn = 100005;
int cow[mxn], loc[mxn], tree[mxn];

int main(){
	
	long long n,inv=0,best=1LL<<60;	
    scanf("%lld", &n);
    

    for(int i=0;i<n;i++){
        scanf ("%lld",cow+i);
        loc[cow[i]]=i;
    }
    for(int i=n-1;i>=0;i--){
        for(int x=cow[i];x>0;x-=x&-x){
        	inv += tree[x];
		}
        for(int x=cow[i];x<=n;x+=x&-x){
        	tree[x]++;
		}
    }
    for(int i=1;i<=n;i++){
        inv += n-1-2*loc[i];
        best = std::min(best,inv);
    }
    printf ("%lld\n", best);
    
    return 0;
}