#include "../include/graphics/cube.h"

static Color getColor(char c)
{
    switch (c)
    {
        case 'W': return WHITE;
        case 'G': return GREEN;
        case 'R': return RED;
        case 'B': return BLUE;
        case 'O': return ORANGE;
        case 'Y': return YELLOW;
        default: return GRAY;
    }
}

static int getIndex(int face, int row, int col)
{
    return (face * 9) + (row * 3) + col;
}

static void DrawCubie(Vector3 position, char *cube, int x, int y, int z)
{
    float cubeSize = 1.0f;
    
    Color front = getColor(cube[getIndex(0, y, x)]);
    Color back  = getColor(cube[getIndex(1, y, 2 - x)]);
    Color top   = getColor(cube[getIndex(2, z, x)]);
    Color bottom = getColor(cube[getIndex(3, 2 - z, x)]);
    Color left  = getColor(cube[getIndex(4, y, 2 - z)]);
    Color right = getColor(cube[getIndex(5, y, z)]);

    DrawCube(position, cubeSize, cubeSize, cubeSize, GRAY);
    if (z == 1) DrawCubeV(position, (Vector3){cubeSize, cubeSize, 0.1f}, front);
    if (z == -1) DrawCubeV(position, (Vector3){cubeSize, cubeSize, 0.1f}, back);
    if (y == 1) DrawCubeV(position, (Vector3){cubeSize, 0.1f, cubeSize}, top);
    if (y == -1) DrawCubeV(position, (Vector3){cubeSize, 0.1f, cubeSize}, bottom);
    if (x == -1) DrawCubeV(position, (Vector3){0.1f, cubeSize, cubeSize}, left);
    if (x == 1) DrawCubeV(position, (Vector3){0.1f, cubeSize, cubeSize}, right);

    DrawCubeWires(position, cubeSize, cubeSize, cubeSize, BLACK);
}


void DrawRubiksCube(char *cube)
{
    float spacing = 1.1f;

    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            for (int z = -1; z <= 1; z++)
            {
                Vector3 position = {x * spacing, y * spacing, z * spacing};
                DrawCubie(position, cube, x + 1, y + 1, z + 1);
            }
        }
    }
}