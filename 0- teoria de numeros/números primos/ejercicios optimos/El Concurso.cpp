#include <stdio.h>

int main(){
	int n, dato, sum = 0, val = -1, valMin = 200000, x, y;
	bool band = 1;
	
	scanf("%d", &n);
	while(n--){
		scanf("%d", &dato);
		sum += dato;
	}
	
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &x, &y);
		if(sum >= x && sum <= y && band == true){ val = sum; band = 0; }
		if(x >= sum && x < valMin) valMin = x;
	}
	
	if(val == -1 && valMin == 200000) printf("-1");
	else if(val == -1 && valMin != 200000) printf("%d", valMin);
	else printf("%d", val);
	
	return 0;
}