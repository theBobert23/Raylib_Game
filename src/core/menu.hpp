#pragma once

//FOR: unique_ptr;  time();  
#include <memory>
#include <ctime>
#include <vector>

#include "raylib.h"
#include "game.hpp"
#include "projects/paddle/paddleGame.hpp"

class Menu {
private:
	Game* game;
	std::vector <GameInfo> games = {
		{GameID::Pong, GameType::MultiPlayer},
		{GameID::SpaceInvasion, GameType::SinglePlayer}
	};

	void MenuUpdate(float dt);
	void MenuDraw();
	void Update(float dt);
	void Draw();
	
public:
	~Menu();
	Menu();

	void Init();
	void Run();
};