#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef long long i64;
typedef long i32;
typedef unsigned char u8;

// Read an integer from stdin
i64 read64();

#define MAX 200001
i64 A[MAX], tmp[MAX];


void merge(i64 *l, i64 lsz, i64 *r, i64 rsz, i64 *out) {
    i64 ptr = 0, lc = 0, rc = 0;

    while( lc<lsz && rc<rsz ) {
        if(l[lc] < r[rc]) {
            out[ptr++] = l[lc++];
        }else{
            out[ptr++] = r[rc++];
        }
    }

    while(lc<lsz)
        out[ptr++] = l[lc++];

    while(rc<rsz)
        out[ptr++] = r[rc++];
}


void sort(i64 *a, i64 sz) {
    if(sz<=1){
        return;
    }else if(sz==2){
        if(a[0] > a[1]){
            i64 t = a[1];
            a[1] = a[0];
            a[0] = t;
        }
        return;
    }

    int mid = sz>>1;
    sort(a, mid);
    sort(a+mid, sz-mid);
    merge(a, mid, a+mid, sz-mid, tmp);
    for(int i = 0; i<sz; i++)
        a[i] = tmp[i];
}


// Main entry point, called on start
int main() {

  i64 n = read64(),
      cnt = 0;

  // Input the numbers
  for (int i = 0; i < n; i++) {
    A[i] = read64();

  }

  sort(A, n);

  cnt = n>=1 ? 1 : 0;
  for(int i = 1; i<n; i++){
        if(A[i] != A[i-1])
            cnt += 1;
      //printf("%lld\n", A[i]);
  }

  printf("%lld\n", cnt);

  return EXIT_SUCCESS;
}

//================================

// 200 KiB
#define SIZE 204800

u8 next_char() {
  static u8 buf[SIZE];
  static i64 bufsz = -1, bufhead = -1, try = 0;

  if (bufhead >= bufsz) {
    // Get more data
    bufsz = read(STDIN_FILENO, buf, SIZE);
    if (bufsz > 0) {
      bufhead = 0;
      try = 0;
    } else if (bufsz == 0) {
      return 0;
    } else if (bufsz < 0) {

      if (try >= 10) {
        perror("read failed");
        exit(EXIT_FAILURE);
      }

      try += 1;
      return next_char();
    }
  }
  return buf[bufhead++];
}

i64 read64() {
  i64 res = 0;
  while (1) {
    u8 c = next_char();
    if (c < '0' || c > '9')
      continue;
    res = c - '0';
    break;
  }

  while (1) {
    u8 c = next_char();
    if (c < '0' || c > '9')
      break;
    res = res * 10 + c - '0';
  }
  return res;
}