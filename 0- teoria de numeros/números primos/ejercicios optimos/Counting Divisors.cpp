#define MAIN_C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
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
#define MAX 1000001

#define OBUFSZ 10485760
char obuf[OBUFSZ];
size_t osz=0;

void putn(int32_t n){
    size_t i, dgs=0;
    char repr[10];

    if(n==0){
        obuf[osz++]='0';
        return;
    }

    while(n>0){
        repr[dgs++]=n%10;
        n/=10;
    }
    char *head = obuf+osz;
    for(i=0; i<dgs; i++){
        head[i]=repr[dgs-i-1]+'0';
    }
    osz+=dgs;
    obuf[osz++]='\n';
}

int main() {
    size_t n, i, j, pz=0;
    int32_t *D, *P, pri, *M;
    bool *notprime;

    notprime = calloc(MAX, sizeof(bool));
    D = calloc(MAX, sizeof(int32_t));
    P = malloc(sizeof(int32_t)*MAX);
    M = calloc(MAX, sizeof(int32_t));
    D[1] = 1;
    M[1] = 1;
    for(i=2; i<MAX; i++){
        if(!notprime[i]){
            P[pz++]=i;
            D[i]=2;
            M[i]=1;
        }
        for(j=0; j<pz; j++){
            pri = P[j];

            if(i*pri>=MAX){
                break;
            }else if(i%pri!=0){
                notprime[i*pri]=1;
                M[i*pri] = i;
                D[i*pri] = D[i]*2;
            }else{
                notprime[i*pri]=1;
                M[i*pri] = M[i];
                D[i*pri] = D[M[i]] + D[i];
                break;
            }
        }
    }

    n = next_int();
    while(n--){
        i = next_int();
        //printf("%d\n", D[i]);
        putn(D[i]);
    }
    fwrite(obuf, sizeof(char), osz, stdout);

    return EXIT_SUCCESS;
}