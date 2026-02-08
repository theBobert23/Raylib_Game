#include "core/game.hpp"
#include "projects/paddle/paddleGame.hpp"



int main()
{

    Game* game = new paddleGame();

    int WIDTH = game->GetWindowWidth();
    int HEIGHT = game->GetWindowHeight();

    game->Init();

    
    InitWindow(WIDTH,HEIGHT, "MyGame");
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