#include "button.hpp"

bool Button::IsClicked() {
	return CheckCollisionPointRec(GetMousePosition(), bounds);
}