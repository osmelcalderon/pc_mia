#include<stdio.h>

int main(){
	int x,y,d=1,t=1,c=0;
	scanf("%d%d",&x,&y);
	while(1){
		if((d==1 && x<=y && y<=x+t)||(d==-1 && y<=x && x<=y+t)){
			printf("%d",x>y?c+x-y:c+y-x);
			break;
		}
		else c+=2*t,t*=2,d*=-1;
	}
}