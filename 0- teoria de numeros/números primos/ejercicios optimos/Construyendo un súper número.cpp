#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MOD 34047161064
int main()
{
      char k [10];
   long long a, c = 0;
   int n, b, l,d;
   scanf("%i %i", &n, &b);
   scanf("%s", k);
   a = strlen(k);
   d = a;
   b--;
           for(int f = 0; f < d; f++){
            c += k[f] - '0';
        }
        l = c;
   while(b--){
     c += (a-1) * l;
    a  = ((a - 1) * d + a) % MOD;
   }
printf("%lld\n", a);

    if(n == 2){
    if(c % 3 == 0){
           puts("Si");
        }else{
           puts("No");
        }
    }
    return 0;
}