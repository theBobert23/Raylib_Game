#pragma once

//FOR: unique_ptr;  time();  
#include <memory>
#include <ctime>
#include <vector>

#include "raylib.h"
#include "game.hpp"
#include "button.hpp"
#include "projects/paddle/paddleGame.hpp"


class Menu {
private:
	Game* game;
	std::vector <GameInfo> games = {
		{GameID::Pong, GameType::MultiPlayer},
		{GameID::SpaceInvasion, GameType::SinglePlayer}
	};
	std::vector<GameIcon> gameIcons;
	std::vector<std::unique_ptr<Button>> buttons;

	void InitGames();
	void MenuUpdate(float dt);
	void MenuDraw();
	void DrawButtons();
	void Update(float dt);
	void Draw();
	void CheckInput();
	
public:
	~Menu();
	Menu();

	void Init();
	void Run();
};