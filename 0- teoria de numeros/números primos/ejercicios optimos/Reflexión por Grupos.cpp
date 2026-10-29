#include<stdio.h>
#include<cstring>
int main(){
    int T,s;
    char x[101],y[101];
    while(1){
        scanf("%d",&T);
        if(!T){break;}
        scanf("%101s",x);
        s=strlen(x);
        T=s/T;
        for(int i=T-1;i<s;i+=T){
            for(int j=i,k=i-(T-1);k<=i;--j,++k){
                y[k]=x[j];
            }
        }
        y[s]='\0';
        printf("%s\n",y);
    }
    return 0;
}