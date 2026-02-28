#pragma once 

#include "../../engine/base/game.hpp"
#include "../shared/constants.hpp"
#include "player.hpp"

#include <memory>

class KitchenGame : public Game {
private:
	std::unique_ptr<Player> player;
	Camera3D camera;
	bool PAUSED;
public:
	~KitchenGame() override;
	KitchenGame();

	void Init() override;
	void Draw() override;
	void Update(float dt) override;
	void CheckInput() override;
	bool ShouldClose() override;

	void DrawPauseMenu();

};