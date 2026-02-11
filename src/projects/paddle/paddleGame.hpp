#pragma once

#include "../../core/game.hpp"
#include "paddle.hpp"
#include "../../utils.hpp"


namespace {
	constexpr int WINDOW_WIDTH = 1200;
	constexpr int  WINDOW_HEIGHT = 600;
}


class paddleGame : public Game {
private:
	Paddle* Player;
	Paddle* Enemy;
	
public:
	~paddleGame() override;

	paddleGame();
	void Init() override;
	void Draw() override;
	void Update(float dt) override;
	void CheckInput() override;
	bool ShouldClose() override;
	
};