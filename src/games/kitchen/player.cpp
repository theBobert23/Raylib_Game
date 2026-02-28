#include "player.hpp"


Player::~Player() {

}

Player::Player() {
	position = { 100,100 };
}

void Player::CheckInput() {

}

void Player::Update(float dt) {

	CheckInput();
}

void Player::Draw() {

	int width = 50;
	int height = 100;

	DrawRectangle((int)position.x, (int)position.y, width, height, BLACK);

}


