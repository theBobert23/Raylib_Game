#include "paddleGame.hpp"


paddleGame :: ~paddleGame() {
	delete Player;
	delete Player2;
	delete ball;
}

paddleGame :: paddleGame() {

	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	Player = new Paddle(GetWindowSize(), ObjectSide::Left, Type::Player);
	Player2 = new Paddle(GetWindowSize(), ObjectSide::Right, Type::Player);
 
	ball = new Ball( { (float) WINDOW_WIDTH / 2.0f, (float) WINDOW_HEIGHT / 2.0f});

}

void paddleGame :: Init() {
	
}

void paddleGame :: Draw() {
	Player->Draw();
	Player2->Draw();
	ball->Draw();
}

void paddleGame :: Update(float dt) {

	UpdateBall(dt);

	Player->Update(dt);
	Player2->Update(dt);
	ball->Update(dt);

}

void paddleGame :: UpdateBall(float dt) {

	Vector2 ballPos = ball->GetPosition();
	int rad = ball->GetRadius();
	
	Vector2 paddleSize = Player->GetSize();
	Vector2 p1Pos = Player->GetPos();
	Vector2 p2Pos = Player2->GetPos();

	if (ballPos.y - rad < 1)
		ball->Invert_Y_Direction();
	if (ballPos.y > WINDOW_HEIGHT - rad)
		ball->Invert_Y_Direction();

	if ((ballPos.x - rad < p1Pos.x + paddleSize.x) && 
		(ballPos.y > p1Pos.y && ballPos.y < p1Pos.y + paddleSize.y))
		ball->Invert_X_Direction();
	if ((ballPos.x + rad > p2Pos.x) &&
		(ballPos.y > p1Pos.y && ballPos.y < p1Pos.y + paddleSize.y))
		ball->Invert_X_Direction();
}

void paddleGame :: CheckInput() {

}

bool paddleGame :: ShouldClose() {
	return false;
}
