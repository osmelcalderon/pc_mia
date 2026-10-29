#define MAIN_C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
// include io.c
#ifndef MAIN_C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#endif

#define BUFSZ 1024000
char buf[BUFSZ];
size_t bufptr=0, buflen=0;

char next_char() {
    if(bufptr>=buflen){
        bufptr = 0;
        buflen = read(STDIN_FILENO, buf, BUFSZ);
        if(buflen<0)exit(EXIT_FAILURE);
        if(buflen==0)return 0;
        return next_char();
    }
    return buf[bufptr++];
}

int64_t next_int() {
    char lst = next_char();
    while(lst < '0' || lst > '9')
        lst = next_char();
    int64_t res = 0;
    while(1) {
        if(lst<'0' || lst>'9')break;
        res = res*10 + lst - '0';
        lst = next_char();
    }
    return res;
}



// end-include io.c
#define MAX 1000003
#ifdef ONLINE_JUDGE
#define dbg if(0)
#else
#define dbg if(1)
#endif


struct reps {
    int32_t num;
    int32_t reps;
};


struct tree {
    struct reps *data;
};


void apply_min(struct reps *out, struct reps *a, struct reps *b) {
    if(a->reps < b->reps){
        out->reps = a->reps;
        out->num = a->num;
    }else if(a->reps > b->reps){
        out->reps = b->reps;
        out->num = b->num;
    }else if(a->num < b->num){
        out->reps = a->reps;
        out->num = a->num;
    }else{
        out->reps = b->reps;
        out->num = b->num;
    }
}


void tree_init(struct tree *tree) {
    size_t i;
    struct reps *data;

    data = calloc(sizeof(struct reps), 2*MAX);
    for(i=0; i<MAX; i++){
        data[i+MAX].num = i;
    }

    for(i=2*MAX-1; i>0; i--){
        if(!(i&1)) {
            apply_min(data+(i/2), data+i, data+i+1);
        }
    }

    tree->data = data;
}

void tree_add(struct tree *tree, size_t idx, int32_t cnt) {
    idx += MAX;
    tree->data[idx].reps += cnt;

    while(idx>1){
        if(idx&1){
            apply_min(tree->data+(idx>>1), tree->data+idx-1, tree->data+idx);
        }else{
            apply_min(tree->data+(idx>>1), tree->data+idx, tree->data+idx+1);
        }
        idx>>=1;
    }
}

int32_t tree_min(struct tree *tree) {
    return tree->data[1].num;
}

int main() {
    size_t n, k, i;
    int32_t *A;
    struct tree tree;

    n = next_int();
    k = next_int();
    A = malloc(sizeof(int32_t)*n);

    for(i=0; i<n; i++){
        A[i] = next_int();
        // Map A[i]>MAX -> MAX-1
        if(A[i]>=MAX){
            A[i] = MAX-1;
        }
    }


    // The tree
    tree_init(&tree);

    // Initial window
    for(i=0; i<k-1; i++){
        dbg printf("Added %d\n", A[i]);
        tree_add(&tree, A[i], 1);
    }

    for(i=k-1; i<n; i++){
        dbg printf("Added %d\n", A[i]);
        tree_add(&tree, A[i], 1);
        printf("%d ", tree_min(&tree));
        dbg printf("Popped %d\n", A[i-k+1]);
        tree_add(&tree, A[i-k+1], -1);
    }

    return EXIT_SUCCESS;
}