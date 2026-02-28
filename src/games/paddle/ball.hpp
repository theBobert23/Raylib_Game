#pragma once

#include "raylib.h"
#include "../shared/constants.hpp"
#include "ctime"

class Ball {
private:
	Vector2 speed;
	Vector2 direction;
	Vector2 pos;
	
	

public:
	Ball(Vector2 position);
	void Draw();
	void Update(float dt);
	Vector2 GetPosition() const;
	void SetPosition(Vector2 newPos);
	void SetSpeed(Vector2 newSpeed);
	void Invert_X_Direction();
	void Invert_Y_Direction();
	void RandomDirection();
	int GetRadius();
};