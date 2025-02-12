#include "../include/rubik.h"


int main()
{
    char ***cube;
    int i;
    int f; 

    cube = malloc(sizeof(char **) * 2);
    if (!cube)
        return (0);
    cube[0] = malloc(sizeof(char *) * 7);
    if (!*cube)
        return (0);
    for (i = 0; i < 6; i++) 
    {
        cube[0][i] = malloc(sizeof(char) * 9);
        if (!cube[0][i])
            return (1);
    }
    i = -1;
    while (i++, i < 6)
    {
        f = -1;
        while(f++, f < 9)
        {
            if (i == 0)
                cube[0][i][f] = WHITE;
            else if (i == 1)
                cube[0][i][f] = RED;
            else if (i == 2)
                cube[0][i][f] = YELLOW;
            else if (i == 3)
                cube[0][i][f] = ORANGE;
            else if (i == 4)
                cube[0][i][f] = BLUE;
            else if (i == 5)
                cube[0][i][f] = GREEN;
            printf("%c", cube[0][i][f]);
            if ((f + 1) % 3 == 0)
                printf("\n");
        }
        write(1, "\n", 1);
    }
}