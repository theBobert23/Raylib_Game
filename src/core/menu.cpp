#include "menu.hpp"
#include "../constants.hpp"

using namespace GeneralConst;
using namespace MenuConst;


Menu::~Menu() {
	delete game;

}

Menu::Menu() {
	game = nullptr;
}

void Menu::Init() {

	//FOR GetRandomValue();
	SetRandomSeed((unsigned int) time(nullptr));

	//VSYNC for anti screen tearing, caps FPS to monitor Hz so no need for SetTargerFPS(); 
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

	//excludes esc from closing he window
	SetExitKey(KEY_NULL);
}

void Menu::Run() {

	RenderTexture2D target = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);

	while (!WindowShouldClose()) {

		BeginTextureMode(target);

		ClearBackground(WHITE);

		//a max dt of 30fps
		float dt = fminf(GetFrameTime(), 1 / 30.f);

		if (game != nullptr) {
			game->Update(dt);
			game->Draw();
		}else {
			MenuUpdate(dt);
			MenuDraw();
		}

		Draw();
		Update(dt);

		EndTextureMode();


		BeginDrawing();

		ClearBackground(BLUE);

		int screenW = GetScreenWidth();
		int screenH = GetScreenHeight();

		float scale = fminf(screenW / (float)WINDOW_WIDTH, screenH / (float)WINDOW_HEIGHT);

		DrawTexturePro(target.texture,
			Rectangle{ 0.0f, 0.0f, WINDOW_WIDTH, -WINDOW_HEIGHT },
			Rectangle{ (screenW - WINDOW_WIDTH * scale) / 2.0f, (screenH - WINDOW_HEIGHT * scale) / 2.0f, WINDOW_WIDTH * scale, WINDOW_HEIGHT * scale },
			Vector2{ 0,0 }, 0.0f, WHITE);

		EndDrawing();
		
	}

	UnloadRenderTexture(target);

	CloseWindow();

}

void Menu::MenuUpdate(float dt) {
	if (IsKeyPressed(KEY_P))
		game = new paddleGame();
}

void Menu::Update(float dt) {
	if (IsKeyPressed(KEY_F11))
		ToggleFullscreen();
}

void Menu::MenuDraw() {

	int icons = WINDOW_WIDTH / ICON_SIZE;
	if (!(icons % 2)) icons--;

	int iconsWidth = icons * ICON_SIZE;

	int PADDING = (WINDOW_WIDTH -  iconsWidth) / 2; 
	
	for (size_t i = 0; i < games.size(); i++) {

		int col = 0;

		int BUTTON_SIZE = (ICON_SIZE - GAP) / 2;

		DrawRectangle( i * ICON_SIZE * 2 + PADDING, col * ICON_SIZE * 2 + PADDING, ICON_SIZE, ICON_SIZE, BLUE);

		DrawRectangle(i * ICON_SIZE * 2 + PADDING, col * ICON_SIZE * 2 + PADDING + (ICON_SIZE + GAP), BUTTON_SIZE, BUTTON_SIZE, RED);
		DrawRectangle(i * ICON_SIZE * 2 + PADDING + GAP + BUTTON_SIZE, col * ICON_SIZE * 2 + PADDING + (ICON_SIZE + GAP), BUTTON_SIZE, BUTTON_SIZE, RED);
	}

}

void Menu::Draw() {

}