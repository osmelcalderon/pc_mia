#include<stdio.h>
#include<stdbool.h>
 
char Map[8][9];
bool Col[8]={false};
bool Diag1[16]={false};
bool Diag2[16]={false};
int cont=0;
 
void BackT(int f){
if(f==8){
    cont++;
    return;
}
 
for(int c=0;c<8;c++){
    if(Map[f][c]=='.'){
        int d1=f+c;
        int d2=f-c+7;
        if(!Col[c]&&!Diag1[d1]&&!Diag2[d2]){
        Col[c]=true;
        Diag1[d1]=true;
        Diag2[d2]=true;
            BackT(f+1);
        Col[c]=false;
        Diag1[d1]=false;
        Diag2[d2]=false;
        }
    }
}
}
 
int main(){
 
for(int i=0;i<8;i++)scanf("%s",Map[i]);
 
BackT(0);
printf("%d",cont);
 
return 0;
}