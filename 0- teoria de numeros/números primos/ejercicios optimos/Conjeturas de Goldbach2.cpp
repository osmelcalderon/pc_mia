#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#define MAX 1000001

struct primes {
    bool *not_prime;
    int32_t *primes;
    size_t primes_size;
    size_t size;
};

struct primes
gen_primes(void)
{
    bool *not_prime = malloc(sizeof(bool) * MAX);
    memset(not_prime, 0, MAX);
    int32_t *primes = malloc(sizeof(int32_t) * MAX);
    size_t primes_sz = 0;

    not_prime[0] = not_prime[1] = true;

    // Generate
    for(size_t i = 2; i < MAX; i++){
        if(!not_prime[i]) {
            primes[primes_sz++] = i;
        }

        for(size_t j = 0; j<primes_sz; j++) {
            size_t Pj = primes[j];
            if(i*Pj >= MAX)
                break;
            not_prime[i*Pj] = true;
        }
    }

    struct primes res = {
        .not_prime = not_prime,
        .size = MAX,
        .primes = primes,
        .primes_size = primes_sz,
    };
    return res;
}


struct buf_t {
    int8_t* buf;
    size_t siz, head;
};


/* The stdin data */
struct buf_t data;


/* Read the entire standard input */
struct buf_t
read_stdin()
{
    // 10 MiB
#define PREALLOC 10485760
    int8_t* buf = malloc(sizeof(int8_t)*PREALLOC);
    size_t siz = 0, rdsiz = 0;

    while(1) {
        rdsiz = read(STDIN_FILENO, buf+siz, PREALLOC-siz);
        if(rdsiz<0){
            perror("read(STDIN_FILENO)");
            exit(EXIT_FAILURE);
        }else if(rdsiz==0){
            break;
        }
        siz += rdsiz;
    }
    if(siz<PREALLOC-1)
        buf[siz] = 0;

    struct buf_t res = {
        .buf = buf,
        .siz = siz,
        .head = 0,
    };
    return res;
}

/* The head of the not yet readed data */
int8_t *stdin_data;

/* Read an integer from standard input, requires `data` to be already initialized */
int64_t
next_int()
{
    return strtol((char*)stdin_data, (char**)&stdin_data, 10);
}


int
main(void)
{
    struct primes P = gen_primes();
    data = read_stdin();
    stdin_data = data.buf;
    int64_t n;

tc:
    n = next_int();

    if(n==0) {
        return EXIT_SUCCESS;
    }

    for(size_t i = 1; i<P.primes_size; i++){
        int64_t prime = P.primes[i];

        if(2*prime >= n){
            printf("Goldbach conjecture is wrong\n");
            goto tc;
        }

        if(!P.not_prime[n-prime]){
            printf("%ld = %ld + %ld\n", n, prime, n-prime);
            goto tc;
        }
    }
    
    return EXIT_SUCCESS;
}