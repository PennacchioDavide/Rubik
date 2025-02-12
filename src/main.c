#include "../include/rubik.h"
#include "../include/graphics/cube.h"


int main()
{
    char *cube = (char *) malloc(sizeof(char) * 54);
    if (!cube)
        exit(1);

    for(int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                *(cube + i + j + k) = B;
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

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Rubik");

    SetTargetFPS(144);

    while(!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Hello", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}