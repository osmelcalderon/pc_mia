#include <stdio.h>
int main(){
	int n,k,p=-10000000,c,m=1000000000,t;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++){
		scanf("%d",&c);
		if (c==k) {
			t=i-p-1;
			p=i;
		    if (t<m) m=t;
			if (m==0) { printf("0"); return 0; }
		} 
	}
	if (m>100001) printf("-1"); else printf("%d",m);	 
	return 0;
}