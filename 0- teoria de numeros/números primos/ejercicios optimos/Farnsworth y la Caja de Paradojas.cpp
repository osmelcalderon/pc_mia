#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%i %i %i",&a,&b,&c);
    if(a==b&&b==c) printf("3");
    if(a==b&&a!=c) printf("2");
    if(a==c&&a!=b) printf("2");
    if(b==c&&b!=a) printf("2");
    if(b!=c&&c!=a&&b!=a) printf("1");
}