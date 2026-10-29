#include<stdio.h>
int main(){
long long Azul,Rojo=0,B,C,D;
scanf("%lld%lld%lld%lld",&Azul,&B,&C,&D);

long long sol=0;
if(B/D>=C){
    printf("-1");
    return 0;
}
if(Azul==0){
    sol++;
    Azul+=B;
Rojo+=C;
}
while(Azul>Rojo*D){
sol++;

Azul+=B;
Rojo+=C;
//printf("%lld %lld\n",Azul,Rojo);
}
printf("%lld",sol);
return 0;
}