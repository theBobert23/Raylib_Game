#include "game.hpp"



void Game::SetWindowSize(int width, int height) {

	//check if values are good.

	WINDOW_WIDTH = width;

	WINDOW_HEIGHT = height;
}


Game::Game() {
	WINDOW_WIDTH = 900;
	WINDOW_HEIGHT = 450;
}

int Game::GetWindowWidth() const {
	return WINDOW_WIDTH;
}


int  Game::GetWindowHeight() const {
	return WINDOW_HEIGHT;
}
