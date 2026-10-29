#include <stdio.h>
#include <stdlib.h>

int t;
int passages[5000+1][2];
int path[500];

void tsearch (int passagenum, int depth) {
    int i;
    path[depth-1] = passagenum;
    if (passagenum == t) {
        printf ("%d\n", depth);
        for (i = 0; i < depth; i++)
            printf ("%d\n", path[i]);
        exit (0);
    }
    if (passages[passagenum][0] != 0) {
       tsearch (passages[passagenum][0], depth+1);
       tsearch (passages[passagenum][1], depth+1);
    }
}

int main() {
    
    int n, ns, i, j;
    scanf ("%d %d %d", &n, &ns, &t);
    for (i = 0; i < ns; i++) {
        scanf ("%d", &j);
        scanf ("%d %d", &passages[j][0], &passages[j][1]);
    }
    tsearch (1, 1);      /* passagenum, depth */
    //printf ("NO ANSWER?\n");
    exit (0);
}