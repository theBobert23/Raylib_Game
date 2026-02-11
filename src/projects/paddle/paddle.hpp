#pragma once

#include "raylib.h"
#include "../../utils.hpp"


namespace {
	constexpr int PADDING = 20;
	constexpr int PADDLE_WIDTH = 10;
	constexpr int PADDLE_HEIGHT = 80;
}



class Paddle {
private:
	ObjectSide SIDE;
	Size WINDOW;
	Type TYPE;

	Vector2 pos;
	Size size;
	int speed;

public:

	Paddle(Size WINDOW, ObjectSide side, Type type);
	~Paddle();

	void Init();
	void Draw();
	void Update(float dt);
	void CheckInput();

};