#include "kitchenPlayer.hpp"

KitchenPlayer::~KitchenPlayer() {

}

KitchenPlayer::KitchenPlayer() {
	position = { 0.0f, 0.0f, 0.0f };
	speed = 5;
}

void KitchenPlayer::Draw() {
	float width = 5, height = 5, length = 7;

	DrawCube(position, width, height, length, RED);

}

void KitchenPlayer::Update(float dt) {
	UpdatePosition(dt);
}

void KitchenPlayer::CheckInput() {

}

Vector3 KitchenPlayer::GetCameraPos() {
	return {position.x, position.y + 2, position.z + 6};
}
