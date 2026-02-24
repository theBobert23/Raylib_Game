#include "menu.hpp"
#include "../constants.hpp"

using namespace GeneralConst;
using namespace MenuConst;


Menu::~Menu() {

}

Menu::Menu() {
	game = nullptr;
	gameIcons.reserve(games.size());
	buttons.reserve(games.size() * 2);
}

void Menu::Init() {

	InitGames();

	//FOR GetRandomValue();
	SetRandomSeed((unsigned int) time(nullptr));

	//VSYNC for anti screen tearing, caps FPS to monitor Hz so no need for SetTargerFPS(); 
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

	//excludes esc from closing he window
	SetExitKey(KEY_NULL);
}

void Menu::InitGames() {

	//---- Spacing logic ----
	int icons = WINDOW_WIDTH / ICON_SIZE;
	if (!(icons % 2)) icons--;

	int iconsWidth = icons * ICON_SIZE;

	int PADDING = (WINDOW_WIDTH - iconsWidth) / 2;
	// -- / --

	int BUTTON_SIZE = (ICON_SIZE - BUTTON_GAP) / 2;

	for (size_t i = 0; i < games.size(); i++) {

		int row = 0;

		gameIcons.push_back({});

		if (games[i].type == GameType::MultiPlayer) {
			
			buttons.push_back(std::make_unique<Button>(
			Rectangle { (float)(PADDING + i * (ICON_SIZE + COL_GAP)), (float)(PADDING + row * (ICON_SIZE + ROW_GAP) + ICON_SIZE + BUTTON_GAP), (float) BUTTON_SIZE, (float) BUTTON_SIZE },
				games[i].id, GameType::SinglePlayer));
		
			buttons.push_back(std::make_unique<Button>(
				Rectangle{ (float)(PADDING + i * (ICON_SIZE + COL_GAP) + BUTTON_SIZE + BUTTON_GAP), (float)(PADDING + row * (ICON_SIZE + ROW_GAP) + ICON_SIZE + BUTTON_GAP), (float)BUTTON_SIZE, (float)BUTTON_SIZE },
				games[i].id, GameType::MultiPlayer));
		}
		else
			buttons.push_back( std::make_unique<Button> (
				Rectangle {(float) (PADDING + i * (ICON_SIZE + COL_GAP)), (float) (PADDING + row * (ICON_SIZE + ROW_GAP) + ICON_SIZE + BUTTON_GAP ), (float) ICON_SIZE, (float) BUTTON_SIZE },
				games[i].id, GameType::SinglePlayer));
	}

	std::cout<<buttons[0]->isClicked(1000, 10);

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
	CheckInput();
}

void Menu::MenuDraw() {

	int icons = WINDOW_WIDTH / ICON_SIZE;
	if (!(icons % 2)) icons--;

	int iconsWidth = icons * ICON_SIZE;

	int PADDING = (WINDOW_WIDTH -  iconsWidth) / 2; 

	DrawButtons();
	
	for (size_t i = 0; i < games.size(); i++) {

		int col = 0;

		int BUTTON_SIZE = (ICON_SIZE - BUTTON_GAP) / 2;

		DrawRectangle((int) i * ICON_SIZE * 2 + PADDING, col * ICON_SIZE * 2 + PADDING, ICON_SIZE, ICON_SIZE, BLUE);

		if (games[i].type == GameType::MultiPlayer) {
			//DrawRectangle(i * ICON_SIZE * 2 + PADDING, col * ICON_SIZE * 2 + PADDING + (ICON_SIZE + GAP), BUTTON_SIZE, BUTTON_SIZE, RED);
			//DrawRectangle(i * ICON_SIZE * 2 + PADDING + BUTTON_GAP + BUTTON_SIZE, col * ICON_SIZE * 2 + PADDING + (ICON_SIZE + GAP), BUTTON_SIZE, BUTTON_SIZE, RED);
		}
		else
			;
			//DrawRectangle(i * ICON_SIZE * 2 + PADDING, col * ICON_SIZE * 2 + PADDING + (ICON_SIZE + GAP), BUTTON_SIZE * 2 + GAP, BUTTON_SIZE, RED);
	}

}

void Menu::DrawButtons() {
	for (const auto& button : buttons)
		button->Draw();
}

void Menu::CheckInput() {
	
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		int x = GetMouseX();
		int y = GetMouseY();

		for (auto& button : buttons)
			if (button->isClicked(x, y))
				LoadGame(button->GetGame());
	}

}

void Menu::LoadGame(GameInfo info) {
	
	switch (info.id) {
		case GameID::Pong :
			game = info.type == GameType::SinglePlayer ? std::make_unique<paddleGame>(GameType::SinglePlayer) : std::make_unique<paddleGame>(GameType::MultiPlayer);
			break;
		case GameID::Kitchen :
			game = std::make_unique<KitchenGame>();
			break;

	}

}

void Menu::Update(float dt) {

	// --- INPUT CHECKS ---
	if (IsKeyPressed(KEY_F11))
		ToggleFullscreen();
	
	// --- ---

	if ( game != nullptr) 
		if ( game->ShouldClose())
			game = nullptr;

}


void Menu::Draw() {

}