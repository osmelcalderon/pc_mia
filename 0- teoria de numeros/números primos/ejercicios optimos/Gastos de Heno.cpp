#include<stdio.h>
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    int v[n], p[m][2];
    for(int i=0; i<n; i++) scanf("%i",&v[i]);
    for(int i=0; i<m; i++) scanf("%i %i",&p[i][0],&p[i][1]);
    int sum;
    for(int i=0; i<m; i++)
    {
        sum=0;
        for(int j=p[i][0]-1; j<p[i][1]; j++) sum+=v[j];
        printf("%i\n",sum);
    }
}