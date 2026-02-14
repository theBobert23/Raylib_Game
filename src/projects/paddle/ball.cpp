#include "ball.hpp"
#include <iostream>

Ball::Ball(Vector2 position) {
	int MIN = 250, MAX = 300;

	pos = position;

	speed.x = GetRandomValue(MIN, MAX);
	speed.y = GetRandomValue(MIN, MAX);

	direction.x = (GetRandomValue(0, 1) * 2) - 1;
	direction.y = (GetRandomValue(0, 1) * 2) - 1;

}

void Ball::Draw() {
	DrawCircle(pos.x, pos.y, RADIUS, BLUE);
}

void Ball::Update(float dt) {

	pos.x += (speed.x * direction.x) * dt;
	pos.y += (speed.y * direction.y) * dt;

}

Vector2 Ball::GetPosition() const{
	return pos;
}

void Ball::SetPosition(Vector2 newPos) {
	pos = newPos;
}

void Ball::SetSpeed(Vector2 newSpeed) {

}

void Ball::Invert_X_Direction() {
	direction.x *= -1;
}

void Ball::Invert_Y_Direction() {
	direction.y *= -1;
}

void Ball::RandomDirection() {
	SetRandomSeed(time(nullptr));
	direction.x = (GetRandomValue(0, 1) * 2) - 1;
	direction.y = (GetRandomValue(0, 1) * 2) - 1;
}

int Ball::GetRadius() {
	return RADIUS;
}