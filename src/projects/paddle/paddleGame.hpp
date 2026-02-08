#pragma once

#include "../../core/game.hpp"
#include "paddle.hpp"

class paddleGame : public Game {
private:
	int PADDLE_WINDOW_WIDTH;
	int PADDLE_WINDOW_HEIGHT;
	
public:
	~paddleGame() override;

	paddleGame();
	void Init() override;
	void Draw() override;
	void Update() override;
	void CheckInput() override;
	bool ShouldClose() override;
	
};