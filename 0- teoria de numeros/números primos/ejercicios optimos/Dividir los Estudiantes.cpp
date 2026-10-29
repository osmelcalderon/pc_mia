#include <stdio.h>
int main() {
    int t, a, b, c, ga, gb, gc;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &a, &b, &c);
        ga = (a > c ? a : c) / 2;
        gb = (a > c ? a : c) - ga;
        gc = (a > c ? c : a);
        while(b--){
            if(ga <= gb && ga <= gc)
               ga++;
            else if(gb <= gc && gb <= ga)
                gb++;
            else if(gc <= gb && gc <= ga)
                gc++;
        }
        c = ga > gb ? ga : gb;
        c =  c > gc ?  c : gc;
        printf("%d\n",c);
    }
    return 0;
}