#pragma once

#include "raylib.h"

namespace {
	constexpr int RADIUS = 5;
}

class Ball {
private:
	Vector2 speed;
	Vector2 direction;
	Vector2 pos;
	
	

public:
	Ball(Vector2 position);
	void Draw();
	void Update();
	Vector2 GetPosition() const;
};