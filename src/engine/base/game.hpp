#pragma once

#include "raylib.h"
#include "../../games/shared/utils.hpp"

class Game {
private:

protected:

public:
	virtual ~Game() = default;
	Game() = default;

	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void CheckInput() = 0;
	virtual bool ShouldClose() = 0;
		
};