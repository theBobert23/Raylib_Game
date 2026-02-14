#include "game.hpp"

Game::~Game() {

}

void Game::SetWindowSize(int width, int height) {

	//check if values are good.

	WINDOW.width = width;

	WINDOW.height = height;
}

Size Game::GetWindowSize() const{
	return WINDOW;
}


Game::Game() {
	WINDOW.width = 900;
	WINDOW.height = 450;

}

int Game::GetWindowWidth() const {
	return WINDOW.width;
}


int  Game::GetWindowHeight() const {
	return WINDOW.height;
}

