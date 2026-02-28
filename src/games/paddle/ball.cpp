#include "ball.hpp"

using namespace PaddleGameConst;

Ball::Ball(Vector2 position) {
	int MIN = 250, MAX = 300;

	pos = position;

	speed.x = (float) GetRandomValue(MIN, MAX);
	speed.y = (float) GetRandomValue(MIN, MAX);

	direction.x = (float) (GetRandomValue(0, 1) * 2) - 1;
	direction.y = (float) (GetRandomValue(0, 1) * 2) - 1;

}

void Ball::Draw() {
	DrawCircle( (int) pos.x, (int) pos.y, RADIUS, BLUE);
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
	SetRandomSeed((unsigned int) time(nullptr));
	direction.x = (float) (GetRandomValue(0, 1) * 2) - 1;
	direction.y = (float) (GetRandomValue(0, 1) * 2) - 1;
}

int Ball::GetRadius() {
	return RADIUS;
}