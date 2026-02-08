#include "paddleGame.hpp"


paddleGame :: ~paddleGame() {

}

paddleGame :: paddleGame() {
	PADDLE_WINDOW_WIDTH = 900;
	PADDLE_WINDOW_HEIGHT = 450;

	SetWindowSize(PADDLE_WINDOW_WIDTH, PADDLE_WINDOW_HEIGHT);
}

//void paddleGame :: GetWindowSize(int &WIDTH, int &HEIGHT) {
//	WIDTH = PADDLE_WINDOW_WIDTH;
//	HEIGHT = PADDLE_WINDOW_HEIGHT;
//}

void paddleGame :: Init() {
	
}

void paddleGame :: Draw() {

}

void paddleGame :: Update() {

}

void paddleGame :: CheckInput() {

}

bool paddleGame :: ShouldClose() {
	return false;
}
