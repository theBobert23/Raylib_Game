#pragma once


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
	SpaceInvasion
};

enum GameType { SinglePlayer, MultiPlayer };

struct GameInfo {
	GameID id;
	GameType type;
};

struct Size {
	int width;
	int height;
};