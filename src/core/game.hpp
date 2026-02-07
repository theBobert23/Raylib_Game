#pragma once

#include "raylib.h"

class Game {
public:
	virtual ~Game() = 0;

	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void CheckInput() = 0;
	virtual bool ShouldClose() = 0;
		
};