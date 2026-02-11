#include "core/game.hpp"
#include "projects/paddle/paddleGame.hpp"

#include <memory>


int main()
{

    std::unique_ptr<Game> game = std::make_unique<paddleGame>();

    int WIDTH = game->GetWindowWidth();
    int HEIGHT = game->GetWindowHeight();

    InitWindow(WIDTH,HEIGHT, "MyGame");
    
    game->Init();

    SetTargetFPS(60);

    //ENTER MENU
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        //Run each game untill closing then enter menu
        //while ( ! (game->ShouldClose())) 
            
            float dt = GetFrameTime();
        
            game->CheckInput();
            game->Update(dt);
            game->Draw();

        


        EndDrawing();
    }

    CloseWindow();
    return 0;
}