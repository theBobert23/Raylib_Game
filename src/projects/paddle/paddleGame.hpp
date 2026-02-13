#pragma once

#include "../../core/game.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "../../utils.hpp"


namespace {
	constexpr int WINDOW_WIDTH = 1200;
	constexpr int  WINDOW_HEIGHT = 600;
	constexpr Vector2 BALL_START_POS =  { (float)WINDOW_WIDTH / 2.0f, (float)WINDOW_HEIGHT / 2.0f} ;
}


class paddleGame : public Game {
private:
	Paddle* Player;
	Paddle* Player2;
	Ball* ball;
	
	
public:
	~paddleGame() override;

	paddleGame();
	void Init() override;
	void Draw() override;
	void Update(float dt) override;
	void CheckInput() override;
	bool ShouldClose() override;

	void UpdateBall(float dt);
	void ResetBall();
};