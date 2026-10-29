#include<stdio.h>

int main(){
	int i=0,j=0,m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	char g[m][10];
	for(;i<m;i++) scanf("%s",g[i]);
	for(;j<m*k;j++){
		for(i=0;i<n*k;i++) printf("%c",g[j/k][i/k]);
		puts("");
	}
}