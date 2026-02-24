#pragma once 

#include "../../core/game.hpp"

class KitchenGame : public Game {
private:

public:
	~KitchenGame() override;
	KitchenGame();

	void Init() override;
	void Draw() override;
	void Update(float dt) override;
	void CheckInput() override;
	bool ShouldClose() override;

};