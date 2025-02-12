#include "../include/rubik.h"
#include "../include/graphics/cube.h"

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
    
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Rubik");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 4.0f, 4.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    float rotationX = 0.0f;
    float rotationY = 0.0f;

    SetTargetFPS(144);

    while(!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) rotationY += 1.0f;
        if (IsKeyDown(KEY_LEFT)) rotationY -= 1.0f;
        if (IsKeyDown(KEY_UP)) rotationX -= 1.0f;
        if (IsKeyDown(KEY_DOWN)) rotationX += 1.0f;

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                rlPushMatrix();
                    rlTranslatef(0.0f, 0.0f, 0.0f);
                    rlRotatef(rotationX, 1, 0, 0);
                    rlRotatef(rotationY, 0, 1, 0);
                    DrawRubiksCube(cube);
                rlPopMatrix();

            EndMode3D();

        EndDrawing();
    }

    CloseWindow();

    free(cube);

    return 0;
}