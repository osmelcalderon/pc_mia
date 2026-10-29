#include<stdio.h>

int main(){
    int n,x,p=0,i=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(x%2) i++;
        else p++;
    }
    while(p<i) p++,i-=2;
	printf("%d",(p>i)?2*i+1:p+i);
}