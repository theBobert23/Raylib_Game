#include "paddle.hpp"

using namespace PaddleGameConst;
using namespace GeneralConst;

Paddle::Paddle(ObjectSide side, Type type) {
	
	SIDE = side;
	TYPE = type;

	size.width = PADDLE_WIDTH;
	size.height = PADDLE_HEIGHT;

	speed = (int) ((WINDOW_HEIGHT - size.height) / TIME);


	switch(side){
		case ObjectSide::Left : 
			pos.x = PADDING;
			break;
		case ObjectSide::Right :
			pos.x = (float) (WINDOW_WIDTH - size.width - PADDING);
			break;

	}
	pos.y = (WINDOW_HEIGHT - size.height) / 2.0f;

}

Paddle :: ~Paddle() {

}

void Paddle :: Init() {

}

void Paddle :: Draw() {
	Color color = BLACK;
	switch (SIDE) {
		case ObjectSide::Left : 
			color = BLACK;
			break;
		case ObjectSide::Right :
			color = RED;
			break;
	}
		DrawRectangle((int)pos.x, (int)pos.y, size.width, size.height, color);
}

void Paddle :: Update(float dt) {
	
	switch (SIDE) {
		case ObjectSide::Left :
			if (IsKeyDown(KEY_W)) 
				pos.y -= speed * dt;
				
			
			if (IsKeyDown(KEY_S)) 
				pos.y += speed * dt;
				
			
			break;

		case ObjectSide::Right: // Enemy / AI
			switch (TYPE) {
				case Type::Player :
					if (IsKeyDown(KEY_I)) 
						pos.y -= speed * dt;
					if (IsKeyDown(KEY_K))
						pos.y += speed * dt;
					break;
				case Type::Computer :

					break;
					
			}
			break;

	}

	if (pos.y < 0)
		pos.y = 0;
	if (pos.y + size.height > WINDOW_HEIGHT)
		pos.y = (float) (WINDOW_HEIGHT - size.height);

}

void Paddle :: CheckInput() {

}
      
Vector2 Paddle :: GetPos() {
	return pos;
}

Vector2 Paddle :: GetSize() {
	return { PADDLE_WIDTH, PADDLE_HEIGHT };
}

