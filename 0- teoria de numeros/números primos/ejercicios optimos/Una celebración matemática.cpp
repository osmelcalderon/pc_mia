#include <stdio.h>
const int MAX=100000;
int primo[MAX+1];
void criba(){
	for (int i=0;i<=MAX;i++)
		primo[i]=1;
	primo[0]=primo[1]=0;
	for (int i=2;i<=MAX;i++){
		if (primo[i])
			for (int j=i+i;j<=MAX;j=j+i)
				primo[j]=0; }
	
} 
int main(){
	criba();
	int m,n,c,sum=0,temp,r;
	scanf("%d%d",&m,&n);
	if (m>n) {
		temp=m;
		m=n;
		n=temp;
	}
	for (int i=m; i<=n;i++)
		if (primo[i]){
			r=i;c=0;
			while (r!=0){
				c=c*10+r%10;
				r/=10;
			}
			if (primo[c]) sum++;		
		}
	printf("%d",sum);
	return 0;
}