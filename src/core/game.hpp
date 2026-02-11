#pragma once

#include "raylib.h"
#include "../utils.hpp"

class Game {
private:
	Size WINDOW;

protected:
	void SetWindowSize(int width, int height);
	Size GetWindowSize() const;

public:
	virtual ~Game() = 0;

	Game();
	int GetWindowWidth() const;
	int GetWindowHeight() const;
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void CheckInput() = 0;
	virtual bool ShouldClose() = 0;
		
};