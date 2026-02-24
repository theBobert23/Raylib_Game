#pragma once

#include <memory>
#include "iostream"


enum ObjectSide {
	Left,
	Right
};

enum Type {
	Player,
	Computer
};

enum GameID {
	Pong,
	Kitchen,
	SpaceInvasion
};

enum GameType { SinglePlayer, MultiPlayer };

struct GameInfo {
	GameID id;
	GameType type;
};

struct MenuButton {
	int x1, y1;
	int x2, y2;
	GameID id;
};

struct RectCoords {
	struct {
		int x, y;
	}pos1, pos2;
};

struct GameIcon {
	int x, y;
	int width,height;
	GameID id;
};

struct Size {
	int width;
	int height;
};