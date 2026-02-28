#pragma once

#include <memory>
#include "iostream"


enum ObjectSide {
	Left,
	Right
};

enum Type {
	Human,
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