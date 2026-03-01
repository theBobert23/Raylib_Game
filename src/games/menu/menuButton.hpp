#pragma once

#include "../../engine/base/ui/button.hpp"

#include "../shared/utils.hpp"
#include "../shared/constants.hpp"

class MenuButton : public Button {
private:
	GameID ID;
	GameType TYPE;
public:
	
	~MenuButton();
	MenuButton(Rectangle rect, GameID id, GameType type);

	void Draw() override;
	
	GameInfo GetGame();
};