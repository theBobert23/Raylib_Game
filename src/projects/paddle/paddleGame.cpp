#include "paddleGame.hpp"


paddleGame :: ~paddleGame() {
	delete Player;
	delete Enemy;
}

paddleGame :: paddleGame() {
	
	WINDOW.width = 900;
	WINDOW.height = 600;

	SetWindowSize(WINDOW.width, WINDOW.height);

	Player = new Paddle(WINDOW, ObjectSide::Left, Type::Player);
	Enemy = new Paddle(WINDOW, ObjectSide::Right, Type::Player);
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
