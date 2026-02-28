#pragma once

#include "../../engine/base/game.hpp"

#include "../shared/constants.hpp"
#include "../shared/utils.hpp"

#include "paddle.hpp"
#include "ball.hpp"


class paddleGame : public Game {
private:
	GameType TYPE;
	Paddle* Player;
	Paddle* Player2;
	Ball* ball;

	bool PAUSED;
	
	
public:
	~paddleGame() override;

	paddleGame(GameType type);
	void Init() override;
	void Draw() override;
	void Update(float dt) override;
	void CheckInput() override;
	bool ShouldClose() override;

	void UpdateBall(float dt);
	void ResetBall();
};