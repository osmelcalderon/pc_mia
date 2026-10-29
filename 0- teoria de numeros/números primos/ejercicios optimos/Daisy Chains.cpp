#include<stdio.h>

int main(){
	int i=0,j=0,m,n,s,c=0;
	scanf("%d",&n);
	int arr[n];
	for(;i<n;i++) scanf("%d",&arr[i]);
	for(;j<n;j++){
		for(i=j;i<n;i++){
			s=0;
			for(m=j;m<=i;m++) s+=arr[m];
			for(m=j;m<=i;m++){
				if(arr[m]*(i-j+1)==s){
					c++;
					break;
				}
			}
		}
	}
	printf("%d",c);
}