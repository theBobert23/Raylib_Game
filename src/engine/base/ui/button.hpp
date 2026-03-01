#pragma once

#include "raylib.h"

class Button {
protected:
	Rectangle bounds;
	Color bgColor;
	Color textColor;
	Color bgColorHover;
	Color textColorHover;

public:
	virtual ~Button() = default;

	virtual void Draw() = 0;

	bool IsClicked();

};