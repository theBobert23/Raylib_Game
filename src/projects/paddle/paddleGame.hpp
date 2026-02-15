#pragma once
#include "../../constants.hpp"
#include "../../core/game.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "../../utils.hpp"


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