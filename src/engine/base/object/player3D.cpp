#include "player3D.hpp"

void Player3D::UpdatePosition(float dt) {

	if (IsKeyDown(KEY_W))
		position.x += speed * dt;
	if (IsKeyDown(KEY_S))
		position.x -= speed * dt;
	if (IsKeyDown(KEY_A))
		position.z += speed * dt;
	if (IsKeyDown(KEY_D))
		position.z -= speed * dt;

}

void Player3D::Update(float dt) {

	UpdatePosition(dt);

}