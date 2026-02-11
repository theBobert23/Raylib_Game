#pragma once

#include "../../core/game.hpp"
#include "paddle.hpp"
#include "../../utils.hpp"

class paddleGame : public Game {
private:
	Size WINDOW;
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