#include <stdio.h>

int main(void)
{
    char c;
    scanf("%c", &c);
    switch(c){
    case 'A': printf("5\n");break;
    case 'B': printf("4\n");break;
    case 'C': printf("4\n");break;
    case 'D': printf("3\n");break;
    case 'E': printf("2\n");break;
    }
    return 0;
}