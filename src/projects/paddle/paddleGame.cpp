#include "paddleGame.hpp"

using namespace PaddleGameConst;
using namespace GeneralConst;

paddleGame :: ~paddleGame() {
	delete Player;
	delete Player2;
	delete ball;
}

paddleGame :: paddleGame() {

	Player = new Paddle(ObjectSide::Left, Type::Player);
	Player2 = new Paddle(ObjectSide::Right, Type::Player);
 
	ball = new Ball( BALL_START_POS );

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
	else if (ballPos.x - rad < p1Pos.x + paddleSize.x) {
		ResetBall();
		return;
	} 

	if ((ballPos.x + rad > p2Pos.x - paddleSize.x/2) &&
		(ballPos.y > p2Pos.y && ballPos.y < p2Pos.y + paddleSize.y))
		ball->Invert_X_Direction();
	else if (ballPos.x + rad > p2Pos.x) {
		ResetBall();
		return;
	}

}

void paddleGame :: ResetBall(){
	ball->RandomDirection();
	ball->SetPosition(BALL_START_POS);
}

void paddleGame :: CheckInput() {

}

bool paddleGame :: ShouldClose() {
	return false;
}
