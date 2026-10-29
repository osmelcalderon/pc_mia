#include<stdio.h>
#include<algorithm>

int main(){
    int i,cp,l,c,a;
    char s[100000];
    scanf("%d",&cp);
    while(cp--){
    	scanf("%d%s",&l,s);
    	if(!(std::count(s,s+l,'A')%2)){
			puts("-1");
			continue;
		}
		c=0;
    	for(i=0;i<l;i++){
	    	if(s[i]=='B'){
				a=i;
				while(s[a+1]=='B') a++;
		    	c^=(a+1-i);
		    	i=a;
			}
		}
    	puts(c?"F":"R");
	}
}