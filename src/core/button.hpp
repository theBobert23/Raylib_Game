#pragma once

#include "raylib.h"
#include "../utils.hpp"
#include "../constants.hpp"

class Button {
private:
	Rectangle RECT;
	GameID ID;
	GameType TYPE;

public:
	
	Button(Rectangle rect, GameID id, GameType type);
	~Button();
	bool isClicked(int x, int y) const;
	GameInfo GetGame();
	void Draw();
};