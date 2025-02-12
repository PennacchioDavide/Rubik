#include "../include/rubik.h"

void init_cube(char *cube)
{
    char colors[6] = {W, G, R, Y, O, B};
    for(int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int index = (i * 9) + (j * 3) + k;
                cube[index] = colors[i];
            }
        }
    }
    
    for(int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int index = (i * 9) + (j * 3) + k;
                printf("%c ", cube[index]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}

int main()
{
    char *cube = (char *) malloc(sizeof(char) * 54);
    if (!cube)
        exit(1);

    init_cube(cube);

    free(cube);

    return 0;
}