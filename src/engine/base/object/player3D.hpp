#pragma once

#include "raylib.h"

class Player3D {
protected:
	Vector3 position;
	int speed;

public:
	~Player3D() = default;

	virtual void Draw() = 0;
	virtual void CheckInput() = 0;
	virtual void UpdatePosition(float dt);
	virtual void Update(float dt);
};
