#include<stdio.h>
#include<iostream>
#define Hd int main(void)

Hd{
    int a,b,c;
    int aux;
    scanf("%d%d%d",&a,&b,&c);
    while(a>b||a>c||b>c){
        if(a>c)aux=a,a=c,c=aux;
        if(a>b)aux=a,a=b,b=aux;
        if(b>c)aux=b,b=c,c=aux;
    }
    std::string ord;
    std::cin>>ord;
    for(char e: ord){
        if(e=='A')printf("%d ",a);
        if(e=='B')printf("%d ",b);
        if(e=='C')printf("%d ",c);
    }
}