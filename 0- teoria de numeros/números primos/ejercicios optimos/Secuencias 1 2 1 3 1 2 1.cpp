#include <stdio.h>
#include <stdint.h>

#define BUFSZ 204800
char buf[BUFSZ];
size_t sz=0;

void putn(int32_t n) {
    if(n>=10){
        buf[sz++]=(n/10)+'0';
    }
    buf[sz++]=n%10+'0';
    buf[sz++] = ' ';
}

void s(int32_t n){
    if(n==1){
        putn(1);
    }else{
        s(n-1);
        putn(n);
        s(n-1);
    }
}

int main() {
    int32_t n;

    scanf("%d", &n);

    s(n);

    fwrite(buf, sizeof(char), sz, stdout);
}