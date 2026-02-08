#pragma once

#include "raylib.h"

class Game {
private:
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;

protected:
	void SetWindowSize(int width, int height);

public:
	virtual ~Game() = 0;

	Game();
	int GetWindowWidth() const;
	int GetWindowHeight() const;
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void CheckInput() = 0;
	virtual bool ShouldClose() = 0;
		
};