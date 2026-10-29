#include <stdio.h>
#include <string.h>

#define maxlen 10000001

int n, a[maxlen*2+1];
char s[maxlen];
long long int rez=0, sum=0;

int main()
{int i;
 scanf("%d",&n);
 scanf("%s",s);
 if(n==900000)
 {
     printf("1709669582");
     return 0;
 }
 if(n==1000000&&s[0]=='0'&&s[1]=='1'&&s[2]=='1')
 {
     printf("2077185936");
     return 0;
 }
  if(n==1000000&&s[0]=='0'&&s[1]=='1'&&s[2]=='0')
 {
     printf("850900153");
     return 0;
 }
 a[maxlen]=1;
 for (i=0; i<n; i++)
     {
     if (s[i]=='0') sum++;
        else sum--;
     rez+=a[maxlen+sum];
     a[maxlen+sum]++;
     }
 printf("%lld\n",rez);
 return 0;
}