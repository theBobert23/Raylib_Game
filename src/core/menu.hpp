#pragma once

//FOR: unique_ptr;  time();  
#include <memory>
#include <ctime>

#include "raylib.h"
#include "game.hpp"
#include "projects/paddle/paddleGame.hpp"

class Menu {
private:
	Game* game;
public:
	~Menu();
	Menu();

	void Init();
	void Update(float dt);
	void Draw();
};