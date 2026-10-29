#include <stdio.h>
#include <math.h>

int main() {

   long num, numTemporal, suma1, suma2 = 0, i;
   scanf("%ld", &num);
   suma1 = num * (num + 1)/2;
   for (i = 0; i < num - 1; i++){
       scanf("%ld", &numTemporal);
       suma2 += numTemporal;
   }
   
   printf("%ld", suma1 - suma2);

    return 0;
}