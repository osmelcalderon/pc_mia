#include <stdio.h>
main()
{
    long long int cont,ct;
    char car;
    cont =0; ct=0;
    bool vocales[26]={ };
    vocales[0]=1;
    vocales[4]=1;
    vocales[8]=1;
    vocales[14]=1;
    vocales[20]=1;
    while(car!='\n')
    {
        car=getchar();
        if(vocales[car-97]==1) ct++;
        else
        {
            if(ct>cont)cont =ct;
            ct=0;
        }
    }
    printf("%d",cont);
}