#include<stdio.h>

int main(){
	int i=0,j=0,n;
	scanf("%d",&n);
	int v[n],c[n];
	for(;i<n;i++) scanf("%d",&v[i]);
	for(;j<n;j++) scanf("%d",&c[j]);
	for(i=0;i<3;i++){
		int aux[n];
		for(j=0;j<n;j++) aux[j]=c[v[j]-1];
		for(j=0;j<n;j++) c[j]=aux[j];
	}
	for(i=0;i<n;i++) printf("%d\n",c[i]);
	return 0;
}