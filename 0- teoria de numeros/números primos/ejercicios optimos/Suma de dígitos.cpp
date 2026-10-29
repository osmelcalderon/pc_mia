int log2(int x) {
  if (x <= 0) {
    return -1;
  }
  int result = 0;
  while (x > 1) {
    x /= 2;
    result++;
  }
  return result;
}

int quickPow(int base, int exp) {
  int result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = result * base;
    }
    base = base * base;
    exp = exp / 2;
  }
  return result;
}


int main() {
    int i, sum = 0;
    int r;
    scanf("%d", &i);
    while (i != 0){
       r=log2(i);
       i-=quickPow(2,r);
       sum += i + 1 + r * quickPow(2, r - 1);
    }
    printf("%d", sum);
    return 0;
}