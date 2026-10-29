#include <stdio.h>
#include <string.h>
int main(){
	char s1[102],s2[102];
	int c=0,a=0;
	int q[102], size1, size2,v1,v2;
	scanf("%s%s",s1,s2);
	size1=strlen(s1)-1; size2=strlen(s2)-1;	
	while (size1>=0 || size2>=0){
		if (size1>=0) { v1=s1[size1]-48; size1--; } else v1=0;
		if (size2>=0) { v2=s2[size2]-48; size2--; } else v2=0;
	    q[c]=(v1+v2+a)%10;
		a=(v1+v2+a)/10;
		c++;	
	}
	if (a!=0) printf("%d",a);
	for (int i=c-1;i>=0;i--) printf("%d",q[i]);
	return 0;
}