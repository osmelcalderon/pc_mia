#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef unsigned char u8;
typedef long long i64;

i64 read64();

static i64 tree[200001];
static int tree_sz;

void tree_init(int n, int* A) {
    tree_sz = n;
    for(int i = 2*n-1; i>=n; i--){
        tree[i] = A[i-n];
    }
    for(int i = 2*n-2; i>1; i-=2){
        tree[i>>1] = tree[i]+tree[i+1];
    }
}

void tree_set(int x, i64 v) {
    x += tree_sz;
    tree[x] = v;
    while(x>1){
        if(x&1)
            tree[x>>1] = tree[x-1] + tree[x];
        else
            tree[x>>1] = tree[x] + tree[x+1];
        x >>= 1;
    }
}

i64 tree_query(int l, int r) {
    l += tree_sz;
    r += tree_sz;

    i64 sol = 0;

    while(l<=r) {
        if( (l&1) ) sol += tree[l++];
        if(!(r&1) ) sol += tree[r--];
        l >>= 1;
        r >>= 1;
    }

    return sol;
}


void solve() {
    static int A[100000];

    i64 n = read64(),
        q = read64();

    for(int i = 0; i<n; i++){
        A[i] = read64();
    }

    tree_init(n, A);

    // Queries
    for(int i = 0; i<q; i++){
        int w = read64();

        if(w==1) {
            int x = read64();
            printf("%lld\n", tree[n+x]);
            tree_set(x, 0);
        }else if(w==2) {
            int x = read64(),
                v = read64();
            tree_set(x, tree[x+n] + v);
        }else if(w==3) {
            int x = read64(), y = read64();
            printf("%lld\n", tree_query(x, y));
        }
    }
}


int main() {
    i64 t = read64();
    int tc = 1;

    while(t--){
        printf("Case %d:\n", tc++);
        solve();
    }
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