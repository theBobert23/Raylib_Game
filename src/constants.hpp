#pragma once

#include "raylib.h"

namespace GeneralConst {
	inline constexpr int WINDOW_WIDTH = 1280;
	inline constexpr int WINDOW_HEIGHT = 720;
}

namespace MenuConst {
	inline constexpr const char* TITLE = "MENU";
	inline constexpr int ICON_SIZE = 150;
	inline constexpr int GAP = 4;
	inline constexpr int COL_GAP = ICON_SIZE * 2;
	//inline constexpr int BUTTON_SIZE = 43; ICON_SIZE-GAP / 2
}

namespace PaddleGameConst {
	inline constexpr Vector2 BALL_START_POS = { GeneralConst::WINDOW_WIDTH / 2.0f, GeneralConst::WINDOW_HEIGHT / 2.0f };
	inline constexpr int BALL_RADIUS = 10;

	inline constexpr int PADDING = 20;
	inline constexpr int PADDLE_WIDTH = 10;
	inline constexpr int PADDLE_HEIGHT = 80;
	//Time for a paddle to go from top to bottom 
	inline constexpr float TIME = 2.0f;
	inline constexpr int RADIUS = 10;
}


