#include "menu.hpp"
#include "../Constants.hpp"

using namespace MenuConst;

Menu::~Menu() {
	delete game;

}

Menu::Menu() {
	game = nullptr;
}

void Menu::Init() {

	//FOR GetRandomValue();
	SetRandomSeed(time(nullptr));

	//VSYNC for anti screen tearing; 
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

	InitWindow(MenuConst::WINDOW_WIDTH, MenuConst::WINDOW_HEIGHT, TITLE);
	
	RenderTexture2D target = LoadRenderTexture(MenuConst::WINDOW_WIDTH, MenuConst::WINDOW_HEIGHT);

	SetTargetFPS(120);

	while (!WindowShouldClose()) {

		//PUT EVERYTHING ON THE VIRTUAL CANVAS
		BeginTextureMode(target);
		
		ClearBackground(RAYWHITE);

		float dt = GetFrameTime();

		Update(dt);

		if (game != nullptr) {
			game->Update(dt);
			game->Draw();
		}else
			Draw();
		
		EndTextureMode();

		//SCALE AND DRAW THE CANVAS ON THE WINDOW
		BeginDrawing();

		ClearBackground(BLUE);

		float scale = fminf((float) GetScreenWidth() / (float) WINDOW_WIDTH, (float) GetScreenHeight() / (float) WINDOW_HEIGHT );

		DrawTexturePro(target.texture,
			Rectangle{ 0.0f, 0.0f,
			(float)target.texture.width,
			(float)target.texture.height },
			Rectangle{} );

		EndDrawing();
	}

	UnloadTexture(target.texture);

	CloseWindow();

}

void Menu::Update(float dt) {
	if (IsKeyPressed(KEY_P))
		game = new paddleGame();
}

void Menu::Draw() {

}