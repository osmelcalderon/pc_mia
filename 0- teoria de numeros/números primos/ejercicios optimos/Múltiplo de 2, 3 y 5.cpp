#include <stdio.h>
int main(){
	int n,q[10]={0},sum=0,v;
	short j=1,band=1,cont=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&v);
		sum+=v;
		q[v]++; }
	if (q[0]==0){
		printf("-1");
		return 0; 	}
	sum%=3;
	if (sum!=0){
		band=0;
		for(int i=1;i<=8;i++)
			if (i%3==sum && q[i]!=0){
				q[i]--;
				band=1;
				break; 	}
		if (band==0){ 
		  	if (sum==1) sum=2; else sum=1;
		  	do{
		  		if (j%3==sum && q[j]!=0){
					q[j]--;
					cont++; }
				else j++;
			}
			while (cont<2 && j<9);
		  	if (cont==2) band=1;
		}
	}
	if (band==0){
		printf("-1");
		return 0;
	}
	cont=0;
	for(int i=9;i>=0;i--){
		if (i>0) cont+=q[i];
		if (i==0 && cont==0) {
			printf("0");
		    return 0;
		}
		for(int j=1;j<=q[i];j++)
			printf("%d",i);
		}		
	return 0;
}