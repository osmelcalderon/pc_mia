#include<stdio.h>
#include<unistd.h>

// Some default values
#define SYS_READ 0
#define SYS_WRITE 1
#define SYS_EXIT 60
#define STDIN 0
#define STDOUT 1
#define STDERR 2

/**
 * Make a system call
 */
static inline void syscall1(long long code, long long arg1){
    __asm__(
        "movq %0, %%rax;" //  P0 -> Rax (Syscall)
        "movq %1, %%rdi;" //  P1 -> Rdi (Param1)
        "syscall"         // Exec
        :
        : "r"(code), "r"(arg1)
        : "%rax", "%rdi"
    );
}

/**
 * Make a system call
 */
static inline void syscall2(long long code, long long arg1, long long arg2){
    __asm__(
        "movq %0, %%rax;" //  P0 -> Rax (Syscall)
        "movq %1, %%rdi;" //  P1 -> Rdi (Param1)
        "movq %2, %%rsi;" //  P1 -> Rdi (Param2)
        "syscall"         // Exec
        :
        : "r"(code), "r"(arg1), "r"(arg2)
        : "%rax", "%rdi", "%rsi"
    );
}

/**
 * Make a system call
 */
static inline void syscall3(long long code, long long arg1, long long arg2, long long arg3){
    __asm__(
        "movq %0, %%rax;" //  P0 -> Rax (Syscall)
        "movq %1, %%rdi;" //  P1 -> Rdi (Param1)
        "movq %2, %%rsi;" //  P2 -> Rdi (Param2)
        "movq %3, %%rdx;"  //  P3 -> Rdx (Param3)
        "syscall"         // Exec
        :
        : "r"(code), "r"(arg1), "r"(arg2), "r"(arg3)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
}

#define BUFSIZE 1024000
//                ^ 1000kb
char buf[BUFSIZE];
long buflen=0, bufptr=0;

char mygetchar(){
    // may hang indefinitely :/
    while(1){
        if(bufptr<buflen){
            return buf[bufptr++];
        }
        bufptr=0;
        buflen = read(0, buf, BUFSIZ);
    }
}

/**
 * Next int in stdin
 */
void next(long long *n){
    *n = 0;
    char c;
    
    //syscall3(SYS_READ, STDIN, (long long)&c, 1);
    //read(0, &c, 1);
    c = mygetchar();
    while(1){
        if(c==0){
            return;
        }else if('0' <= c && c<= '9'){
            *n = c-'0';
            break;
        }
        //syscall3(SYS_READ, STDIN, (long long)&c, 1);
        //read(0, &c, 1);
        c = mygetchar();
    }

    while(1){
        //syscall3(SYS_READ, STDIN, (long long)&c, 1);
        //read(0, &c, 1);
        c = mygetchar();
        //
        if(c<'0' || c>'9')break;
        *n = (*n)*10 + c - '0';
    }
}

/**
 * Print to stdout a number
 */
void print(long long n){
    char digits[20];
    char digSize=0;
    if(n==0){
        digits[0] = '0';
        //syscall3(SYS_WRITE, STDOUT, (long long)&digits[0], 1);
        write(1, digits, 1);
        return;
    }
    while(n){
        digits[digSize++]=n%10 + '0';
        n/=10;
    }
    //Now reverse
    long itr = (digSize-1)>>1;
    char tmp;
    do{
        tmp = digits[itr];
        digits[itr] = digits[digSize-itr-1];
        digits[digSize-itr-1] = tmp;
    }while(itr--);
    //Now print
    //syscall3(SYS_WRITE, STDOUT, (long long)&digits, digSize);
    write(1, digits, digSize);
}

/**
 * Print a new line
 */
//void write(char c){
//    syscall3(SYS_WRITE, STDOUT, (long long)&c, 1);
//}

/**
 * Start function, called at start
 */
//void _start(){
int main(){
    //
    // @karellgz
    // 
    long long n, a=0, b=0, t;
    next(&n);

    long long itr = ((n+2)*(n+1)>>1)-1;
    while(itr--){
        next(&t);
        a+=t;
        next(&t);
        b+=t;
    }
    
    n = n*(n+1)*(n+2)/3;
    print((n>>1)-a);
    write(1, " ", 1);
    print(n-b);
    write(1, "\n", 1);
    //syscall1(SYS_EXIT, 0); //Exit
    // :/
}