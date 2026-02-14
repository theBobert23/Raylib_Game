#include "menu.hpp"
#include "../constants.hpp"

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

	//VSYNC for anti screen tearing, caps FPS to monitor Hz so no need for SetTargerFPS(); 
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

	InitWindow(MenuConst::WINDOW_WIDTH, MenuConst::WINDOW_HEIGHT, TITLE);
	
	RenderTexture2D target = LoadRenderTexture(MenuConst::WINDOW_WIDTH, 
		MenuConst::WINDOW_HEIGHT);
	

	while (!WindowShouldClose()) {

		//PUT EVERYTHING ON THE VIRTUAL CANVAS
		BeginTextureMode(target);
		
		ClearBackground(RAYWHITE);

		float dt = GetFrameTime();

		

		if (game != nullptr) {
			game->Update(dt);
			game->Draw();
		}
		else {
			Update(dt);
			Draw();
		}
		
		EndTextureMode();

		//SCALE AND DRAW THE CANVAS ON THE WINDOW
		BeginDrawing();

		ClearBackground(BLUE);

		float scale = fminf((float)GetScreenWidth() / (float)WINDOW_WIDTH,
			(float)GetScreenHeight() / (float)WINDOW_HEIGHT);

		int ScreenW = GetScreenWidth();
		int ScreenH = GetScreenHeight();

		DrawTexturePro(target.texture,
			Rectangle{ 0.0f, 0.0f,
			(float)target.texture.width,
			(float)target.texture.height },

			Rectangle{ (ScreenW - WINDOW_WIDTH * scale) * 0.5f,
				-(ScreenH - WINDOW_HEIGHT * scale) * 0.5f,
				WINDOW_WIDTH * scale,
				WINDOW_HEIGHT * scale },

			Vector2{ 0, 0 }, 0.0f, WHITE);

		EndDrawing();
	}

	UnloadRenderTexture(target);

	CloseWindow();

}

void Menu::Update(float dt) {
	if (IsKeyPressed(KEY_P))
		game = new paddleGame();
}

void Menu::Draw() {

}