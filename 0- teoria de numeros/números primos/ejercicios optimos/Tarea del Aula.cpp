#include <stdio.h>
#include <string.h>

int main() {

    char cadena1[101], operador, cadena2[101];
    int i;
    scanf("%s %c %s",cadena1, &operador, cadena2);

    int tam1 = strlen(cadena1);
    int tam2 = strlen(cadena2);

    if (operador == '+'){
        if (tam1 == tam2){
            cadena1[0] = '2';
            printf("%s\n", cadena1);
        }
        else{
            if (tam1 < tam2){
                cadena2[tam2 - tam1] = '1';
                printf("%s\n", cadena2);
            }
            else{
                cadena1[tam1 - tam2] = '1';
                printf("%s\n", cadena1);
            }
        }
    }
    else{
        if (tam1 < tam2){
            for (i = 1; i < tam1; i++){
                cadena2[tam2++] = '0';
            }
            cadena2[tam2] = '\0';
            printf("%s\n", cadena2);
        }
        else{
            for (i = 1; i < tam2; i++){
                cadena1[tam1++] = '0';
            }
            cadena1[tam1] = '\0';
            printf("%s\n", cadena1);
        }
    }

    return 0;
}