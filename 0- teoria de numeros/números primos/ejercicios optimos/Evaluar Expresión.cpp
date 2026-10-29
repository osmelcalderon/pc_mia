#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    short initial = 0;
    char *string = (char *)malloc(401 * sizeof(char));
    scanf("%s", string);
    short nsums = 0;
    short nsubs = 0;

    char c = *string;
    while (c != '\0')
    {
        if (c == '+')
        {
            nsums++;
        }
        else if (c == '-')
        {
            nsubs++;
        }

        string++;
        c = *string;
    }
    initial = ((int)(nsums / 2)) - ((int)(nsubs / 2));
    printf("%d", initial);

    return 0;
}