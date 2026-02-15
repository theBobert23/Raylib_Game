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

	void Update(float dt);
	void Draw();
	
public:
	~Menu();
	Menu();

	void Init();
	void Run();
};