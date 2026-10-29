#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int t;
    scanf("%d\n", &t);
    while(t--){
        char s[101];
        fgets(s, 101, stdin);
        int final = 0, i;
        for(i = 0; i < strlen(s); i++){
            if(tolower(s[i]) == 'z') {
                final++;
            }
        }

        if(final >= 3){
            puts("Time to take a nap.");
        }
        else{
            puts("Perry saves the day!");
        }
    }

    return 0;
}