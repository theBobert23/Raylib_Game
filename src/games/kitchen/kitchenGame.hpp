#pragma once 

#include "../../engine/core/game.hpp"
#include "../shared/constants.hpp"
#include "kitchenPlayer.hpp"

#include <memory>

class KitchenGame : public Game {
private:
	std::unique_ptr<KitchenPlayer> player;
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