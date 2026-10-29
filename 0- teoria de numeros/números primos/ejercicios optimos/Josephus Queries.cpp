#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int64_t solve(int64_t n, int64_t k, bool rem_first) {
    //printf("solve(%ld, %ld, %d)\n", n, k, (int32_t)rem_first);
    int64_t remaining = (n&1) ? ((n+1)/2 - rem_first) : (n/2);
    int64_t del = n - remaining;
    if(n==1)
        return 1;
    if(k <= del)
        return 2*k - rem_first;
    bool rem_last = rem_first == (n&1);
    return solve(remaining, k-del, !rem_last)*2 - (int64_t)!rem_first;
}

int main() {

    size_t q;
    int64_t n, k;
    scanf("%ld", &q);

    while(q--){
        scanf("%ld%ld", &n, &k);
        int32_t step = solve(n, k, 0);
        printf("%d\n", step);

    }

    return EXIT_SUCCESS;
}