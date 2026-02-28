#pragma once

#include "raylib.h"

class Player {
private:
	Vector2 position;

	void CheckInput();

public:
	~Player();
	Player();

	void Draw();
	void Update(float dt);

};