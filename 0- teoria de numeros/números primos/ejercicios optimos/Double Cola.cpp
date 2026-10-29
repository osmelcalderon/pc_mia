#include <stdio.h>
#define uint unsigned long long

int main()
{
  int T; scanf("%d\n", &T);
  while (T--)
  {
    uint n; scanf("%llu", &n);
    uint t = 0, i = 5;

    while (t + i < n)
      t += i, i *= 2;
    uint p = i / 5;

    switch ((n - t - 1) / p)
    {
      case 0:
        printf("Sheldon\n");
        break;
      case 1:
        printf("Leonard\n");
        break;
      case 2:
        printf("Penny\n");
        break;
      case 3:
        printf("Rajesh\n");
        break;
      case 4:
        printf("Howard\n");
        break;
    }
  }
}