#include "menuButton.hpp"


MenuButton::~MenuButton() {

}

MenuButton::MenuButton(Rectangle rect, GameID id, GameType type) {
	bounds = rect;
	ID = id;
	TYPE = type;
}

GameInfo MenuButton::GetGame() {
	return { ID, TYPE };
}

void MenuButton::Draw() {

	switch (TYPE) {
	case GameType::MultiPlayer:
		DrawRectangle(bounds.x, bounds.y, bounds.width, bounds.height, RED);
		break;
	case GameType::SinglePlayer:
		DrawRectangle(bounds.x, bounds.y, bounds.width, bounds.height, BLUE);
		break;

	}

}