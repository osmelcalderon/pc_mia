#include <stdio.h>
 
main() {
    //FILE *fin = fopen ("privc.in", "r");
    //FILE *fout = fopen ("privc.out", "w");
    int n, i, j, nexchanges, ok;
    int list[1000], count[3];
    count[0] = count[1] = count[2] = 0;
    scanf ("%d", &n);
    for (i = 0; i < n; i++) {
        scanf ("%d", &list[i]);
        count[--list[i]]++;
    }
    nexchanges = 0;
    /* fix all the 0's: */
    for (i = 0; i < count[0]; i++) {
        if (list[i] == 0) continue;
        if (list[i] == 2) {
            int ok = 0;
            for (j = count[0]+count[1]; j < n; j++) {
                if (list[j] != 0) continue;
                int t = list[i]; list[i] = list[j]; list[j] = t;
                nexchanges++;
                ok = 1;
                break;
            }
            if (ok == 1) continue;
        }
        /* either list[i] == 1 OR no acceptable '0' was found */  
        for (j = count[0]; ; j++) {
            if (list[j] != 0) continue;
            int t = list[i]; list[i] = list[j]; list[j] = t;
            nexchanges++;
            break;
        }
        continue;
    }
    /* fix all the 1's: */
    for (i = count[0]; i < count[0]+count[1]; i++) {
        if (list[i] == 1) continue;
        for (j = count[0]+count[1]; j < n; j++) {
            if (list[j] != 1) continue;
            int t = list[i]; list[i] = list[j]; list[j] = t;
            nexchanges++;
            break;
        }
    }
    printf ("%d\n", nexchanges);
    //exit (0);
}