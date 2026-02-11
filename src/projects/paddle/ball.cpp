#include "ball.hpp"


Ball::Ball(Vector2 position) {
	int MIN = 40, MAX = 60;

	pos = position;

	speed.x = GetRandomValue(MIN, MAX);
	speed.y = GetRandomValue(MIN, MAX);

	direction.x = (GetRandomValue(0, 1) * 2) - 1;
	direction.y = (GetRandomValue(0, 1) * 2) - 1;

}

void Ball::Draw() {
	DrawCircle(pos.x, pos.y, RADIUS, BLUE);
}

void Ball::Update() {

}

Vector2 Ball::GetPosition() const{
	return pos;
}

void Ball::SetDirection(Vector2 newDirection) {
	direction.x *= newDirection.x;
	direction.y *= newDirection.y;
}

void Ball::SetSpeed(Vector2 newSpeed) {

}

