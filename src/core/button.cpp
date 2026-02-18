#include "button.hpp"

Button::~Button() {

}

Button::Button(Rectangle rect, GameID id, GameType type) {
	RECT = rect;
	ID = id;
	TYPE = type;
}

bool Button::isClicked(int x, int y) {

	if ((x > RECT.x && x < RECT.x + RECT.width) &&
		(y > RECT.y && y < RECT.y + RECT.height))

		return true;

	return false;
}

GameInfo Button::GetGame() {
	return { ID, TYPE };
}

void Button::Draw() {

	switch (TYPE) {
	case GameType::MultiPlayer :
		DrawRectangle(RECT.x, RECT.y, RECT.width, RECT.height, RED);
		break;
	case GameType::SinglePlayer :
		DrawRectangle(RECT.x, RECT.y, RECT.width, RECT.height, BLUE);
		break;

	}

}