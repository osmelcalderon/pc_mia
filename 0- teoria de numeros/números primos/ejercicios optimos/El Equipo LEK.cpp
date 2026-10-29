#include<stdio.h>
int main(){
    int menor,mayor,actual,cantidad = 0,n;
    scanf("%d", &n);
    scanf("%d", &menor);
    mayor = menor;
    for(int i = 1; i<n;i++){
        scanf("%d", &actual);
        if(actual>mayor){
            mayor = actual;
            cantidad +=1;
        }
        else if(actual < menor){
            menor = actual;
            cantidad +=1;
        }
    }
    printf("%d", cantidad);
    return 0;

}