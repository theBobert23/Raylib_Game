#include "kitchenGame.hpp"


using namespace GeneralConst;

KitchenGame::~KitchenGame() {

}

KitchenGame::KitchenGame() {
	player = std::make_unique<Player>();
	PAUSED = false;

	Init();
}

void KitchenGame::Init() {

	camera.position = {0.0f, 2.0f, 6.0f};
	camera.target = {0.0f, 1.5f, 0.0f};
	camera.fovy = 60.0f;
	camera.up = { 0.0f, 1.0f,0.0f };
	camera.projection = CAMERA_PERSPECTIVE;

	DisableCursor();

}

void KitchenGame::Draw() {


	if (PAUSED)
		DrawPauseMenu();
	else {
		BeginMode3D(camera);

		DrawPlane({ 0.0f, 0.0f, 0.0f }, { 30, 10 }, BLUE);

		EndMode3D();

		DrawCircle(100, 100, 20, RED);

	}

}

void KitchenGame::DrawPauseMenu() {
	DrawText("PAUSED", WINDOW_WIDTH / 2, 100, 50, BLACK);
}

void KitchenGame::Update(float dt){

	if (!PAUSED) {
		CheckInput();
		UpdateCamera(&camera, CAMERA_FIRST_PERSON);
		player->Update(dt);

	}
	else {
		;
	}



}

void KitchenGame::CheckInput(){

	if (IsKeyPressed(KEY_ESCAPE))
		if (!PAUSED) {
			PAUSED = true;
			EnableCursor();
		}
		else {
			PAUSED = false;
			DisableCursor();
		}
}

bool KitchenGame::ShouldClose() {
	return false;
}
