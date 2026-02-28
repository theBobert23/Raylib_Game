#pragma once

//FOR: unique_ptr;  time();  
#include <memory>
#include <ctime>
#include <vector>

#include "raylib.h"
#include "../../engine/base/game.hpp"
#include "menuButton.hpp"
#include "../shared/constants.hpp"
#include "../paddle/paddleGame.hpp"
#include "../kitchen/kitchenGame.hpp"


class Menu {
private:
	std::unique_ptr<Game> game;
	std::vector <GameInfo> games = {
		{GameID::Pong, GameType::MultiPlayer},
		{GameID::Kitchen, GameType::SinglePlayer}
	};
	std::vector<GameIcon> gameIcons;
	std::vector<std::unique_ptr<MenuButton>> buttons;

	void InitGames();
	void MenuUpdate(float dt);
	void MenuDraw();
	void DrawButtons();
	void Update(float dt);
	void Draw();
	void CheckInput();
	void LoadGame(GameInfo info);
	
public:
	~Menu();
	Menu();

	void Init();
	void Run();
};