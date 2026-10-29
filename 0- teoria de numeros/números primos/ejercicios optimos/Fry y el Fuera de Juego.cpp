#include <stdio.h>
int main(){
	int jug,a,cont=0,d;
	scanf("%d",&jug);
	for (int i=1; i<=11;i++){
		scanf("%d",&a);
		if (i==jug) d=a;
    }
	for (int i=1; i<=11;i++){
		scanf("%d",&a);	
		if (a<d) cont++;
	}
	printf(((cont<2) ?"OFFSIDE" :"GOAL"));
	return 0;
}