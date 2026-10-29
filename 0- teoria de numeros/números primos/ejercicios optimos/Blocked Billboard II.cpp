#include <stdio.h>

int max(int a, int b){
	return a > b ? a : b;
}
int min(int a, int b){
	return a < b ? a : b;
}

int main(){
    int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    if(y4 >= y2 && y1 >= y3){ // toda la altura
        if(x2 > x3 && x2 < x4)
			x2 = x3;
        if(x1 < x4 && x1 > x3)
			x1 = x4;
    }

    if(x4 >= x2 && x1 >= x3){ // todo el ancho
        if(y2 > y3 && y2 < y4)
			y2 = y3;
        if(y1 < y4 && y1 > y3)
			y1 = y4;
    }

    int area = (x2 - x1) * (y2 - y1);
    printf("%d\n", area);

    return 0;
}