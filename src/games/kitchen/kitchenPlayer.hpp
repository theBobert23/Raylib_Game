#pragma once

#include "raylib.h"
#include "../../engine/base/object/player3D.hpp"

class KitchenPlayer : public Player3D {
private:

public:
	~KitchenPlayer();
	KitchenPlayer();

	void Draw() override;
	void CheckInput() override;
	void Update(float dt) override;

	Vector3 GetCameraPos();

};