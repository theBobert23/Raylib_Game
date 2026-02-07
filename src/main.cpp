#include "raylib.h"

int main()
{
    InitWindow(850,450, "MyGame");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello Raylib!", 350, 200, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}