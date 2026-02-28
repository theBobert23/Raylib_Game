#pragma once

#include "raylib.h"
#include "../shared/utils.hpp"
#include "../shared/constants.hpp"


class Paddle {
private:
	ObjectSide SIDE;
	Type TYPE;

	Vector2 pos;
	Size size;
	int speed;

public:

	Paddle(ObjectSide side, Type type);
	~Paddle();

	void Init();
	void Draw();
	void Update(float dt);
	void CheckInput();
	Vector2 GetPos();
	Vector2 GetSize();
};