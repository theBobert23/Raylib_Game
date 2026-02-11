#include "paddle.hpp"


Paddle::Paddle(Size window, ObjectSide side, Type type) {
	
	WINDOW = window;
	SIDE = side;
	TYPE = type;

	size.width = PADDLE_WIDTH;
	size.height = PADDLE_HEIGHT;

	float TIME = 2.5f;
	speed = (WINDOW.height - size.height) / TIME;


	switch(side){
		case ObjectSide::Left : 
			pos.x = PADDING;
			break;
		case ObjectSide::Right :
			pos.x = WINDOW.width - size.width - PADDING;
			break;

	}
	pos.y = (WINDOW.height - size.height) / 2.0f;

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
					
			}
			break;

	}

	if (pos.y < 0)
		pos.y = 0;
	if (pos.y + size.height > WINDOW.height)
		pos.y = WINDOW.height - size.height;

}

void Paddle :: CheckInput() {

	

}

