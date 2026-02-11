#include "paddleGame.hpp"


paddleGame :: ~paddleGame() {
	delete Player;
	delete Enemy;
}

paddleGame :: paddleGame() {

	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	Player = new Paddle(GetWindowSize(), ObjectSide::Left, Type::Player);
	Enemy = new Paddle(GetWindowSize(), ObjectSide::Right, Type::Player);
}

void paddleGame :: Init() {
	
}

void paddleGame :: Draw() {
	Player->Draw();
	Enemy->Draw();
}

void paddleGame :: Update(float dt) {
	Player->Update(dt);
	Enemy->Update(dt);

}

void paddleGame :: CheckInput() {

}

bool paddleGame :: ShouldClose() {
	return false;
}
