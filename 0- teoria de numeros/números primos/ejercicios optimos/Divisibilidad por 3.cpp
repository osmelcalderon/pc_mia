#include <stdio.h>

int main(void)
{
    int d1, d2, d3, di1, di2, i=0, c=3, c1;
    scanf("%d %d %d", &d1, &d2, &d3);
    do{
        di1=c%10; c1=c/10;
        di2=c1%10;
        if(c==d1 || c==d2 || c==d3){
            i=1;
        }
        else{
            if(di1==d1 || di1==d2 || di1==d3){
                if(di2==d1 || di2==d2 || di2==d3){
                    i=1;
                }
                else
                    c+=3;
            }
            else
                c+=3;
        }
    }while(i==0);
    printf("%d\n", c);
    return 0;
}