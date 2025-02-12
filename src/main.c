#include "../include/rubik.h"


int main()
{
    char *cube = (char *) malloc(sizeof(char) * 54);
    if (!cube)
        return NULL;

    for(int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                *(cube + i + j + k) = BLUE;
            }
        }
    }

    for(int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("%c ", *(cube + i + j + k));
            }
            printf("\n");
        }
        printf("\n\n");
    }

    free(cube);
}